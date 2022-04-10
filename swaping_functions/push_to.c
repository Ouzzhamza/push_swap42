/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:28:23 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/08 22:55:37 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"
#include "../bonus/checker.h"

/* **************************************************** */
/*                   🅳🅴🅻🅴🆃_🅽🅾🅳🅴                   */
/* **************************************************** */

void	delete_node(t_node **stack)
{
	t_node	*ptr;

	ptr = (*stack);
	if ((*stack) == (*stack)->next)
		(*stack) = NULL;
	else
	{
		(*stack)->prev->next = (*stack)->next;
		(*stack)->next->prev = (*stack)->prev;
		(*stack) = (*stack)->next;
	}
	free(ptr);
}
/* **************************************************** */
/*           🅿🆄🆂🅷_🆃🅾_🅾🆃🅷🅴🆁_🅻🅸🆂🆃               */
/* **************************************************** */

void	push_to(t_node **stack_from, t_node **stack_to, char *operation, \
		int type)
{
	t_node	*save;

	if (stack_from != NULL)
	{
		save = ft_lstnew((*stack_from)->data);
		delete_node(stack_from);
		ft_lstadd_front(save, stack_to);
		if (type == 1)
		{
			write(1, operation, 2);
			write(1, "\n", 1);
		}
	}
}
