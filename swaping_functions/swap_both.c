/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 09:13:17 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/10 11:30:36 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void	ss(t_node **stack_a, t_node **stack_b, char *operation)
{
	int	temp;
	int	temp2;

	if (protect(stack_a) && protect (stack_b))
	{
		temp = (*stack_a)->data;
		temp2 = (*stack_a)->next->data;
		(*stack_a)->data = temp2;
		(*stack_a)->next->data = temp;
		temp = (*stack_b)->data;
		temp2 = (*stack_b)->next->data;
		(*stack_b)->data = temp2;
		(*stack_b)->next->data = temp;
		write(1, operation, 2);
		write(1, "\n", 1);
	}
}
