/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/14 01:39:01 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/08/05 14:07:54 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stacks.h"
#include "prototypes.h"
#include "instructions.h"
#include <stdio.h>

// gcc -Wall -Werror -Wextra main.c optimizations.c tree_sort.c stack_sort.c stack_sort_utils.c solve_chunk_in_a.c solve_chunk_in_b.c algorithm.c ../error.c ../stacks.c ../dup_stacks.c ../checker/check_sort.c ../utils/*.c ../instructions/*.c ../getnextline/*.c -I../../includes -g -fsanitize=address -o push_swap

// ./push_swap 0 9 1 8 2
// ./push_swap 8 3 6 1 7 0 5 2 9 4

// gcc -Wall -Werror -Wextra -D CHECKER main.c check_sort.c ../error.c ../stacks.c ../utils/*.c ../instructions/*.c ../getnextline/*.c -I../../includes -g -fsanitize=address -o checker 
// cat empty.txt | ./checker 0 1 2
// cat test.txt | ./checker 0 9 1 8 2
// cat out.txt | ./checker 8 3 6 1 7 0 5 2 9 4

void	show_top_of_stacks(t_stacks *stacks)
{
	t_link			*link;
	int				i;

	link = stacks->a->head;
	if (link && link->next && link->next->next && link->next->next->next && link->next->next->next->next)
	{
		printf("\n\nSTACK A\n");
		i = 0;
		while (i < 5)
		{
			printf("Number: %d [%d, %d, %d, %llu]\n", link->nbr, link->index, link->chunk, link->chunk_index, link->sort_id);
			link = link->next;
			i++;
		}
		i = 0;
		link = stacks->b->head;
		if (link && link->next && link->next->next && link->next->next->next && link->next->next->next->next)
		{
			printf("\n\nSTACK B\n");
			while (i < 5)
			{
				printf("Number: %d [%d, %d, %d, %llu]\n", link->nbr, link->index, link->chunk, link->chunk_index, link->sort_id);
				link = link->next;
				i++;
			}
		}
	}
}