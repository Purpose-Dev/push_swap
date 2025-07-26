/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:32:51 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/26 11:33:23 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	stack_size(t_stack *stack)
{
	return ((int)dlist_size(stack));
}

t_element	*create_element(const int value, const int index)
{
	t_element	*elem;

	elem = malloc(sizeof(t_element));
	if (!elem)
		return (NULL);
	elem->value = value;
	elem->index = index;
	return (elem);
}
