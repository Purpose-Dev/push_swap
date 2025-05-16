/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:51:44 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/05/16 12:26:51 by rel-qoqu         ###   ########.fr       */
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
		if (str[i] < '0' || str[i] > '9')
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

int	check_arguments(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (FALSE);
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
