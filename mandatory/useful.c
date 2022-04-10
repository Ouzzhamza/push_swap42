/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:00:54 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/09 22:12:09 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

/* **************************************************** */
/*                     🅿🆁🅾🆃🅴🅲🆃                     */
/* **************************************************** */

int	protect(t_node **stack)
{
	t_node	*head;
	bool	count;

	count = true;
	head = (*stack);
	if ((*stack) == NULL || head->next == (*stack))
		count = false;
	return (count);
}
/* **************************************************** */
/*                    🅵🆁🅴🅴_🅰🅻🅻
                        */
/* **************************************************** */

void	free_all(t_node **stack_a, t_node **stack_b, t_data *data)
{
	t_node	*pointer;
	t_node	*hold;

	free(data);
	pointer = (*stack_a);
	while (pointer->next != (*stack_a))
	{
		pointer = pointer->next;
		hold = (*stack_a)->next;
		(*stack_a)->prev->next = (*stack_a)->next;
		(*stack_a)->next->prev = (*stack_a)->prev;
		free ((*stack_a));
		(*stack_a) = hold;
	}
	free(*stack_a);
	free(*stack_b);
}

/* **************************************************** */
/*                     🅿🆄🆂🅷_🅴🆁🆁🅾🆁🆂               */
/* **************************************************** */

void	push_errors(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

/* **************************************************** */
/*                    🆂🅾🆁🆃🅴🅳                        */
/* **************************************************** */

int	sorted(t_node **stack, int order, int len)
{
	t_node	*pointer;
	int		i;

	pointer = (*stack);
	i = 0;
	while (i++ < len - 1)
	{
		if ((order == ASCENDING && pointer->data > pointer->next->data)
			|| (order == DESCENDING && pointer->data < \
			pointer->next->data))
			return (0);
		pointer = pointer->next;
	}
	return (1);
}
