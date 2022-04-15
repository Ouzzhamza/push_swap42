/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:47:59 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/06 17:06:06 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void	ft_lstadd_back(int data, t_node **lst, t_node *new)
{
	t_node	*last_node;

	if (*lst == NULL)
	{
		*lst = new;
		new->data = data;
		new->next = new;
		new->prev = new;
	}
	else
	{
		last_node = ft_lstlast(*lst);
		last_node->next = new;
		new->data = data;
		new->prev = last_node;
		new->next = NULL;
	}
}
