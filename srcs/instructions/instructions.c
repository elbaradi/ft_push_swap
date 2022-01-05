/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/12 10:44:44 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/08/02 16:53:14 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include "prototypes.h"
#include "instructions.h"
#include <stdlib.h>

void	ps_swap(t_stacks *stacks, t_operation operation)
{
	t_stack	*stack;

	if (operation == swap_a)
		stack = stacks->a;
	else
		stack = stacks->b;
	if (stack->size != 0 && stack->size != 1)
	{
		stack->head->prev = stack->head->next;
		stack->head = stack->head->next;
		stack->head->prev->next = stack->head->next;
		stack->head->next = stack->head->prev;
		stack->head->prev = NULL;
		if (stack->size == 2)
		{
			stack->tail = stack->head->next;
			stack->tail->prev = stack->head;
			stack->tail->next = NULL;
		}
		else
			stack->head->next->next->prev = stack->head->next;
	}
}

void	ps_push(t_stacks *stacks, t_operation operation)
{
	t_vecstacks	stx;
	t_link		*tmp;

	stx.dst = stacks->a;
	stx.src = stacks->b;
	if (operation == push_b)
		stx.dst = stacks->b;
	if (operation == push_b)
		stx.src = stacks->a;
	if (stx.src->size == 0)
		return ;
	tmp = stx.src->head;
	stx.src->head = stx.src->head->next;
	if (stx.src->head)
		stx.src->head->prev = NULL;
	stx.src->size -= 1;
	if (stx.src->size == 0 || stx.src->size == 1)
		stx.src->tail = stx.src->head;
	tmp->next = stx.dst->head;
	stx.dst->head = tmp;
	if (stx.dst->size > 0)
		stx.dst->head->next->prev = stx.dst->head;
	stx.dst->size += 1;
	if (stx.dst->size == 1)
		stx.dst->tail = stx.dst->head;
}

// void	ps_push(t_stacks *stacks, t_operation operation)
// {
// 	t_stack	*dst;
// 	t_stack	*src;
// 	t_link	*tmp;

// 	dst = stacks->a;
// 	src = stacks->b;
// 	if (operation == push_b)
// 		dst = stacks->b;
// 	if (operation == push_b)
// 		src = stacks->a;
// 	if (src->size > 0)
// 	{
// 		tmp = src->head;
// 		src->head = src->head->next;
// 		if (src->head)
// 			src->head->prev = NULL;
// 		src->size -= 1;
// 		if (src->size == 0 || src->size == 1)
// 			src->tail = src->head;
// 		tmp->next = dst->head;
// 		dst->head = tmp;
// 		if (dst->size > 0)
// 			dst->head->next->prev = dst->head;
// 		dst->size += 1;
// 		if (dst->size == 1)
// 			dst->tail = dst->head;
// 	}
// }

void	ps_shift_up(t_stacks *stacks, t_operation operation)
{
	t_stack	*stack;
	t_link	*tmp;

	if (operation == shift_up_a)
		stack = stacks->a;
	else
		stack = stacks->b;
	if (stack->size != 0 && stack->size != 1)
	{
		tmp = stack->head;
		stack->head = stack->head->next;
		stack->head->prev = NULL;
		tmp->prev = stack->tail;
		stack->tail->next = tmp;
		stack->tail = tmp;
		stack->tail->next = NULL;
	}
}

void	ps_shift_down(t_stacks *stacks, t_operation operation)
{
	t_stack	*stack;
	t_link	*tmp;

	if (operation == shift_down_a)
		stack = stacks->a;
	else
		stack = stacks->b;
	if (stack->size != 0 && stack->size != 1)
	{
		tmp = stack->tail;
		stack->tail = stack->tail->prev;
		stack->tail->next = NULL;
		tmp->next = stack->head;
		stack->head->prev = tmp;
		stack->head = tmp;
		stack->head->prev = NULL;
	}
}

void	ps_both(t_stacks *stacks, t_operation operation)
{
	if (operation == swap_both)
	{
		ps_swap(stacks, swap_a);
		ps_swap(stacks, swap_b);
	}
	else if (operation == shift_up_both)
	{
		ps_shift_up(stacks, shift_up_a);
		ps_shift_up(stacks, shift_up_b);
	}
	else if (operation == shift_down_both)
	{
		ps_shift_down(stacks, shift_down_a);
		ps_shift_down(stacks, shift_down_b);
	}
}
