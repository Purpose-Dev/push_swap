/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:09:20 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/26 12:15:29 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/parsing.h"
#include "../libs/libft/includes/libft.h"

int	handle_error_and_cleanup(t_stack *stack_a, t_stack *stack_b)
{
	ft_putstr_fd("Error\n", 2);
	clear_stack(stack_a);
	clear_stack(stack_b);
	return (1);
}

int	init_and_parse(const int argc, char **argv, t_stack **stack_a,
		t_stack **stack_b)
{
	int	v_flag;

	v_flag = 0;
	if (check_arguments(argc, argv, &v_flag) == -1)
		return (-1);
	*stack_a = parse_input(argc, argv);
	if (!*stack_a)
		return (-1);
	*stack_b = init_stack();
	return (0);
}
