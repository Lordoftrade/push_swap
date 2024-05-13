/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:34:50 by mgreshne          #+#    #+#             */
/*   Updated: 2024/05/02 19:34:50 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_max(t_list *stack, int i)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp->index != 0)
	{
		if (tmp->index == i - 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	sorting_3_values(t_list **a)
{
	t_list	*tmp;

	if (*a == NULL || (*a)->next == NULL || (*a)->next->next == NULL)
		ft_error_exit();
	tmp = *a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (((*a)->index > (*a)->next->index) && ((*a)->index > tmp->index))
		ra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
	if ((*a)->next->index > tmp->index)
	{
		rra(a);
		if ((*a)->index > (*a)->next->index)
			sa(a);
	}
	return (1);
}

int	sorting_4_values(t_list **a, t_list **b, int size)
{
	if (*a == NULL)
		ft_error_exit();
	while (((*a)->index != size - 1))
	{
		if (index_max(*a, size) == 1)
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
	sorting_3_values(a);
	pa(a, b);
	ra(a);
	return (1);
}

int	sorting_2_values(t_list **a)
{
	if (*a == NULL || (*a)->next == NULL)
		ft_error_exit();
	if ((*a)->index > (*a)->next->index)
		sa(a);
	return (1);
}

void	choosing_algorithm(t_list **a, t_list **b, int size)
{
	int	i;

	i = 0;
	if (size == 2)
		i = sorting_2_values(a);
	else if (size == 3)
		i = sorting_3_values(a);
	else if (size == 4)
		i = sorting_4_values(a, b, size);
	else if (size == 5)
		i = sorting_5_values(a, b);
	else if (size > 5)
	{
		i = butterfly(a, b, size);
	}
	if (i != 0)
	{
		ft_free_list(a);
		exit(0);
	}
}
