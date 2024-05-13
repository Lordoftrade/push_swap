/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:40:36 by mgreshne          #+#    #+#             */
/*   Updated: 2024/04/29 13:40:36 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_list(t_list **stack)
{
	t_list	*current;
	t_list	*next;

	if (stack == NULL || *stack == NULL)
		return ;
	current = *stack;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	ft_error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free_charstr(char **str_array)
{
	int	i;

	i = 0;
	while (str_array[i])
		free(str_array[i++]);
	free(str_array);
	exit(1);
}

void	ft_free_str(char **str_array)
{
	int	i;

	i = 0;
	while (str_array[i])
		free(str_array[i++]);
	free(str_array);
}
