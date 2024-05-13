/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionally2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:58:35 by mgreshne          #+#    #+#             */
/*   Updated: 2024/05/03 15:58:35 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_strings_with_spaces(const char **strings,
	size_t count, char *container)
{
	size_t	i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < count)
	{
		j = 0;
		while (strings[i][j])
			container[k++] = strings[i][j++];
		if (strings[i + 1])
			container[k++] = ' ';
		i++;
	}
	container[k] = '\0';
}
