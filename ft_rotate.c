/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:35:48 by mgreshne          #+#    #+#             */
/*   Updated: 2024/05/02 19:35:48 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*current;

	if (*stack && (*stack)->next)
	{
		last = *stack;
		*stack = (*stack)->next;
		last->next = NULL;
		current = *stack;
		while (current->next)
			current = current->next;
		current->next = last;
	}
	else
		return ;
}

void	ra(t_list **a)
{
	if (*a == NULL || (*a)->next == NULL)
		return ;
	ft_rotate(a);
	write (1, "ra\n", 3);
}

void	rb(t_list **b)
{
	if (*b == NULL)
		return ;
	ft_rotate(b);
	write (1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	if (*a == NULL || *b == NULL || (*a)->next == NULL || (*b)->next == NULL)
		return ;
	ft_rotate(a);
	ft_rotate(b);
	write (1, "rr\n", 3);
}
