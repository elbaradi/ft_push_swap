/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree_sort.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/18 12:14:48 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/07/14 03:28:34 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_SORT_H
# define TREE_SORT_H

# include <stdlib.h>
# include <stacks.h>

typedef struct s_node
{
	t_link			*ptr;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

#endif