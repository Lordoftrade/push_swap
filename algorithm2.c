/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:04:54 by mgreshne          #+#    #+#             */
/*   Updated: 2024/05/02 19:04:54 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorting_5_values(t_list **a, t_list **b)
{
	int	j;
	int	i;

	if ((a == NULL || *a == NULL) && *b != NULL)
		ft_error_exit();
	i = 2;
	j = 0;
	while (j++ != 2)
	{
		while ((*a)->index != i - 1)
		{
			if (index_max(*a, i) == 1)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
		i--;
	}
	sorting_3_values(a);
	if ((*b)->index < (*b)->next->index)
		sb(b);
	pa(a, b);
	pa(a, b);
	return (1);
}

int	ft_range(int size)
{
	int	i;
	int	a;
	int	b;

	i = 1;
	while (i * i <= size)
	{
		if (i * i <= size)
			a = i;
		if (i * i * i <= size)
			b = i;
		i++;
	}
	i = a + b + 1;
	return (i);
}

void	push_b_in_a(t_list **a, t_list **b, int size)
{
	while (size > 0)
	{
		while ((*b)->index != size - 1)
		{
			if (index_max(*b, size) == 1)
				rb(b);
			else
				rrb(b);
		}
		pa(a, b);
		size--;
	}
}

int	butterfly(t_list **a, t_list **b, int size)
{
	int	count;
	int	n;

	count = 0;
	n = ft_range(size);
	while (*a && count < size)
	{
		if ((*a)->index <= count)
		{
			pb(a, b);
			rb(b);
			count++;
		}
		else if ((*a)->index <= count + n)
		{
			pb(a, b);
			count++;
		}
		else
			ra(a);
	}
	push_b_in_a(a, b, size);
	return (1);
}
