/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/20 19:44:12 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/08/05 17:35:47 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "prototypes.h"

int	main(int argc, char **argv)
{
	t_data			*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		ps_error();
	ft_bzero(data, sizeof(t_data));
	(void)argc;
	data->stacks = create_stacks(argv + 1);
	if (is_sorted(data->stacks->a))
		exit(EXIT_SUCCESS);
	sort_tree(data->stacks->a);
	sort_stack(data);
	free(data);
	exit(EXIT_SUCCESS);
}
