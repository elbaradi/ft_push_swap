/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   no_duplicates.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/14 13:27:38 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/04/14 15:54:47 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

int	no_duplicates(t_stacks *stacks)
{
	t_link	*link;
	t_link	*cmp;

	link = stacks->a->head;
	while (link)
	{
		cmp = link->next;
		while (cmp)
		{
			if (link->nbr == cmp->nbr)
				return (0);
			cmp = cmp->next;
		}
		link = link->next;
	}
	return (1);
}
