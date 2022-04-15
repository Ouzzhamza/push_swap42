/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:48:36 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/10 11:24:54 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* **************************************************** */
/*                     🆂🅾🆁🆃🅸🅽🅶_3                   */
/* **************************************************** */

void	sorting_3(t_node **stack_a, t_node **stack_b, int len)
{
	while (len || ((*stack_a)->data > (*stack_a)->next->data && \
	(*stack_a)->next->data > (*stack_a)->next->next->data))
	{
		if (len == 1 && (*stack_a)->data > (*stack_a)->next->data)
			swap_first_two(stack_a, "sa", 1);
		else if (len == 1 || (len >= 2 && (*stack_b)->data > \
		((*stack_b)->next->data)) || (len == 3 && (*stack_b)->data > \
		(*stack_b)->next->next->data))
		{
			push_to(stack_b, stack_a, "pa", 1);
			len--;
		}
		else
			benefits(stack_a, stack_b, 2);
	}
}

/* **************************************************** */
/*               🅾🅿🆃🅸🅼🅸🆂🅰🆃🅸🅾🅽_🅱                 */
/* **************************************************** */

int	optimisation_b(t_node **stack_b, t_node **stack_a, int len)
{
	if (len == 1)
		push_to(stack_b, stack_a, "pa", 1);
	else if (len == 2)
	{
		if ((*stack_b)->data < ((*stack_b)->next->data))
			benefits(stack_a, stack_b, 2);
		push_to(stack_b, stack_a, "pa", 1);
		push_to(stack_b, stack_a, "pa", 1);
	}
	else if (len == 3)
		sorting_3(stack_a, stack_b, len);
	return (1);
}

/* **************************************************** */
/*                   🅿🆄🆂🅷_🆃🅾_🅰                     */
/* **************************************************** */

int	push_to_a(t_node **stack_a, t_node **stack_b, t_data *data, int len)
{
	int	nb_elm;
	int	pushed_under;

	pushed_under = 0;
	nb_elm = len;
	if (sorted(stack_b, DESCENDING, len))
		while (len--)
			push_to(stack_b, stack_a, "pa", 1);
	if (len <= 3)
		return (optimisation_b(stack_b, stack_a, len));
	pivot_chose((*stack_b), data, len);
	while (len != nb_elm / 2)
	{
		if ((*stack_b)->data >= data->pivot && (len--))
			push_to(stack_b, stack_a, "pa", 1);
		else if (++pushed_under)
			first_to_end(stack_b, "rb", 1);
	}
	data->av_limit_number = ft_lstsize((*stack_b));
	while (nb_elm / 2 != data->av_limit_number && pushed_under--)
		benefits(stack_a, stack_b, 4);
	push_to_b(stack_a, stack_b, data, nb_elm / 2 + nb_elm % 2);
	push_to_a(stack_a, stack_b, data, nb_elm / 2);
	return (0);
}
