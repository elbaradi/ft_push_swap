/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/20 10:25:46 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/08/05 16:35:38 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include "prototypes.h"

int	is_empty(t_stack *stack)
{
	return (stack->size == 0);
}

int	is_sorted(t_stack *stack)
{
	t_link	*link;

	link = stack->head;
	while (link->next)
	{
		if (link->nbr >= link->next->nbr)
			return (0);
		link = link->next;
	}
	return (1);
}

int	check_sort(t_stacks *stacks)
{
	if ((is_empty(stacks->b)) && is_sorted(stacks->a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (1);
}
