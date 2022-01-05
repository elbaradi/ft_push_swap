/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wrapper.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/09 09:53:36 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/08/02 13:18:36 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include "prototypes.h"
#include "instructions.h"
#include "stdlib.h"

unsigned long long	encoder(int first, int second, int third, int fourth)
{
	unsigned long long	sequence;

	sequence = 0;
	if (fourth != empty)
		sequence = (sequence + fourth + (fourth < 11)) * 11;
	if (third != empty)
		sequence = (sequence + third + (third < 11)) * 11;
	if (second != empty)
		sequence = (sequence + second + (second < 11)) * 11;
	sequence = (sequence + first + 1);
	return (sequence);
}

//Make static?
int	add_instruction(t_instruction **lst, int operation)
{
	t_instruction	*new;

	new = malloc(sizeof(t_instruction));
	if (new == NULL)
		ps_error();
	new->operation = operation;
	new->next = NULL;
	(*lst)->next = new;
	*lst = (*lst)->next;
	return (0);
}

void	ps_instruct(t_stacks *stacks, unsigned long long operation_sequence)
{
	int						operation;
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

	while (operation_sequence)
	{
		operation = (int)((operation_sequence - 1) % 11);
		dispatch[operation](stacks, operation);
		add_instruction(&stacks->instruction_list, operation);
		stacks->instruction_count += 1;
		operation_sequence = (operation_sequence - 1) / 11;
	}
}

static int	instruction_to_string(int operation, char **str)
{
	if (operation == empty)
		return (0);
	if (operation == swap_a || operation == swap_b || operation == swap_both)
		**str = 's';
	else if (operation == push_a || operation == push_b)
		**str = 'p';
	else if (operation >= shift_up_a && operation <= shift_down_both)
		**str = 'r';
	if (operation >= shift_down_a && operation <= shift_down_both)
	{
		*(*str + 1) = 'r';
		(*str) += 1;
	}
	if (operation == swap_a || operation == push_a
		|| operation == shift_up_a || operation == shift_down_a)
		*(*str + 1) = 'a';
	else if (operation == swap_b || operation == push_b
		|| operation == shift_up_b || operation == shift_down_b)
		*(*str + 1) = 'b';
	else
		*(*str + 1) = **str;
	*(*str + 2) = '\n';
	(*str) += 3;
	return (3 + (operation >= shift_down_a && operation <= shift_down_both));
}

void	get_instruction_str(t_stacks *stacks)
{
	char			*str;
	t_instruction	*curr;
	t_instruction	*next;

	str = malloc(stacks->instruction_count * 4 + 1);
	stacks->instruction_str = str;
	curr = stacks->instruction_list;
	stacks->strlen = 0;
	while (curr)
	{
		stacks->strlen += instruction_to_string(curr->operation, &str);
		next = curr->next;
		free(curr);
		curr = next;
	}
	*str = '\0';
}
