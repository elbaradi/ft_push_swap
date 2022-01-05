/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_chunk_in_a.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/08 15:12:27 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/08/06 13:32:29 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stacks.h"
#include "prototypes.h"
#include "instructions.h"

/* permutations_b[4] = {
	 1 . . 
	 . 1 .  
	 . 3 .  
	 . . 3  
}	*/

static void	optimal_swap(t_stacks *stacks, int *both)
{
	int	permutations_b[4];
	int	index[3];

	ft_bzero(both, 5 * sizeof(int));
	ft_bzero(permutations_b, 4 * sizeof(int));
	if (stacks->b->head && stacks->b->head->next)
	{
		index[0] = stacks->b->head->index;
		index[1] = stacks->b->head->next->index;
		if (stacks->b->head->next->next)
		{
			index[2] = stacks->b->head->next->next->index;
			permutations_b[0] = (index[0] < index[1] && index[0] < index[2]);
			permutations_b[1] = (index[1] < index[0] && index[1] < index[2]);
			permutations_b[2] = (index[1] > index[0] && index[1] > index[2]);
			permutations_b[3] = (index[2] > index[0] && index[2] > index[1]);
		}
		else
			permutations_b[2] = (index[1] > index[0]);
		both[0] = 2 * (permutations_b[0] || permutations_b[2]);
		both[1] = 2 * (permutations_b[1] || permutations_b[3]);
		both[2] = 2 * (both[1] || permutations_b[0]);
		both[3] = 2 * (both[0] || both[1]);
		both[4] = 2 * permutations_b[3];
	}
}

void	solve_chunk_size_two_in_a(t_stacks *stacks)
{
	if (stacks->b->head && stacks->b->head->next && stacks->a->head->next
		&& stacks->a->head->sort_id == stacks->a->head->next->sort_id
		&& stacks->a->head->chunk_index > stacks->a->head->next->chunk_index
		&& stacks->b->head->sort_id == stacks->b->head->next->sort_id
		&& stacks->b->head->chunk_index < stacks->b->head->next->chunk_index)
		ps_instruct(stacks, swap_both + 1);
	else if (stacks->a->head->next
		&& stacks->a->head->sort_id == stacks->a->head->next->sort_id
		&& stacks->a->head->chunk_index > stacks->a->head->next->chunk_index)
		ps_instruct(stacks, swap_a + 1);
	else
		return ;
}

void	solve_chunk_size_three_in_a(t_stacks *stacks)
{
	int					permutation;
	unsigned long long	sequence;
	int					b[5];

	permutation = 100 * (stacks->a->head->chunk_index + 1) + 10
		* (stacks->a->head->next->chunk_index + 1)
		+ stacks->a->head->next->next->chunk_index + 1;
	optimal_swap(stacks, b);
	if (permutation == 321 || (permutation - 321) % 111 == 0)
		sequence = encoder(swap_a + b[0], encoder(shift_up_a + b[2], swap_a
					+ b[2], shift_down_a + b[2], swap_a + b[4]), empty, empty);
	else if (permutation == 312 || (permutation - 312) % 111 == 0)
		sequence = encoder(swap_a + b[0], shift_up_a + b[2],
				swap_a + b[2], shift_down_a + b[2]);
	else if (permutation == 231 || (permutation - 231) % 111 == 0)
		sequence = encoder(shift_up_a + b[1], swap_a + b[3],
				shift_down_a + b[1], swap_a + b[4]);
	else if (permutation == 213 || (permutation - 213) % 111 == 0)
		sequence = encoder(swap_a + b[0], empty, empty, empty);
	else if (permutation == 132 || (permutation - 132) % 111 == 0)
		sequence = encoder(shift_up_a + b[1], swap_a + b[3],
				shift_down_a + b[1], empty);
	else
		return ;
	ps_instruct(stacks, sequence);
}

static void	solve_for_three(t_stacks *stacks)
{
	int					permutation;
	unsigned long long	sequence;

	permutation = 100 * (stacks->a->head->chunk_index + 1) + 10
		* (stacks->a->head->next->chunk_index + 1)
		+ stacks->a->head->next->next->chunk_index + 1;
	if (permutation == 321)
		sequence = encoder(shift_up_a, swap_a, empty, empty);
	else if (permutation == 312)
		sequence = encoder(shift_up_a, empty, empty, empty);
	else if (permutation == 231)
		sequence = encoder(shift_down_a, empty, empty, empty);
	else if (permutation == 213)
		sequence = encoder(swap_a, empty, empty, empty);
	else if (permutation == 132)
		sequence = encoder(swap_a, shift_up_a, empty, empty);
	else
		return ;
	ps_instruct(stacks, sequence);
}

void	solve_top_chunk_in_a(t_stacks *stacks)
{
	int	size;

	size = stacks->a->head->chunk;
	if (size == 1)
		return ;
	else if (size == 2)
		solve_chunk_size_two_in_a(stacks);
	else if (size == 3 && stacks->a->size == 3)
		solve_for_three(stacks);
	else if (size == 3)
		solve_chunk_size_three_in_a(stacks);
	return ;
}
