/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:52:25 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/06 17:06:02 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void	ft_index_back(int integer, t_data *data)
{
	t_index	*node;
	t_index	*last_node;

	node = (t_index *)malloc (sizeof(t_index));
	if (node == NULL)
		return ;
	last_node = data->index;
	node->integer = integer;
	node->next = NULL;
	if (!data->index)
		data->index = node;
	else
	{
		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}
		last_node->next = node;
	}
}
