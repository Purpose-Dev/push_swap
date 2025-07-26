/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_position_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:45:34 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/26 13:17:23 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sorting.h"

static int	find_greater_target(t_stack *a, const int value)
{
	t_dlist_node	*current;
	int				pos;
	int				target_pos;
	int				min_greater_value;
	t_element		*elem;

	current = a->head;
	target_pos = -1;
	min_greater_value = INT_MAX;
	pos = 0;
	while (current)
	{
		elem = (t_element *)current->data;
		if (elem->value > value && elem->value < min_greater_value)
		{
			min_greater_value = elem->value;
			target_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (target_pos);
}

static int	find_min_value_target(const t_stack *a)
{
	t_dlist_node	*current;
	int				pos;
	int				target_pos;
	int				min_value;
	t_element		*elem;

	current = a->head;
	pos = 0;
	target_pos = 0;
	min_value = INT_MAX;
	while (current)
	{
		elem = (t_element *) current->data;
		if (elem->value < min_value)
		{
			min_value = elem->value;
			target_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (target_pos);
}

int	find_target_position(t_stack *a, const int value)
{
	int			target_pos_greater;

	target_pos_greater = find_greater_target(a, value);
	if (target_pos_greater != -1)
		return (target_pos_greater);
	return (find_min_value_target(a));
}
