/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:51:54 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/05/16 12:32:06 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

static int	cmp_int(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

static int	*stack_to_array(t_stack *stack)
{
	int		i;
	int		*arr;
	t_node	*current;

	arr = malloc(sizeof(int) * stack->size);
	if (!arr)
		error_and_exit("Memory allocation failed");
	i = 0;
	current = stack->top;
	while (i < stack->size)
	{
		arr[i] = current->value;
		current = current->next;
		i++;
	}
	return (arr);
}

void index_stack(t_stack *stack)
{
	int	*arr;
	int	*sorted;

	arr = stack_to_array(stack);
	sorted = malloc(sizeof(int) * stack->size);
	if (!sorted)
	{
		free(arr);
		error_and_exit("Memory allocation failed");
	}
	for (int i = 0; i < stack->size; i++)
		sorted[i] = arr[i];
	qsort(sorted, stack->size, sizeof(int), cmp_int);
	t_node *current = stack->top;
	while (current)
	{
		int *pos = bsearch(&current->value, sorted, stack->size, sizeof(int), cmp_int);
		if (pos)
			current->value = pos - sorted;
		current = current->next;
	}
	free(arr);
	free(sorted);
}