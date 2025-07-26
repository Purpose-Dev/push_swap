/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_and_execute_utils_1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:17:03 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/26 12:27:19 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sorting.h"

static void	handle_rr_rotations(t_stack *a, t_stack *b,
		int *target_pos, int *b_pos)
{
	int	min_rotations;

	min_rotations = *target_pos;
	if (*b_pos < min_rotations)
		min_rotations = *b_pos;
	while (min_rotations-- > 0)
	{
		rr(a, b);
		(*target_pos)--;
		(*b_pos)--;
	}
}

static void	handle_rrr_rotations(t_stack *a, t_stack *b,
		int *target_pos, int *b_pos)
{
	int	min_rotations;
	int	a_size;
	int	b_size;

	a_size = stack_size(a);
	b_size = stack_size(b);
	min_rotations = a_size - *target_pos;
	if (b_size - *b_pos < min_rotations)
		min_rotations = b_size - *b_pos;
	while (min_rotations-- > 0)
	{
		rrr(a, b);
		(*target_pos)++;
		(*b_pos)++;
	}
}

static void	execute_same_direction_rotations(t_stack *a, t_stack *b,
		int *target_pos, int *b_pos)
{
	int	rotate_a_up;
	int	rotate_b_up;
	int	a_size;
	int	b_size;

	a_size = stack_size(a);
	b_size = stack_size(b);
	rotate_a_up = 0;
	rotate_b_up = 0;
	if (*target_pos <= a_size / 2)
		rotate_a_up = 1;
	if (*b_pos <= b_size / 2)
		rotate_b_up = 1;
	if (rotate_a_up && rotate_b_up)
		handle_rr_rotations(a, b, target_pos, b_pos);
	else if (!rotate_a_up && !rotate_b_up)
		handle_rrr_rotations(a, b, target_pos, b_pos);
}

static void	execute_remaining_rotations(t_stack *a, t_stack *b,
										int target_pos, int b_pos)
{
	const int	a_size = stack_size(a);
	const int	b_size = stack_size(b);

	if (b_pos <= b_size / 2)
	{
		while (b_pos-- > 0)
			rb(b);
	}
	else
	{
		while (b_pos++ < b_size)
			rrb(b);
	}
	if (target_pos <= a_size / 2)
	{
		while (target_pos-- > 0)
			ra(a);
	}
	else
	{
		while (target_pos++ < a_size)
			rra(a);
	}
}

void	execute_rotations(t_stack *a, t_stack *b, int target_pos, int b_pos)
{
	execute_same_direction_rotations(a, b, &target_pos, &b_pos);
	execute_remaining_rotations(a, b, target_pos, b_pos);
}
