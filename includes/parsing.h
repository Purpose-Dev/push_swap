/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:46:16 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/26 11:27:34 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "limits.h"
# include "push_swap.h"
# include "../libs/libft/includes/core/string/ft_string.h"

int		check_arguments(int argc, char **argv, int *v_flag);
t_stack	*parse_input(int argc, char **argv);

#endif // PARSING_H
