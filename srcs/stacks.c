/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stacks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/12 14:19:22 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/08/02 14:24:07 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "prototypes.h"
#include "stacks.h"

t_stacks	*getstacks(void)
{
	static t_stacks	stacks = {0};

	return (&stacks);
}

t_stacks	*init_stacks(void)
{
	t_stacks	*stacks;

	stacks = getstacks();
	stacks->a = malloc(sizeof(t_stack));
	if (stacks->a == NULL)
		return (NULL);
	ft_bzero(stacks->a, sizeof(t_stack));
	stacks->b = malloc(sizeof(t_stack));
	if (stacks->b == NULL)
	{
		free(stacks->a);
		return (NULL);
	}
	ft_bzero(stacks->b, sizeof(t_stack));
	return (stacks);
}

int	is_valid_int(char *input)
{
	if (ft_strlen_without_padding(input, '0') > 11)
		return (0);
	if (!(is_valid_number_string(input)))
		return (0);
	return (1);
}

int	store_int(char *input, t_stacks *stacks)
{
	t_link		*new;
	long long	nbr;

	new = malloc(sizeof(t_link));
	if (new == NULL)
		return (0);
	nbr = ft_atoi(input);
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (0);
	new->nbr = (int)nbr;
	new->prev = stacks->a->tail;
	new->next = NULL;
	if (stacks->a->head == NULL)
		stacks->a->head = new;
	else
		stacks->a->tail->next = new;
	stacks->a->tail = new;
	stacks->a->size += 1;
	return (1);
}

t_stacks	*create_stacks(char **input)
{
	t_stacks	*stacks;

	stacks = init_stacks();
	while (*input)
	{
		if (is_valid_int(*input) == 0)
			ps_error();
		if (store_int(*input, stacks) == 0)
			ps_error();
		input++;
	}
	if (stacks->a->head == NULL)
		exit(EXIT_SUCCESS);
	if (no_duplicates(stacks) == 0)
		ps_error();
	return (stacks);
}
