/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:52:08 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/26 11:41:03 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sorting.h"

void	sort_two(t_stack *a)
{
	t_element	*first;
	t_element	*second;

	if (stack_size(a) != 2)
		return ;
	first = get_top(a);
	second = (t_element *)dlist_get_at(a, 1);
	if (first->value > second->value)
		sa(a);
}

void	sort_three(t_stack *a)
{
	if (stack_size(a) != 3)
		return ;
	auto t_element * first = get_top(a);
	auto t_element * second = (t_element *)dlist_get_at(a, 1);
	auto t_element * third = (t_element *)dlist_get_at(a, 2);
	if (first->value > second->value && second->value > third->value)
	{
		sa(a);
		rra(a);
	}
	else if (first->value > third->value && third->value > second->value)
		ra(a);
	else if (second->value > first->value && first->value > third->value)
		rra(a);
	else if (second->value > third->value && third->value > first->value)
	{
		sa(a);
		ra(a);
	}
	else if (third->value > first->value && first->value > second->value)
		sa(a);
}

static t_element	*get_min_element(const t_stack *stack)
{
	t_dlist_node	*node;
	t_element		*min_elem;
	t_element		*elem;

	node = stack->head;
	min_elem = (t_element *)node->data;
	while (node)
	{
		elem = (t_element *)node->data;
		if (elem->value < min_elem->value)
			min_elem = elem;
		node = node->next;
	}
	return (min_elem);
}

static int	find_min_position(const t_stack *stack)
{
	t_dlist_node	*node;
	t_element		*min_elem;
	t_element		*elem;
	int				pos;
	int				min_pos;

	node = stack->head;
	min_elem = get_min_element(stack);
	pos = 0;
	min_pos = 0;
	while (node)
	{
		elem = (t_element *)node->data;
		if (elem->value == min_elem->value)
		{
			min_pos = pos;
			break ;
		}
		node = node->next;
		pos++;
	}
	return (min_pos);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min_pos;
	int	size;

	size = stack_size(a);
	while (size > 3)
	{
		min_pos = find_min_position(a);
		while (min_pos > 0 && min_pos <= size / 2)
		{
			ra(a);
			min_pos--;
		}
		while (min_pos < size && min_pos > size / 2)
		{
			rra(a);
			min_pos++;
		}
		pb(a, b);
		size--;
	}
	sort_three(a);
	while (!is_empty(b))
	{
		pa(a, b);
	}
}
