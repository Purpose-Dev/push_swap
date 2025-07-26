/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:38:55 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/26 11:29:13 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libs/libft/includes/collections/lists/d/ft_dlist.h"
# include "../libs/libft/includes/io/ft_printf.h"

# define TRUE 1
# define FALSE 0

typedef struct s_element
{
	int	value;
	int	index;
}	t_element;

typedef t_dlist	t_stack;

t_stack		*init_stack(void);
void		push_stack(t_stack *stack, int value);
int			pop_stack(t_stack *stack);
void		clear_stack(t_stack *stack);
int			is_empty(t_stack *stack);
int			stack_size(t_stack *stack);

t_element	*create_element(int value, int index);
void		free_element(void *elem);

void		error_and_exit(const char *msg);

#endif // PUSH_SWAP_H
