/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_chose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:02:40 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/10 08:53:58 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* **************************************************** */
/*                  🅿🅸🆅🅾🆃_🅲🅷🅾🆂🅴                  */
/* **************************************************** */

void	pivot_chose(t_node *stack, t_data *data, int len)
{
	int		i;
	int		devide;

	data->limiter1 = 0;
	devide = 2;
	data->pointer1 = stack;
	while (data->limiter1 < len)
	{
		i = 0;
		data->limiter2 = 0;
		data->pointer2 = stack;
		while (data->limiter2 < len)
		{
			if (data->pointer2->data < data->pointer1->data && i++)
				if (i > len / devide)
					break ;
			data->pointer2 = data->pointer2->next;
			data->limiter2++;
		}
		if (i == len / devide)
			break ;
		data->pointer1 = data->pointer1->next;
		data->limiter1++;
	}
	data->pivot = data->pointer1->data;
}
