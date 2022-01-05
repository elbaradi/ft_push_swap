/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   optimizations.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/02 15:00:19 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/08/02 23:45:58 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stacks.h"
#include "prototypes.h"
#include "instructions.h"

t_link	*get_link(t_stack *stack, int offset)
{
	t_link	*link;

	link = stack->head;
	while (link && offset)
	{
		link = link->next;
		offset--;
	}
	return (link);
}

static int	solve_chunk_size_four_plus_in_a(t_stacks *stacks, int *index,
int size)
{
	while (*index >= size / 2)
	{
		if (!(get_link(stacks->a, *index)->chunk_index >= size / 2))
			return (0);
		(*index)--;
	}
	if (size == 6)
	{
		ps_instruct(stacks, encoder(push_b, push_b, push_b, empty));
		solve_chunk_size_three_in_a(stacks);
		solve_chunk_size_three_in_b(stacks);
	}
	else if (size == 5)
	{
		ps_instruct(stacks, encoder(push_b, push_b, empty, empty));
		solve_chunk_size_three_in_a(stacks);
		solve_chunk_size_two_in_b(stacks);
	}
	else if (size == 4)
	{
		ps_instruct(stacks, encoder(push_b, push_b, empty, empty));
		solve_chunk_size_two_in_a(stacks);
		solve_chunk_size_two_in_b(stacks);
	}
	return (1);
}

int	solve_if_solvable_chunk_in_a(t_stacks *stacks)
{
	int	index;
	int	size;

	if (stacks->a->head->chunk <= CHUNK_SIZE + 3)
	{
		size = stacks->a->head->chunk;
		index = stacks->a->head->chunk - 1;
		while (index >= 3)
		{
			if (!(get_link(stacks->a, index)->chunk_index == index))
				break ;
			index--;
		}
		if (index == 2)
			solve_chunk_size_three_in_a(stacks);
		else
			return (solve_chunk_size_four_plus_in_a(stacks, &index, size));
		return (1);
	}
	return (0);
}

int	solve_if_solvable_chunk_in_b(t_stacks *stacks)
{
	int	index;
	int	size;

	if (stacks->b->head->chunk <= CHUNK_SIZE + 3)
	{
		size = stacks->b->head->chunk;
		index = (size / 2) - 1;
		while (index >= 0)
		{
			if (!(get_link(stacks->b, index)->chunk_index > size / 2))
				return (0);
			index--;
		}
		if (size == 6)
			solve_chunk_size_three_in_b(stacks);
		else
			solve_chunk_size_two_in_b(stacks);
		if (size == 4)
			solve_chunk_size_two_in_b(stacks);
		else
			solve_chunk_size_three_in_b(stacks);
		return (1);
	}
	return (0);
}
