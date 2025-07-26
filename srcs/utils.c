/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:32:05 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/26 12:42:21 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../includes/push_swap.h"

void	free_element(void *elem)
{
	if (elem)
		free(elem);
}

void	error_and_exit(const char *msg)
{
	ft_dprintf(2, msg);
	ft_dprintf(2, "\n");
	exit(EXIT_FAILURE);
}

int	check_arguments(int argc, char **argv, int *v_flag)
{
	int	i;

	*v_flag = FALSE;
	if (argc < 2)
		return (FALSE);
	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-v") == 0)
		{
			*v_flag = TRUE;
			while (i < argc - 1)
			{
				argv[i] = argv[i + 1];
				i++;
			}
			argc--;
			break ;
		}
		i++;
	}
	return (argc >= 2);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	is_valid_number(const char *str)
{
	int		i;
	long	num;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (FALSE);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		i++;
	}
	num = ft_atol(str);
	return (num >= INT_MIN && num <= INT_MAX);
}
