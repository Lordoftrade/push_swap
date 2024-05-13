/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:37:10 by mgreshne          #+#    #+#             */
/*   Updated: 2024/05/02 19:37:10 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrotate(t_list **stack)
{
	t_list	*current;
	t_list	*prev;

	if (*stack && (*stack)->next)
	{
		current = *stack;
		prev = NULL;
		while (current->next)
		{
			prev = current;
			current = current->next;
		}
		current->next = *stack;
		*stack = current;
		prev->next = NULL;
	}
	else
		return ;
}

void	rra(t_list **a)
{
	if (*a == NULL || (*a)->next == NULL)
		return ;
	ft_rrotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	if (*b == NULL || (*b)->next == NULL)
		return ;
	ft_rrotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	if (*a == NULL || *b == NULL || (*a)->next == NULL || (*b)->next == NULL)
		return ;
	ft_rrotate(a);
	ft_rrotate(b);
	write(1, "rrr\n", 4);
}
