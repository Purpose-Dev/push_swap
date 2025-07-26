/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:09:20 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/26 12:16:16 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/sorting.h"
#include "../libs/libft/includes/libft.h"

static int	execute_instruction(t_stack **stack_a, t_stack **stack_b,
		const char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		sa(*stack_a);
	else if (ft_strcmp(line, "sb") == 0)
		sb(*stack_b);
	else if (ft_strcmp(line, "ss") == 0)
		ss(*stack_a, *stack_b);
	else if (ft_strcmp(line, "pa") == 0)
		pa(*stack_a, *stack_b);
	else if (ft_strcmp(line, "pb") == 0)
		pb(*stack_a, *stack_b);
	else if (ft_strcmp(line, "ra") == 0)
		ra(*stack_a);
	else if (ft_strcmp(line, "rb") == 0)
		rb(*stack_b);
	else if (ft_strcmp(line, "rr") == 0)
		rr(*stack_a, *stack_b);
	else if (ft_strcmp(line, "rra") == 0)
		rra(*stack_a);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb(*stack_b);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(*stack_a, *stack_b);
	else
		return (0);
	return (1);
}

static int	is_stack_sorted(t_stack *stack)
{
	t_dlist_node	*node;
	t_element		*current;
	t_element		*next;

	if (!stack || is_empty(stack))
		return (1);
	node = stack->head;
	while (node && node->next)
	{
		current = (t_element *)node->data;
		next = (t_element *)node->next->data;
		if (current->value > next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

static int	process_line(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (line && ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	if (!execute_instruction(stack_a, stack_b, line))
	{
		free(line);
		return (0);
	}
	return (1);
}

static int	process_instructions(t_stack **stack_a, t_stack **stack_b)
{
	char		*line;
	size_t		n;
	ssize_t		result;
	t_ft_file	*stdin_stream;

	line = NULL;
	n = 0;
	stdin_stream = ft_stdin();
	result = ft_getline(&line, &n, stdin_stream);
	while (result > 0)
	{
		if (!process_line(stack_a, stack_b, line))
			return (0);
		free(line);
		line = NULL;
		n = 0;
		result = ft_getline(&line, &n, stdin_stream);
	}
	if (line)
		free(line);
	if (result == -1)
		return (0);
	return (1);
}

int	main(const int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	if (init_and_parse(argc, argv, &stack_a, &stack_b) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (!process_instructions(&stack_a, &stack_b))
		return (handle_error_and_cleanup(stack_a, stack_b));
	if (is_stack_sorted(stack_a) && is_empty(stack_b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	clear_stack(stack_a);
	clear_stack(stack_b);
	return (0);
}
