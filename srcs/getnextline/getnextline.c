/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   getnextline.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:20:20 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/07/14 03:31:33 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "getnextline.h"

static t_list	*find_lst(int fd, t_list **lst)
{
	t_list			*new;
	t_list			*cycle;

	cycle = *lst;
	while (cycle)
	{
		if (cycle->fd == fd)
			return (cycle);
		if (!cycle->next)
			break ;
		cycle = cycle->next;
	}
	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->index = 0;
	new->fd = fd;
	new->next = 0;
	new->bytes_read = 0;
	*new->buf = *(char *)ft_memset(new->buf, 0, BUFFER_SIZE);
	if (*lst)
		cycle->next = new;
	else
		*lst = new;
	return (new);
}

static char	*copy_till_newline(t_list *lst)
{
	char			*tmp;
	ssize_t			start;
	ssize_t			i;

	start = lst->index;
	while (lst->index < lst->bytes_read && lst->buf[lst->index] != '\n')
		lst->index++;
	tmp = malloc(lst->index - start + 1);
	if (!tmp)
		return (0);
	i = 0;
	while (i < lst->index - start)
	{
		*(tmp + i) = lst->buf[start + i];
		i++;
	}
	*(tmp + i) = 0;
	if (lst->index == lst->bytes_read)
		lst->eob_reached = 1;
	if (lst->buf[lst->index] == '\n')
	{
		lst->newline_reached = 1;
		lst->index++;
	}
	return (tmp);
}

static int	exit_get_next_line(t_list **lst, t_list *curr, int rtn_value)
{
	t_list			*tmp;
	t_list			*cycle;

	if (!*lst)
		return (rtn_value);
	cycle = *lst;
	while (cycle)
	{
		tmp = cycle->next;
		if (rtn_value == -1)
			free(cycle);
		if (rtn_value == 0 && cycle->next == curr)
			cycle->next = curr->next;
		if (rtn_value == 0 && cycle == curr)
		{
			if (*lst == curr)
				*lst = curr->next;
			free(cycle);
			return (0);
		}
		cycle = tmp;
	}
	*lst = 0;
	return (rtn_value);
}

static int	process_input(t_list **lst, t_list *curr, char **line)
{
	char			*tmp;

	while (!curr->newline_reached)
	{
		tmp = copy_till_newline(curr);
		if (!tmp)
			return (exit_get_next_line(lst, curr, -1));
		*line = ft_gnl_strcat(line, tmp);
		free(tmp);
		if (!line)
			return (exit_get_next_line(lst, curr, -1));
		if (curr->eob_reached || !curr->index)
		{
			curr->index = 0;
			*curr->buf = *(char *)ft_memset(&curr->buf, 0, BUFFER_SIZE);
			curr->bytes_read = read(curr->fd, curr->buf, BUFFER_SIZE);
			if (!curr->bytes_read)
				return (exit_get_next_line(lst, curr, 0));
			if (curr->bytes_read == -1)
				return (exit_get_next_line(lst, curr, -1));
			curr->eob_reached = 0;
		}
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static t_list	*lst = 0;
	t_list			*curr;

	curr = find_lst(fd, &lst);
	if (!curr || BUFFER_SIZE < 1 || fd < 0 || line == 0)
		return (exit_get_next_line(&lst, curr, -1));
	*line = 0;
	curr->newline_reached = 0;
	curr->eob_reached = 0;
	return (process_input(&lst, curr, line));
}
