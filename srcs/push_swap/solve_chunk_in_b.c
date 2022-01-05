/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_chunk_in_b.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/14 01:48:37 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/08/05 16:12:21 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stacks.h"
#include "prototypes.h"
#include "instructions.h"

void	solve_chunk_size_two_in_b(t_stacks *stacks)
{
	unsigned long long	sequence;
	int					single_swap;
	int					double_swap;

	single_swap = stacks->b->head->chunk_index
		< stacks->b->head->next->chunk_index;
	double_swap = single_swap && stacks->b->head->next->next
		&& stacks->b->head->next->next->next
		&& stacks->b->head->next->next->index
		< stacks->b->head->next->next->next->index;
	if (double_swap)
		sequence = encoder(push_a, push_a, swap_both, empty);
	else if (single_swap)
		sequence = encoder(push_a, push_a, swap_a, empty);
	else
		sequence = encoder(push_a, push_a, empty, empty);
	ps_instruct(stacks, sequence);
	return ;
}

void	solve_chunk_size_three_in_b(t_stacks *stacks)
{
	int					permutation;
	unsigned long long	sequence;

	permutation = 100 * (stacks->b->head->chunk_index + 1) + 10
		* (stacks->b->head->next->chunk_index + 1)
		+ stacks->b->head->next->next->chunk_index + 1;
	if (permutation == 123 || (permutation - 123) % 111 == 0)
		sequence = encoder(push_a, swap_b,
				encoder(push_a, swap_a, push_a, swap_a), empty);
	else if (permutation == 213 || (permutation - 213) % 111 == 0)
		sequence = encoder(push_a,
				encoder(swap_b, push_a, swap_a, push_a), empty, empty);
	else if (permutation == 132 || (permutation - 132) % 111 == 0)
		sequence = encoder(swap_b,
				encoder(push_a, push_a, push_a, swap_a), empty, empty);
	else if (permutation == 312 || (permutation - 312) % 111 == 0)
		sequence = encoder(push_a, push_a, push_a, swap_a);
	else if (permutation == 231 || (permutation - 231) % 111 == 0)
		sequence = encoder(swap_b, push_a, push_a, push_a);
	else
		sequence = encoder(push_a, push_a, push_a, empty);
	ps_instruct(stacks, sequence);
	return ;
}

void	solve_top_chunk_in_b(t_stacks *stacks)
{
	int	size;

	size = stacks->b->head->chunk;
	if (size == 1)
		ps_instruct(stacks, push_a + 1);
	else if (size == 2)
		solve_chunk_size_two_in_b(stacks);
	else if (size == 3)
		solve_chunk_size_three_in_b(stacks);
	return ;
}
