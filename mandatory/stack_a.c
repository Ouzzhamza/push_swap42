/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:42:22 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/10 10:24:22 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

/* **************************************************** */
/*                       🆂🅾🆁🆃_3                      */
/* **************************************************** */

void	sort_3(t_node **stack_a, t_node **stack_b, int len)
{
	while (len != 3 || !((*stack_a)->data < (*stack_a)->next->data \
		&& (*stack_a)->next->data < (*stack_a)->next->next->data))
	{
		if (len == 3 && (*stack_a)->data > (*stack_a)->next->data && \
		(*stack_a)->next->next->data)
			swap_first_two(stack_a, "sa", 1);
		else if (len == 3 && !((*stack_a)->next->next->data > \
		(*stack_a)->data && (*stack_a)->next->next->data > \
		(*stack_a)->next->data))
		{
			push_to(stack_a, stack_b, "pb", 1);
			len--;
		}
		else if ((*stack_a)->data > (*stack_a)->next->data)
			swap_first_two(stack_a, "sa", 1);
		else if (len++)
			push_to(stack_b, stack_a, "pa", 1);
	}
}

/* **************************************************** */
/*                    🆂🅾🆁🆃_🅱🅰🆂🅴_3                  */
/* **************************************************** */

void	sort_base_3(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a)->data < (*stack_a)->next->data && \
	(*stack_a)->data < (*stack_a)->next->next->data)
	{
		if ((*stack_a)->next->data > (*stack_a)->next->next->data)
		{
			end_to_first(stack_a, "rra", 1);
			benefits(stack_a, stack_b, 1);
		}
	}
	else if ((*stack_a)->data > (*stack_a)->next->data && \
	(*stack_a)->data > (*stack_a)->next->next->data)
	{
		if ((*stack_a)->next->data < (*stack_a)->next->next->data)
			first_to_end(stack_a, "ra", 1);
		else
		{
			benefits(stack_a, stack_b, 1);
			end_to_first(stack_a, "rra", 1);
		}
	}
	if ((*stack_a)->next->data < (*stack_a)->next->next->data)
		benefits(stack_a, stack_b, 1);
	else
		end_to_first(stack_a, "rra", 1);
}

/* **************************************************** */
/*               🅾🅿🆃🅸🅼🅸🆂🅰🆃🅸🅾🅽                   */
/* **************************************************** */

void	optimisation(t_node **stack_a, t_node **stack_b, t_data *data, int len)
{
	if (len == 3 && data->av_limit_number == 3)
		sort_base_3(stack_a, stack_b);
	else if (len == 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			benefits(stack_a, stack_b, 1);
	}
	else if (len == 3)
		sort_3(stack_a, stack_b, len);
}

/* **************************************************** */
/*                🆅🅴🆁🅸🅵🅸🅲🅰🆃🅸🅾🅽                  */
/* **************************************************** */

int	verification(t_node **stack_a, t_node **stack_b, t_data *data, int len)
{
	if (sorted(stack_a, ASCENDING, len))
		return (1);
	if (len <= 3)
	{
		optimisation(stack_a, stack_b, data, len);
		return (1);
	}
	return (0);
}

/* **************************************************** */
/*                   🅿🆄🆂🅷_🆃🅾_🅱                     */
/* **************************************************** */

int	push_to_b(t_node **stack_a, t_node **stack_b, t_data *data, int len)
{
	int	nb_elm;
	int	pushed_under;

	pushed_under = 0;
	nb_elm = len;
	data->av_limit_number = ft_lstsize((*stack_a));
	if (verification(stack_a, stack_b, data, len))
		return (1);
	pivot_chose((*stack_a), data, len);
	while (len != nb_elm / 2 + nb_elm % 2)
	{
		if ((*stack_a)->data < data->pivot && (len--))
			push_to(stack_a, stack_b, "pb", 1);
		else if (++pushed_under)
			first_to_end(stack_a, "ra", 1);
	}
	data->av_limit_number = ft_lstsize((*stack_a));
	while (nb_elm / 2 + nb_elm % 2 != data->av_limit_number && pushed_under--)
		end_to_first(stack_a, "rra", 1);
	push_to_b(stack_a, stack_b, data, nb_elm / 2 + nb_elm % 2);
	push_to_a(stack_a, stack_b, data, nb_elm / 2);
	return (0);
}
