/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:35:39 by mgreshne          #+#    #+#             */
/*   Updated: 2024/05/02 19:35:39 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **a, t_list **b)
{
	t_list	*cur_a;

	if (*a)
	{
		cur_a = *a;
		*a = (*a)->next;
		cur_a->next = *b;
		*b = cur_a;
		write (1, "pb\n", 3);
	}
	else
		return ;
}

void	pa(t_list **a, t_list **b)
{
	t_list	*cur_b;

	if (*b)
	{
		cur_b = *b;
		*b = (*b)->next;
		cur_b->next = *a;
		*a = cur_b;
		write (1, "pa\n", 3);
	}
	else
		return ;
}
