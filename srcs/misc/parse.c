/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:51:44 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/26 12:47:48 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static int	has_duplicates(const int *numbers, const int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (numbers[i] == numbers[j])
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

static int	parse_single_string_arg(const char *arg_str, int **numbers_ptr)
{
	char	**split;
	int		i;
	int		count;

	split = ft_split(arg_str, ' ');
	if (!split)
		return (0);
	count = 0;
	while (split[count])
		count++;
	*numbers_ptr = malloc(sizeof(int) * count);
	if (!*numbers_ptr)
		return (free_split(split), 0);
	i = 0;
	while (i < count)
	{
		if (!is_valid_number(split[i]))
			return (free(*numbers_ptr), free_split(split), 0);
		(*numbers_ptr)[i] = ft_atoi(split[i]);
		i++;
	}
	return (free_split(split), count);
}

static int	parse_multiple_args(const int argc, char **argv, int **numbers_ptr)
{
	int	i;
	int	count;

	count = argc - 1;
	*numbers_ptr = malloc(sizeof(int) * count);
	if (!*numbers_ptr)
		return (0);
	i = 0;
	while (i < count)
	{
		if (!is_valid_number(argv[i + 1]))
		{
			free(*numbers_ptr);
			return (0);
		}
		(*numbers_ptr)[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (count);
}

static int	parse_arguments(const int argc, char **argv, int **numbers)
{
	int		count;

	if (argc == 2)
		count = parse_single_string_arg(argv[1], numbers);
	else
		count = parse_multiple_args(argc, argv, numbers);
	if (count == 0)
		return (0);
	if (has_duplicates(*numbers, count))
	{
		free(*numbers);
		return (0);
	}
	return (count);
}

t_stack	*parse_input(const int argc, char **argv)
{
	t_stack		*stack;
	int			*numbers;
	int			i;
	const int	count = parse_arguments(argc, argv, &numbers);

	if (count == 0)
		return (NULL);
	stack = init_stack();
	if (!stack)
	{
		free(numbers);
		return (NULL);
	}
	i = count - 1;
	while (i >= 0)
	{
		push_stack(stack, numbers[i]);
		i--;
	}
	free(numbers);
	return (stack);
}
