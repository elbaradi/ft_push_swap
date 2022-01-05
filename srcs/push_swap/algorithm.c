/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/14 01:59:58 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/08/02 17:20:32 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stacks.h"
#include "prototypes.h"
#include "instructions.h"
#include <stdio.h>

static void	calc_chunk_size(int size, int *chunk_size, int method)
{
	if (method == 0)
	{
		chunk_size[0] = size / 3;
		chunk_size[1] = size / 3;
		chunk_size[2] = size / 3 + (size % 3);
	}
	else
	{
		chunk_size[0] = size / 3;
		chunk_size[1] = size / 3 + ((size % 3) / 2);
		chunk_size[2] = size / 3 + (((size % 3) + 1) / 2);
	}
}

/* Initializes sort ids, instruction count and chunk sizes.
*/

static void	init_sort_info(t_stacks *stacks)
{
	t_link	*first;

	first = stacks->a->head;
	stacks->instruction_count = 0;
	stacks->a->head->sort_id = 0;
	stacks->a->head->chunk_index = stacks->a->head->index;
	stacks->a->head->chunk = stacks->a->size;
	ps_shift_up(stacks, shift_up_a);
	while (stacks->a->head != first)
	{
		stacks->a->head->sort_id = 0;
		stacks->a->head->chunk = stacks->a->size;
		stacks->a->head->chunk_index = stacks->a->head->index;
		ps_shift_up(stacks, shift_up_a);
	}
}

/* The first cycle is for efficiency sake slightly different; it doesn't rotate
back and can place tier two directly on top of tier 1 in stack B. This
function also initializes sort ids and other sorting info.
*/

void	first_cycle(t_stacks *stacks)
{
	int	chunk_size[3];

	init_sort_info(stacks);
	if (stacks->a->size <= CHUNK_SIZE)
		solve_top_chunk_in_a(stacks);
	else
	{
		if (solve_if_solvable_chunk_in_a(stacks) == 1)
			return ;
		calc_chunk_size(stacks->a->head->chunk, chunk_size, stacks->method);
		sort_first_cycle(stacks, chunk_size);
		divide_stack_a_in_three(stacks, 3);
		divide_stack_b_in_three(stacks, 2);
		divide_stack_b_in_three(stacks, 1);
	}
}

/* The Algorithm works as follows:
It cycles through all unsorted integers of A. It divides the integers in three
tiers. The highest numbers stay in A. The midrange numbers go to the top of B.
The lowest numbers go to the bottom of B. 

Before: 						|	After:
								|
Stack A			Stack B			|	Stack A			Stack B
[1, 2, 3]		-				|	[3]				[2]
								|					[1]

It then continues to cycle through A, again splitting A into three tiers in the
same way as before, keeping the highest numbers in A.

Before: 						|	After:
								|
Stack A			Stack B			|	Stack A			Stack B
[3]				[2]				|	[3.3]			[3.2]
				[1]				|					[3.1]
								|					[2]
								|					[1]

It keeps cycling through and splitting up A until the
a smallest chunk size of no greater than three has been reached [3.X.3.3].
Instead of splitting this chunk up further, it sorts this chunk directly.
It then pushes the top chunk of B [3.X.3.2] to A and sorts this,
followed by the second-top chunk of B [3.X.3.1]. Depending on the chunk size,
Stack A now holds the largest 3 to 9 numbers in order.

Before: 						|	After:
								|
Stack A			Stack B			|	Stack A			Stack B
[3.X.3.3]		[3.X.3.2]		|	[3.X.3.1]		[3.X.2]
				[3.X.3.1]		|	[3.X.3.2]		[3.X.1]
				[3.X.2]			|	[3.x.3.3]		[...]
				[3.X.1]			|					[2]
				[...]			|					[1]
				[2]				|
				[1]				|

(The X and ... should be interpreted as some number of intermediary splits)

The algorithms splits chunks in stack B as follows; the highest numbers go to
the top of A. The midrange numbers go to the bottom of A. The lowest numbers go
to the bottom of B. After the highest numbers of the split at the top of A have
been further split and completely sorted, the midrange and lowest numbers at the
bottom of A and B are brought back up to the top of their stacks,
to be further split and sorted. This process continues all the way until in the
end chunk [1.X.1.1] has been pushed and sorted at the top of A.

Before: 						|	After:
								|
Stack A			Stack B			|	Stack A			Stack B
[1.X.1.3]		[1.X.1.2]		|	[1.X.1.1]		-
[1.X.2.1]		[1.X.1.1]		|	[1.X.1.2]
[1.X.2.2]						|	[1.x.1.3]
[1.X.2.3]						|	[1.X.2.1]	
[1.X.3.1]						|	[1.X.2.2]	
[1.X.3.2]						|	[1.X.2.3]
[1.X.3.3]						|	[1.X.3.1]
[...]							|	[1.X.3.2]
[3.X.3.1]						|	[1.X.3.3]
[3.X.3.2]						|	[...]
[3.X.3.3]						|	[3.X.3.1]
								|	[3.X.3.2]
								|	[3.X.3.3]
*/

void	divide_stack_a_in_three(t_stacks *stacks, unsigned long long id)
{
	int	chunk_size[3];

	if (stacks->a->head->chunk <= CHUNK_SIZE && stacks->a->head->sort_id == id)
		solve_top_chunk_in_a(stacks);
	else if (stacks->a->head->sort_id == id)
	{
		if (solve_if_solvable_chunk_in_a(stacks) == 1)
			return ;
		calc_chunk_size(stacks->a->head->chunk, chunk_size, stacks->method);
		sort_top_chunk_in_a(stacks, id, chunk_size);
		rotate_back(stacks, chunk_size[2], chunk_size[1]);
		divide_stack_a_in_three(stacks, 10 * id + 3);
		divide_stack_b_in_three(stacks, 10 * id + 2);
		divide_stack_b_in_three(stacks, 10 * id + 1);
	}
}

void	divide_stack_b_in_three(t_stacks *stacks, unsigned long long id)
{
	int	chunk_size[3];

	if (stacks->b->head == NULL)
		return ;
	if (stacks->b->head->chunk <= CHUNK_SIZE && stacks->b->head->sort_id == id)
		solve_top_chunk_in_b(stacks);
	else if (stacks->b->head->sort_id == id)
	{
		if (solve_if_solvable_chunk_in_b(stacks) == 1)
			return ;
		calc_chunk_size(stacks->b->head->chunk, chunk_size, stacks->method);
		sort_top_chunk_in_b(stacks, id, chunk_size);
		divide_stack_a_in_three(stacks, 10 * id + 3);
		rotate_back(stacks, chunk_size[1], chunk_size[0]);
		divide_stack_a_in_three(stacks, 10 * id + 2);
		divide_stack_b_in_three(stacks, 10 * id + 1);
	}
}
