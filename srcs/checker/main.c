/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/14 14:56:19 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/08/05 17:42:43 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "prototypes.h"
#include "checker.h"
#include "instructions.h"
#include "stacks.h"

int	main(int argc, char **argv)
{
	t_data_b	*data;

	data = malloc(sizeof(t_data_b));
	if (data == NULL)
		ps_error();
	(void)argc;
	data->stacks = create_stacks(argv + 1);
	data->instruction = read_instructions();
	process_instructions(data->instruction);
	check_sort(data->stacks);
	free_instructions(data->instruction);
	free_stacks(data->stacks);
	free(data);
	exit(EXIT_SUCCESS);
}
