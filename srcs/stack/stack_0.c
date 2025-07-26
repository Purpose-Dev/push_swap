/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:28:14 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/26 11:33:48 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*init_stack(void)
{
	return (dlist_create());
}

void	push_stack(t_stack *stack, const int value)
{
	t_element	*elem;

	elem = create_element(value, -1);
	if (!elem)
		error_and_exit("Error");
	if (dlist_push_front(stack, elem) == 0)
	{
		free_element(elem);
		error_and_exit("Error");
	}
}

int	pop_stack(t_stack *stack)
{
	t_element	*elem;
	int			value;

	if (is_empty(stack))
		return (0);
	elem = (t_element *)dlist_pop_front(stack);
	value = elem->value;
	free_element(elem);
	return (value);
}

void	clear_stack(t_stack *stack)
{
	if (stack)
		dlist_destroy(stack, free_element);
}

int	is_empty(t_stack *stack)
{
	return (dlist_is_empty(stack));
}
