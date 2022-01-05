/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/14 15:06:30 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/08/05 17:31:03 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# ifndef CHECKER_H
#  define CHECKER_H

#  include "instructions.h"
#  include "stacks.h"

typedef struct s_data_b
{
	t_instruction	*instruction;
	t_stacks		*stacks;
}	t_data_b;

# endif