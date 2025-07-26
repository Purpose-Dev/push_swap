/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:52:37 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/26 12:09:15 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sorting.h"

void	sa(t_stack *a)
{
	t_element	*first;
	t_element	*second;

	if (stack_size(a) < 2)
		return ;
	first = (t_element *)dlist_pop_front(a);
	second = (t_element *)dlist_pop_front(a);
	dlist_push_front(a, first);
	dlist_push_front(a, second);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	t_element	*first;
	t_element	*second;

	if (stack_size(b) < 2)
		return ;
	first = (t_element *)dlist_pop_front(b);
	second = (t_element *)dlist_pop_front(b);
	dlist_push_front(b, first);
	dlist_push_front(b, second);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	const int	can_swap_a = (stack_size(a) >= 2);
	const int	can_swap_b = (stack_size(b) >= 2);

	auto t_element * first_a, *second_a;
	auto t_element * first_b, *second_b;
	if (!can_swap_a && !can_swap_b)
		return ;
	if (can_swap_a)
	{
		first_a = (t_element *)dlist_pop_front(a);
		second_a = (t_element *)dlist_pop_front(a);
		dlist_push_front(a, first_a);
		dlist_push_front(a, second_a);
	}
	if (can_swap_b)
	{
		first_b = (t_element *)dlist_pop_front(b);
		second_b = (t_element *)dlist_pop_front(b);
		dlist_push_front(b, first_b);
		dlist_push_front(b, second_b);
	}
	ft_printf("ss\n");
}

void	pa(t_stack *a, t_stack *b)
{
	t_element	*elem;

	if (is_empty(b))
		return ;
	elem = (t_element *)dlist_pop_front(b);
	dlist_push_front(a, elem);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	t_element	*elem;

	if (is_empty(a))
		return ;
	elem = (t_element *)dlist_pop_front(a);
	dlist_push_front(b, elem);
	ft_printf("pb\n");
}
