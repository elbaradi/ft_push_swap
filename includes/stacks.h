/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stacks.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/12 10:54:51 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/08/02 17:05:03 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H
# include "instructions.h"

typedef struct s_link
{
	int					nbr;
	int					index;
	int					chunk_index;
	unsigned long long	sort_id;
	int					chunk;
	struct s_link		*next;
	struct s_link		*prev;
}	t_link;

typedef struct s_stack
{
	t_link				*head;
	t_link				*tail;
	unsigned long long	size;
}	t_stack;

typedef struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
	t_instruction	*instruction_list;
	int				instruction_count;
	char			*instruction_str;
	int				strlen;
	int				method;
}	t_stacks;

typedef struct s_vecstacks
{
	t_stack			*dst;
	t_stack			*src;
}	t_vecstacks;

#endif
