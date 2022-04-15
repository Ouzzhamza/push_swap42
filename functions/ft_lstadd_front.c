/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:48:40 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/06 17:06:11 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void	ft_lstadd_front(t_node *new_node, t_node **stack)
{
	t_node	*last;

	if (!(*stack))
	{
		(*stack) = new_node;
		new_node->next = (*stack);
		new_node->prev = (*stack);
	}
	else
	{
		last = (*stack)->prev;
		new_node->next = (*stack);
		new_node->prev = last;
		last->next = new_node;
		(*stack)->prev = new_node;
		(*stack) = new_node;
	}
}
