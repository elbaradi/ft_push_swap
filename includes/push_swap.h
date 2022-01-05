/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/21 12:55:00 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/08/05 17:27:30 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
#  define PUSH_SWAP_H

#  include "stacks.h"

typedef struct s_data
{
	t_stacks		*stacks;
	int				top_score;
	char			*top_answer;
	int				strlen;
}	t_data;

typedef struct s_vec2i
{
	int	i;
	int	j;
}	t_vec2i;

# endif