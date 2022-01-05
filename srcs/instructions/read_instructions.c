/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_instructions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/14 17:55:47 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/08/05 14:01:51 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"
#include "getnextline.h"
#include "prototypes.h"

t_operation	get_operation(char *str)
{
	t_operation	operation;

	if (!(*str))
		return (empty);
	if (*str == 's')
		operation = swap_a;
	else if (*str == 'p')
		operation = push_a;
	else if (*str == 'r' && *(str + 1) == 'r' && *(str + 2))
	{
		operation = shift_down_a;
		str++;
	}
	else if (*str == 'r')
		operation = shift_up_a;
	else
		return (invalid);
	str++;
	if (*str == 'b')
		operation += 1;
	else if (*str == *(str - 1) && *str != 'p')
		operation += 2;
	else if (*str != 'a')
		return (invalid);
	return (operation);
}

static void	loop_read_instructions(t_instruction *lst)
{
	int				ret;
	char			*line;
	t_instruction	*link;

	ret = 1;
	link = lst;
	while (ret > 0)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		if (ret == -1)
			ps_error();
		link->operation = get_operation(line);
		if (link->operation == invalid
			|| (link->operation == empty && (link != lst && ret > 0)))
			ps_error();
		if (ret)
		{
			link->next = malloc(sizeof(t_instruction));
			if (link->next == NULL)
				ps_error();
			link = link->next;
		}
		free(line);
	}
	link->next = NULL;
}

t_instruction	*read_instructions(void)
{
	t_instruction	*list;

	list = malloc(sizeof(t_instruction));
	if (list == NULL)
		ps_error();
	loop_read_instructions(list);
	return (list);
}

void	free_instructions(t_instruction *lst)
{
	t_instruction	*link;
	t_instruction	*tmp;

	link = lst;
	while (link)
	{
		tmp = link->next;
		free(link);
		link = tmp;
	}
}
