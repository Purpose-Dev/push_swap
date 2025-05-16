/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:52:47 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/05/16 17:38:12 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "sorting.h"

void	ra(t_stack *a)
{
	int		first;
	t_stack	*temp;

	if (a->size < 2)
		return ;
	first = pop(a);
	temp = init_stack();
	while (a->size > 0)
		push(temp, pop(a));
	push(a, first);
	while (temp->size > 0)
		push(a, pop(temp));
	clear_stack(temp);
	printf("ra\n");
}

void	rb(t_stack *b)
{
	ra(b);
	printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	printf("rr\n");
}

void	rra(t_stack *a)
{
	t_stack	*temp;
	int		last;

	if (a->size < 2)
		return ;
	temp = init_stack();
	while (a->size > 1)
		push(temp, pop(a));
	last = pop(a);
	while (temp->size > 0)
		push(a, pop(temp));
	push(a, last);
	clear_stack(temp);
	printf("rra\n");
}
