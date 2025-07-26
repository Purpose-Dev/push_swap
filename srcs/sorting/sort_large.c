/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:26:56 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/26 12:08:32 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sorting.h"

static void	calculate_best_move(t_stack *a, t_stack *b, int *best_pos_b,
		int *min_cost)
{
	t_dlist_node	*current_b;
	int				pos_b;
	t_element		*elem_b;
	int				target_pos_a;
	int				current_cost;

	current_b = b->head;
	pos_b = 0;
	*min_cost = INT_MAX;
	*best_pos_b = 0;
	while (current_b)
	{
		elem_b = (t_element *) current_b->data;
		target_pos_a = find_target_position(a, elem_b->value);
		current_cost = calculate_cost(a, b, target_pos_a, pos_b);
		if (current_cost < *min_cost)
		{
			*min_cost = current_cost;
			*best_pos_b = pos_b;
		}
		current_b = current_b->next;
		pos_b++;
	}
}

static void	find_min_position_and_value(const t_stack *a, int *min_pos_ptr,
		int *min_value_ptr)
{
	t_dlist_node	*current;
	int				pos;
	t_element		*elem;

	current = a->head;
	pos = 0;
	*min_value_ptr = INT_MAX;
	*min_pos_ptr = 0;
	while (current)
	{
		elem = (t_element *)current->data;
		if (elem->value < *min_value_ptr)
		{
			*min_value_ptr = elem->value;
			*min_pos_ptr = pos;
		}
		current = current->next;
		pos++;
	}
}

static void	final_rotation_a(t_stack *a)
{
	int	min_pos;
	int	min_value;
	int	size;

	find_min_position_and_value(a, &min_pos, &min_value);
	size = stack_size(a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a);
	}
	else
	{
		while (min_pos++ < size)
			rra(a);
	}
}

void	turk_sort(t_stack *a, t_stack *b)
{
	int			best_pos_b;
	int			min_cost;
	t_element	*best_elem_b;
	int			final_target_a;

	while (stack_size(a) > 3)
		pb(a, b);
	sort_three(a);
	while (!is_empty(b))
	{
		calculate_best_move(a, b, &best_pos_b, &min_cost);
		best_elem_b = (t_element *) dlist_get_at(b, best_pos_b);
		final_target_a = find_target_position(a, best_elem_b->value);
		execute_rotations(a, b, final_target_a, best_pos_b);
		pa(a, b);
	}
	final_rotation_a(a);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	int	size;

	if (is_sorted(a))
		return ;
	size = stack_size(a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else if (size <= 100)
		turk_sort(a, b);
	else
	{
		index_stack(a);
		turk_sort(a, b);
	}
}
