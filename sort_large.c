/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:52:21 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/05/16 12:15:37 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

static int	get_max_bits(t_stack *stack)
{
	int		max;
	t_node	*current;
	int		bits;

	max = 0;
	current = stack->top;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	max_bits;
	int	size;
	int	value;

	i = 0;
	max_bits = get_max_bits(a);
	while (i < max_bits)
	{
		size = a->size;
		j = 0;
		while (j < size)
		{
			value = a->top->value;
			if ((value >> i) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (b->size > 0)
			pa(a, b);
	}
}

void	sort_large(t_stack *a, t_stack *b, int argc)
{
	index_stack(a);
	radix_sort(a, b);
}
