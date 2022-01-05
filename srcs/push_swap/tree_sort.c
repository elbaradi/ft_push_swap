/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/18 12:14:03 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/08/02 14:45:49 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tree_sort.h"
#include "stacks.h"
#include "prototypes.h"

static void	tree_to_index(t_node *node, int *index)
{
	if (node)
	{
		tree_to_index(node->left, index);
		node->ptr->index = *index;
		(*index)++;
		tree_to_index(node->right, index);
		free(node);
	}
}

static void	insert(t_node *parent, t_link *link, int left)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
		ps_error();
	new->ptr = link;
	new->left = NULL;
	new->right = NULL;
	if (left == 1)
		parent->left = new;
	else
		parent->right = new;
}

static void	traverse(t_node *node, t_link *link)
{
	if (node->ptr->nbr > link->nbr)
	{
		if (node->left == NULL)
			insert(node, link, 1);
		else
			traverse(node->left, link);
	}
	else if (node->ptr->nbr < link->nbr)
	{
		if (node->right == NULL)
			insert(node, link, 2);
		else
			traverse(node->right, link);
	}
}

/* This function take the integer list, creates a binary tree,
traverses the tree sorting the integers into an array, while deleting the tree.
*/
void	sort_tree(t_stack *list)
{
	int		index;
	t_node	*root;
	t_link	*link;

	root = malloc(sizeof(t_node));
	if (root == NULL)
		ps_error();
	link = list->head;
	root->ptr = link;
	root->left = NULL;
	root->right = NULL;
	while (link->next)
	{
		link = link->next;
		traverse(root, link);
	}
	index = 0;
	tree_to_index(root, &index);
	return ;
}
