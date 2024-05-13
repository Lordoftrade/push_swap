/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:55:28 by mgreshne          #+#    #+#             */
/*   Updated: 2024/05/03 18:24:05 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_space(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == 45 || str[i] == 43)
		&& (str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	while (str[i])
	{
		if ((str[i] == 45 || str[i] == 43) && str[i - 1] != 32)
			return (1);
		i++;
	}
	return (0);
}

int	*convert_to_int_array(char **str_array, int *size)
{
	int		*int_array;
	int		i;
	long	num;

	*size = 0;
	i = 0;
	while (str_array[*size])
		*size += 1;
	int_array = (int *)malloc(sizeof(int) * (*size));
	if (!int_array)
		ft_free_charstr(str_array);
	while (i < *size)
	{
		num = ft_atoi(str_array[i], int_array, str_array);
		int_array[i++] = num;
	}
	return (int_array);
}

void	ft_is_digit_sign(char *argv)
{
	int	j;
	int	len;

	j = -1;
	len = ft_strlen(argv);
	while (argv[++j] != '\0')
	{
		if (((argv[j] < 48) || (argv[j] > 57)) && (argv[j] != 32))
		{
			if (argv[j] != 45 && argv[j] != 43)
				ft_error_exit();
		}
		if ((argv[j] == 32) && (argv[j + 1] == 32))
			ft_error_exit();
		if (argv[j] == 45 || argv[j] == 43)
		{
			if (j + 1 >= len || (argv[j + 1] < 48 || argv[j + 1] > 57))
				ft_error_exit();
		}
	}
}

void	checking_arg(int argc, char **argv)
{
	int	i;
	int	len;

	i = 1;
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		if ((argv[i][len - 1] == ' ') || (argv[i][0] == ' ') || !argv[i][0])
			ft_error_exit();
		ft_is_digit_sign(argv[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	**argc_split;
	char	*finish;
	int		*int_array;
	int		size;
	int		i;

	argc_split = NULL;
	finish = NULL;
	int_array = NULL;
	if (argc == 1)
		exit(0);
	check_input(argc, argv, &argc_split, &finish);
	int_array = convert_to_int_array(argc_split, &size);
	i = 0;
	while (argc_split[i])
		free(argc_split[i++]);
	free(argc_split);
	ft_checking_duplication(int_array, size);
	check_sorted(int_array, size);
	after_parsing(int_array, size);
	return (0);
}
