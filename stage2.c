/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:39:38 by mgreshne          #+#    #+#             */
/*   Updated: 2024/05/02 19:39:38 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int val)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->value = val;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	fill_list(t_list **a, int *int_array, int size)
{
	t_list	*new_node;
	t_list	*current;
	int		i;

	i = 0;
	while (i < size)
	{
		new_node = create_node(int_array[i++]);
		if (new_node == NULL)
		{
			ft_free_list(a);
			free(int_array);
			exit(1);
		}
		if (*a == NULL)
		{
			*a = new_node;
			current = *a;
		}
		else
		{
			current->next = new_node;
			current = current->next;
		}
	}
}

void	after_parsing(int *int_array, int size)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	fill_list(&a, int_array, size);
	sorted_int_array(int_array, size);
	fill_index(a, int_array, size);
	free(int_array);
	choosing_algorithm(&a, &b, size);
}
