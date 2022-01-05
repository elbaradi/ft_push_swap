/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prototypes.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/14 09:57:06 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/08/05 17:32:20 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include <stddef.h>
# include "instructions.h"
# include "stacks.h"
# include "push_swap.h"

# define CHUNK_SIZE 3

# ifdef CHECKER
/* Read Instructions [CHECKER] */
t_instruction		*read_instructions(void);
void				process_instructions(t_instruction *instruction_list);
void				free_instructions(t_instruction *lst);

# else
/* Write Instructions [PUSH_SWAP] */
int					add_instruction(t_instruction **link, int operation);
void				get_instruction_str(t_stacks *stacks);

/* Sorting [PUSH_SWAP] */
void				sort_tree(t_stack *list);
void				sort_stack(t_data *data);
void				first_cycle(t_stacks *stacks);
void				divide_stack_a_in_three(t_stacks *stacks,
						unsigned long long id);
void				divide_stack_b_in_three(t_stacks *stacks,
						unsigned long long id);
void				solve_top_chunk_in_a(t_stacks *stacks);
void				solve_top_chunk_in_b(t_stacks *stacks);
void				sort_first_cycle(t_stacks *stacks, int *chunk_size);
void				sort_top_chunk_in_a(t_stacks *stacks, unsigned long long id,
						int *chunk_size);
void				sort_top_chunk_in_b(t_stacks *stacks, unsigned long long id,
						int *chunk_size);
void				rotate_back(t_stacks *stacks, int rot_a, int rot_b);
unsigned long long	encoder(int first, int second, int third, int fourth);

/* Solver [PUSH_SWAP]	*/
int					solve_if_solvable_chunk_in_a(t_stacks *stacks);
int					solve_if_solvable_chunk_in_b(t_stacks *stacks);
t_link				*get_link(t_stack *stack, int offset);
void				solve_chunk_size_two_in_a(t_stacks *stacks);
void				solve_chunk_size_three_in_a(t_stacks *stacks);
void				solve_chunk_size_two_in_b(t_stacks *stacks);
void				solve_chunk_size_three_in_b(t_stacks *stacks);
# endif

/* Checker [BOTH] */
int					check_sort(t_stacks *stacks);
int					is_sorted(t_stack *stack);

/* Error [BOTH] */
void				ps_error(void);

/* Instructions [BOTH] */
void				ps_instruct(t_stacks *stacks,
						unsigned long long operation_sequence);
void				ps_swap(t_stacks *stacks, t_operation operation);
void				ps_push(t_stacks *stacks, t_operation operation);
void				ps_shift_up(t_stacks *stacks, t_operation operation);
void				ps_shift_down(t_stacks *stacks, t_operation operation);
void				ps_both(t_stacks *stacks, t_operation operation);

/* Stacks [BOTH] */
t_stacks			*create_stacks(char **input);
t_stacks			*getstacks(void);
t_stacks			*dup_stacks(t_stacks *stacks);
void				free_stacks(t_stacks *stacks);

/* Utils [BOTH] */
int					ft_strlen_without_padding(char *str, char padding);
int					is_valid_number_string(char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isdigit(int c);
long long			ft_atoi(char *str);
int					no_duplicates(t_stacks *stacks);
void				ft_putstr(char *s);
size_t				ft_strlen(const char *s);

#endif
