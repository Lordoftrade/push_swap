/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:43:26 by mgreshne          #+#    #+#             */
/*   Updated: 2024/05/02 16:43:26 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sorted(int *int_array, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (int_array[i] > int_array[i + 1])
			return ;
		i++;
	}
	free(int_array);
	exit(0);
}

void	ft_checking_duplication(int *int_array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (int_array[i] == int_array[j])
			{
				free(int_array);
				ft_error_exit();
			}
			j++;
		}
		i++;
	}
}

void	check_input(int argc, char **argv, char ***argc_split, char **finish)
{
	if (argc == 2 && !argv[1][0])
		ft_error_exit();
	else
	{
		checking_arg(argc, argv);
		if (argc == 2)
		{
			if (ft_check_space(argv[1]) == 1)
				ft_error_exit();
			*argc_split = ft_split(argv[1], ' ');
		}
		else
		{
			*finish = merge_lines((const char **)&argv[1], argc - 1);
			if (ft_check_space(*finish) == 1)
			{
				free(*finish);
				ft_error_exit();
			}
			*argc_split = ft_split(*finish, ' ');
			free(*finish);
		}
		if (argc_split == NULL || *argc_split == NULL)
			exit(1);
	}
}
