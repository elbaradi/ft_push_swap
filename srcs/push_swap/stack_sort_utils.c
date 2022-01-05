/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_sort_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 14:49:39 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/08/05 15:51:22 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stacks.h"
#include "prototypes.h"
#include "instructions.h"

void	rotate_back(t_stacks *stacks, int rot_a, int rot_b)
{
	while (rot_a > rot_b)
	{
		ps_instruct(stacks, shift_down_a + 1);
		rot_a--;
	}
	while (rot_b > rot_a)
	{
		ps_instruct(stacks, shift_down_b + 1);
		rot_b--;
	}
	while (rot_a)
	{
		ps_instruct(stacks, shift_down_both + 1);
		rot_a--;
	}
}

static void	update_sort_info(t_link *link, int tier, int *chunk_size)
{
	link->sort_id += tier;
	link->chunk = chunk_size[tier - 1];
	if (tier == 2)
		link->chunk_index -= chunk_size[0];
	else if (tier == 3)
		link->chunk_index -= chunk_size[0] + chunk_size[1];
	return ;
}

void	sort_first_cycle(t_stacks *stacks, int *chunk_size)
{
	while (stacks->a->head->sort_id == 0)
	{
		if (stacks->a->head->chunk_index < chunk_size[0])
		{
			update_sort_info(stacks->a->head, 1, chunk_size);
			ps_instruct(stacks, push_b + 1);
			if (!(stacks->a->head->sort_id == 0 && stacks->a->head->chunk_index
					>= chunk_size[0] + chunk_size[1]) && (stacks->b->head->next
					&& stacks->b->head->next->sort_id != 1))
				ps_instruct(stacks, shift_up_b + 1);
		}
		else if (stacks->a->head->chunk_index < chunk_size[0] + chunk_size[1])
		{
			update_sort_info(stacks->a->head, 2, chunk_size);
			ps_instruct(stacks, push_b + 1);
		}
		else
		{
			update_sort_info(stacks->a->head, 3, chunk_size);
			if (stacks->b->head && stacks->b->head->sort_id == 1)
				ps_instruct(stacks, shift_up_both + 1);
			else
				ps_instruct(stacks, shift_up_a + 1);
		}
	}
}

void	sort_top_chunk_in_a(t_stacks *stacks, unsigned long long id,
int *chunk_size)
{
	while (stacks->a->head->sort_id == id)
	{
		stacks->a->head->sort_id *= 10;
		if (stacks->a->head->chunk_index < chunk_size[0])
		{
			update_sort_info(stacks->a->head, 1, chunk_size);
			ps_instruct(stacks, push_b + 1);
		}
		else if (stacks->a->head->chunk_index < chunk_size[0] + chunk_size[1])
		{
			update_sort_info(stacks->a->head, 2, chunk_size);
			ps_instruct(stacks, push_b + 1);
			if (!(stacks->a->head->sort_id == id && stacks->a->head->chunk_index
					>= chunk_size[0] + chunk_size[1]))
				ps_instruct(stacks, shift_up_b + 1);
		}
		else
		{
			update_sort_info(stacks->a->head, 3, chunk_size);
			if (stacks->b->head && (stacks->b->head->sort_id - 2) / 10 == id)
				ps_instruct(stacks, shift_up_both + 1);
			else
				ps_instruct(stacks, shift_up_a + 1);
		}
	}
}

void	sort_top_chunk_in_b(t_stacks *stacks, unsigned long long id,
int *chunk_size)
{
	while (stacks->b->head->sort_id == id)
	{
		stacks->b->head->sort_id *= 10;
		if (stacks->b->head->chunk_index < chunk_size[0])
		{
			update_sort_info(stacks->b->head, 1, chunk_size);
			if (stacks->a->head->sort_id  == id * 10 + 2)
				ps_instruct(stacks, shift_up_both + 1);
			else
				ps_instruct(stacks, shift_up_b + 1);
		}
		else if (stacks->b->head->chunk_index < chunk_size[0] + chunk_size[1])
		{
			update_sort_info(stacks->b->head, 2, chunk_size);
			ps_instruct(stacks, push_a + 1);
			if (!(stacks->b->head && stacks->b->head->sort_id == id
					&& stacks->b->head->chunk_index < chunk_size[0]))
				ps_instruct(stacks, shift_up_a + 1);
		}
		else
		{
			update_sort_info(stacks->b->head, 3, chunk_size);
			ps_instruct(stacks, push_a + 1);
		}
	}
}
