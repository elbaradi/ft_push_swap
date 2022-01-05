/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_sort.c                   	                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/21 14:52:56 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/07/14 03:27:36 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stacks.h"
#include "prototypes.h"
#include "instructions.h"
#include <stdlib.h>
#include <unistd.h>

static t_instruction	*init_instruction_list(t_stacks *stacks)
{
	stacks->instruction_list = malloc(sizeof(t_instruction));
	if (stacks->instruction_list == NULL)
		ps_error();
	stacks->instruction_list->operation = empty;
	return (stacks->instruction_list);
}

static void	compare_highscore(t_data *data, t_stacks *stacks)
{
	if (data->top_score == 0 || stacks->instruction_count < data->top_score)
	{
		data->top_score = stacks->instruction_count;
		if (data->top_answer)
			free(data->top_answer);
		data->top_answer = stacks->instruction_str;
		data->strlen = stacks->strlen;
	}
	else
		free(stacks->instruction_str);
}

void	sort_stack(t_data *data)
{
	t_stacks		*stacks;
	t_instruction	*root;
	int				i;

	i = 0;
	while (i < 2)
	{
		stacks = dup_stacks(data->stacks);
		stacks->method = i;
		root = init_instruction_list(stacks);
		first_cycle(stacks);
		stacks->instruction_list = root;
		get_instruction_str(stacks);
		compare_highscore(data, stacks);
		free_stacks(stacks);
		free(stacks);
		i++;
	}
	write(1, data->top_answer, data->strlen);
	free(data->top_answer);
	free_stacks(data->stacks);
}
