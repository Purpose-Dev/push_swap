/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:52:47 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/26 12:10:42 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sorting.h"

void	ra(t_stack *a)
{
	t_element	*elem;

	if (stack_size(a) < 2)
		return ;
	elem = (t_element *)dlist_pop_front(a);
	dlist_push_back(a, elem);
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	t_element	*elem;

	if (stack_size(b) < 2)
		return ;
	elem = (t_element *)dlist_pop_front(b);
	dlist_push_back(b, elem);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	const int	can_rotate_a = (stack_size(a) >= 2);
	const int	can_rotate_b = (stack_size(b) >= 2);
	t_element	*elem_a;
	t_element	*elem_b;

	if (!can_rotate_a && !can_rotate_b)
		return ;
	if (can_rotate_a)
	{
		elem_a = (t_element *)dlist_pop_front(a);
		dlist_push_back(a, elem_a);
	}
	if (can_rotate_b)
	{
		elem_b = (t_element *)dlist_pop_front(b);
		dlist_push_back(b, elem_b);
	}
	ft_printf("rr\n");
}

void	rra(t_stack *a)
{
	t_element	*elem;

	if (stack_size(a) < 2)
		return ;
	elem = (t_element *)dlist_pop_back(a);
	dlist_push_front(a, elem);
	ft_printf("rra\n");
}
