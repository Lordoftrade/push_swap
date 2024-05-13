/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:39:24 by mgreshne          #+#    #+#             */
/*   Updated: 2024/05/02 19:39:24 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack)
{
	int	value_tmp;
	int	index_tmp;

	if (stack && *stack && (*stack)->next)
	{
		value_tmp = (*stack)->value;
		index_tmp = (*stack)->index;
		(*stack)->value = (*stack)->next->value;
		(*stack)->index = (*stack)->next->index;
		(*stack)->next->value = value_tmp;
		(*stack)->next->index = index_tmp;
	}
}

void	sa(t_list **a)
{
	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	ft_swap(a);
	write (1, "sa\n", 3);
}

void	sb(t_list **b)
{
	if (b == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	ft_swap(b);
	write (1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	if (a == NULL || *a == NULL || b == NULL || *b == NULL)
		return ;
	ft_swap(a);
	ft_swap(b);
	write (1, "ss\n", 3);
}
