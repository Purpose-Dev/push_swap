/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:51:44 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/05/16 18:09:31 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	is_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	has_duplicate(t_stack *stack, int value)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value == value)
			return (TRUE);
		current = current->next;
	}
	return (FALSE);
}

static int	is_valid_int(const char *str)
{
	int	val;

	val = ft_atoi(str);
	if (val < INT_MIN || val > INT_MAX)
		return (FALSE);
	return (TRUE);
}

int	check_arguments(int argc, char **argv, int *v_flag)
{
	int	i;
	int	j;

	*v_flag = 0;
	if (argc <= 1)
		return (FALSE);
	if (!ft_strncmp(argv[1], "-v", 2))
		*v_flag = 1;
	i = 1 + *v_flag;
	while (i < argc)
	{
		if (!is_number(argv[i]) || !is_valid_int(argv[i]))
			return (FALSE);
		j = i + 1;
		while (j < argc)
		{
			if (!ft_strncmp(argv[i], argv[j], 5))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

t_stack	*parse_input(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	int		value;

	i = 1;
	a = init_stack();
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		if (has_duplicate(a, value))
			error_and_exit("Error: Duplicate values");
		push(a, value);
		i++;
	}
	return (a);
}
