/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:51:54 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/26 12:35:58 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sorting.h"

static int	partition(int *values, int low, int high);

static void	quick_sort_values(int *values, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(values, low, high);
		quick_sort_values(values, low, pivot - 1);
		quick_sort_values(values, pivot + 1, high);
	}
}

static int	partition(int *values, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	pivot = values[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (values[j] < pivot)
		{
			i++;
			temp = values[i];
			values[i] = values[j];
			values[j] = temp;
		}
		j++;
	}
	temp = values[i + 1];
	values[i + 1] = values[high];
	values[high] = temp;
	return (i + 1);
}

static int	find_index_of_value(const int *sorted_values, const int size,
		const int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted_values[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

static int	*extract_values_from_stack(t_stack *stack, int size)
{
	int				*values;
	t_dlist_node	*node;
	int				i;
	t_element		*elem;

	values = malloc(sizeof(int) * size);
	if (!values)
		error_and_exit("Error");
	node = stack->head;
	i = 0;
	while (node)
	{
		elem = (t_element *)node->data;
		values[i] = elem->value;
		node = node->next;
		i++;
	}
	return (values);
}

void	index_stack(t_stack *stack)
{
	int				size;
	int				*values;
	t_dlist_node	*node;
	t_element		*elem;

	size = stack_size(stack);
	if (size == 0)
		return ;
	values = extract_values_from_stack(stack, size);
	quick_sort_values(values, 0, size - 1);
	node = stack->head;
	while (node)
	{
		elem = (t_element *)node->data;
		elem->index = find_index_of_value(values, size, elem->value);
		node = node->next;
	}
	free(values);
}
