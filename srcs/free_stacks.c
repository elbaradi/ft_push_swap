/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_stacks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/03 17:13:18 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/08/05 14:02:59 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "prototypes.h"
#include "stacks.h"

void	free_stacks(t_stacks *stacks)
{
	t_link	*link;
	t_link	*tmp;

	link = stacks->a->head;
	while (link)
	{
		tmp = link->next;
		free(link);
		link = tmp;
	}
	free(stacks->a);
	link = stacks->b->head;
	while (link)
	{
		tmp = link->next;
		free(link);
		link = tmp;
	}
	free(stacks->b);
}
