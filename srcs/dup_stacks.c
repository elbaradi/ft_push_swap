/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dup_stacks.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/21 15:13:40 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/08/02 14:23:58 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "stacks.h"
#include <stdlib.h>

static t_stacks	*dup_stacks_init(void)
{
	t_stacks	*dup;

	dup = malloc(sizeof(t_stacks));
	if (dup == NULL)
		ps_error();
	dup->a = malloc(sizeof(t_stack));
	if (dup->a == NULL)
		ps_error();
	ft_bzero(dup->a, sizeof(t_stack));
	dup->b = malloc(sizeof(t_stack));
	if (dup->b == NULL)
		ps_error();
	ft_bzero(dup->b, sizeof(t_stack));
	return (dup);
}

static t_link	*dup_link(t_link *link)
{
	t_link	*dup;

	dup = malloc(sizeof(t_link));
	if (dup == NULL)
		ps_error();
	dup->nbr = link->nbr;
	dup->index = link->index;
	dup->prev = NULL;
	dup->next = NULL;
	return (dup);
}

t_stacks	*dup_stacks(t_stacks *stacks)
{
	t_stacks	*dup;
	t_link		*link;
	t_link		*dup_ln;

	dup = dup_stacks_init();
	dup->a->size = stacks->a->size;
	link = stacks->a->head;
	dup_ln = dup_link(link);
	dup->a->head = dup_ln;
	while (link->next)
	{
		dup_ln->next = dup_link(link->next);
		dup_ln->next->prev = dup_ln;
		dup_ln = dup_ln->next;
		link = link->next;
	}
	dup->a->tail = dup_ln;
	return (dup);
}
