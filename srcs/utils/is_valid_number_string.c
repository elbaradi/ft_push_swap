/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_valid_number_string.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/14 09:56:57 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/04/14 14:44:43 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	is_valid_number_string(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (!(*str))
		return (0);
	while (*str && ft_isdigit(*str))
		str++;
	if (*str)
		return (0);
	return (1);
}
