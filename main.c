/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:51:46 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/05/16 17:59:06 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing.h"
#include "sorting.h"

static void	initialize_stacks(int argc, char **argv, t_stack **a,
	t_stack **b, int *v_flags)
{
	int	valid_args;

	valid_args = check_arguments(argc, argv);
	if (!valid_args)
		error_and_exit("Error");
	*a = parse_input(argc, argv);
	*b = init_stack();
}

static void	choose_sorting(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	if (size <= 1)
		return ;
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		sort_large(a, b, size);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		v_flag;

	if (argc < 2)
		return (0);
	initialize_stacks(argc, argv, &a, &b, &v_flag);
	choose_sorting(a, b, v_flag);
	clear_stack(a);
	clear_stack(b);
	return (0);
}
