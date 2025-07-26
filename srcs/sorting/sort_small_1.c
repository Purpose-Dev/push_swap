/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:52:08 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/26 11:37:22 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sorting.h"

int	is_sorted(t_stack *stack)
{
	t_dlist_node	*node;
	t_element		*current;
	t_element		*next;

	if (stack_size(stack) <= 1)
		return (TRUE);
	node = stack->head;
	while (node && node->next)
	{
		current = (t_element *)node->data;
		next = (t_element *)node->next->data;
		if (current->value > next->value)
			return (FALSE);
		node = node->next;
	}
	return (TRUE);
}

t_element	*get_top(t_stack *stack)
{
	if (is_empty(stack))
		return (NULL);
	return ((t_element *)dlist_get_front(stack));
}

t_element	*get_bottom(t_stack *stack)
{
	if (is_empty(stack))
		return (NULL);
	return ((t_element *)dlist_get_back(stack));
}
