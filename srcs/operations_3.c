/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:56:16 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/26 12:11:57 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sorting.h"

void	rrb(t_stack *b)
{
	t_element	*elem;

	if (stack_size(b) < 2)
		return ;
	elem = (t_element *)dlist_pop_back(b);
	dlist_push_front(b, elem);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	const int	can_rotate_a = (stack_size(a) >= 2);
	const int	can_rotate_b = (stack_size(b) >= 2);
	t_element	*elem_a;
	t_element	*elem_b;

	if (!can_rotate_a && !can_rotate_b)
		return ;
	if (can_rotate_a)
	{
		elem_a = (t_element *)dlist_pop_back(a);
		dlist_push_front(a, elem_a);
	}
	if (can_rotate_b)
	{
		elem_b = (t_element *)dlist_pop_back(b);
		dlist_push_front(b, elem_b);
	}
	ft_printf("rrr\n");
}
