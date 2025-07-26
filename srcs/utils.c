/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:32:05 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/26 12:37:43 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
