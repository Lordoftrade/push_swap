/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:55:25 by mgreshne          #+#    #+#             */
/*   Updated: 2024/05/03 17:44:48 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}	t_list;

void	check_input(int argc, char **argv, char ***argc_split, char **finish);
int		ft_check_space(char *str);
void	checking_arg(int argc, char **argv);
size_t	ft_strlen(const char *s);
void	ft_error_exit(void);
void	ft_free_list(t_list **stack);
char	*merge_lines(const char **strings, size_t count);
void	copy_strings_with_spaces(const char **strings,
			size_t count, char *container);
char	**ft_split(char const *s, char c);
int		ft_atoi(char *str, int *int_array, char **str_array);
void	ft_checking_duplication(int *int_array, int size);
void	check_sorted(int *int_array, int size);
void	sorted_int_array(int *int_array, int size);
void	fill_index(t_list *a, int *int_array, int size);
void	after_parsing(int *int_array, int size);

void	choosing_algorithm(t_list **a, t_list **b, int size);
int		index_max(t_list *stack, int i);

int		sorting_3_values(t_list **a);
int		sorting_5_values(t_list **a, t_list **b);
int		butterfly(t_list **a, t_list **b, int size);
void	push_b_in_a(t_list **a, t_list **b, int size);

void	ft_swap(t_list **stack);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	ft_rotate(t_list **stack);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	ft_rrotate(t_list **stack);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

void	ft_free_charstr(char **str_array);
void	ft_free_str(char **str_array);
#endif
