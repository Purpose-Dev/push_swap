/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:51:36 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/26 12:36:38 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/comparator.h"

int	ft_compare(const int a, const int b)
{
	if (a > b)
		return (1);
	if (a < b)
		return (-1);
	return (0);
}
