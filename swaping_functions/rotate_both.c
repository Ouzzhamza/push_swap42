/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotete_both.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:45:13 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/10 11:24:02 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void	rrr(t_node **stack_a, t_node **stack_b, char *operation)
{
	if (protect(stack_a) && protect(stack_b))
	{
		(*stack_a) = (*stack_a)->prev;
		(*stack_b) = (*stack_b)->prev;
		write(1, operation, 2);
		write(1, "\n", 1);
	}
}
