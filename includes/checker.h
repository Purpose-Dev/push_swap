/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:25:51 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/26 11:28:47 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

int		handle_error_and_cleanup(t_stack *stack_a, t_stack *stack_b);
void	init_and_parse(const int argc, char **argv, t_stack **stack_a,
			t_stack *stack_b);

#endif // CHECKER_H
