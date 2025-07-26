/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:47:54 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/26 11:59:17 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include <limits.h>
# include "push_swap.h"

void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);

void		sort_stack(t_stack *a, t_stack *b);
void		index_stack(t_stack *stack);

void		sort_two(t_stack *a);
void		sort_three(t_stack *a);
void		sort_five(t_stack *a, t_stack *b);
void		turk_sort(t_stack *a, t_stack *b);

int			is_sorted(t_stack *stack);
t_element	*get_top(t_stack *stack);
t_element	*get_bottom(t_stack *stack);

int			find_target_position(t_stack *a, int value);
int			calculate_cost(t_stack *a, t_stack *b, int target_pos, int b_pos);
void		execute_rotations(t_stack *a, t_stack *b, int target_pos,
				int b_pos);

#endif // SORTING_H
