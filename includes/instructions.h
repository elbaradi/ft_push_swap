/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/14 16:43:28 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/08/02 16:52:42 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

typedef enum e_operation
{
	swap_a,
	swap_b,
	swap_both,
	push_a,
	push_b,
	shift_up_a,
	shift_up_b,
	shift_up_both,
	shift_down_a,
	shift_down_b,
	shift_down_both,
	empty,
	invalid
}	t_operation;

typedef struct s_instruction
{
	t_operation				operation;
	struct s_instruction	*next;
}	t_instruction;

#endif
