/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:51:46 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/26 12:37:32 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../includes/push_swap.h"
#include "../includes/sorting.h"

int	main(const int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		v_flag;

	if (!check_arguments(argc, argv, &v_flag))
		error_and_exit("Error");
	stack_a = parse_input(argc, argv);
	if (!stack_a)
		error_and_exit("Error");
	stack_b = init_stack();
	if (!stack_b)
	{
		clear_stack(stack_a);
		error_and_exit("Error");
	}
	sort_stack(stack_a, stack_b);
	clear_stack(stack_a);
	clear_stack(stack_b);
	return (0);
}
