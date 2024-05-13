/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionally.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:40:29 by mgreshne          #+#    #+#             */
/*   Updated: 2024/04/29 13:40:29 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_index(t_list *a, int *int_array, int size)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (i < size)
	{
		tmp = a;
		while (tmp != NULL)
		{
			if (int_array[i] == tmp->value)
				tmp->index = i;
			tmp = tmp->next;
		}
		i++;
	}
}

void	sorted_int_array(int *int_array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (int_array[j] > int_array[j + 1])
			{
				tmp = int_array[j];
				int_array[j] = int_array[j + 1];
				int_array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	ft_atoi(char *str, int *int_array, char **str_array)
{
	int			i;
	int			sign;
	long long	nb;

	nb = 0;
	sign = 1;
	i = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if (!(nb * sign >= INT_MIN && nb * sign <= INT_MAX))
		{
			ft_free_str(str_array);
			free(int_array);
			ft_error_exit();
		}
		i++;
	}
	return (nb * sign);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*merge_lines(const char **strings, size_t count)
{
	char		*container;
	size_t		total_length;
	size_t		i;

	total_length = 0;
	if (strings == NULL || count == 0)
		exit(1);
	i = 0;
	while (i < count)
	{
		if (strings[i] != NULL)
			total_length += ft_strlen(strings[i++]);
	}
	container = (char *)malloc(total_length + count);
	if (container == NULL)
		exit(1);
	copy_strings_with_spaces(strings, count, container);
	return (container);
}
