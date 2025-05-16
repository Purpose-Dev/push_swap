/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:51:20 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/05/16 11:09:29 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		error_and_exit("Memory allocation failed");
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		error_and_exit("Memory allocation failed");
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

int	pop(t_stack *stack)
{
	int	value;

	if (stack->size == 0)
		error_and_exit("Pop from empty stack");
	t_node	*node = stack->top;
	value = node->value;
	stack->top = node->next;
	free(node);
	stack->size--;
	return (value);
}

void clear_stack(t_stack *stack)
{
	while (stack->size > 0)
		pop(stack);
	free(stack);
}

void	error_and_exit(const char *msg)
{
	write(2, msg, strlen(msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
