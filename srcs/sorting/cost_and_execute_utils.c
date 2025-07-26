/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_and_execute_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:45:43 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/26 12:25:20 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sorting.h"

typedef struct s_cost_norm
{
	int	cost_a;
	int	cost_b;
	int	target_pos_a;
	int	b_pos;
	int	a_size;
	int	b_size;
}	t_cn;

static int	get_rotation_cost(const int pos, const int size)
{
	int	cost;

	if (pos <= size / 2)
		cost = pos;
	else
		cost = size - pos;
	return (cost);
}

static int	get_total_rotation_cost(const t_cn *cn)
{
	int	same_direction;
	int	overlap;
	int	total_cost;

	same_direction = 0;
	if (cn->target_pos_a <= cn->a_size / 2 && cn->b_pos <= cn->b_size / 2)
		same_direction = 1;
	if (cn->target_pos_a > cn->a_size / 2 && cn->b_pos > cn->b_size / 2)
		same_direction = 1;
	if (same_direction)
	{
		overlap = cn->cost_a;
		if (cn->cost_b < overlap)
			overlap = cn->cost_b;
		total_cost = cn->cost_a + cn->cost_b - overlap;
	}
	else
		total_cost = cn->cost_a + cn->cost_b;
	return (total_cost);
}

int	calculate_cost(t_stack *a, t_stack *b, const int target_pos,
		const int b_pos)
{
	t_cn	cost_data;

	cost_data.a_size = stack_size(a);
	cost_data.b_size = stack_size(b);
	cost_data.cost_a = get_rotation_cost(target_pos, cost_data.a_size);
	cost_data.cost_b = get_rotation_cost(b_pos, cost_data.b_size);
	cost_data.target_pos_a = target_pos;
	cost_data.b_pos = b_pos;
	return (get_total_rotation_cost(&cost_data));
}
