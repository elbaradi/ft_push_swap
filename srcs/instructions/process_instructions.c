/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   process_instructions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/14 16:36:22 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/07/14 03:12:37 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "instructions.h"
#include "stacks.h"

void	process_instructions(t_instruction *instruction_list)
{
	static	void	(*const	dispatch[13])(t_stacks *stacks,
	t_operation operation) = {
		[swap_a] = &ps_swap,
		[swap_b] = &ps_swap,
		[swap_both] = &ps_both,
		[push_a] = &ps_push,
		[push_b] = &ps_push,
		[shift_up_a] = &ps_shift_up,
		[shift_up_b] = &ps_shift_up,
		[shift_up_both] = &ps_both,
		[shift_down_a] = &ps_shift_down,
		[shift_down_b] = &ps_shift_down,
		[shift_down_both] = &ps_both,
	};
	t_instruction			*link;
	t_stacks				*stacks;

	link = instruction_list;
	stacks = getstacks();
	while (link)
	{
		if (dispatch[link->operation])
			dispatch[link->operation](stacks, link->operation);
		link = link->next;
	}
}
