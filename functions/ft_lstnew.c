/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:19:38 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/06 17:06:19 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

t_node	*ft_lstnew(int data)
{
	t_node	*ptr;

	ptr = (t_node *)malloc (sizeof(t_node));
	if (ptr == NULL)
		return (NULL);
	ptr ->data = data;
	ptr ->next = NULL;
	ptr->prev = ptr;
	return (ptr);
}
