/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:32:56 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/06 17:06:24 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

int	ft_lstsize(t_node *stack)
{
	int		i;
	t_node	*new;

	new = stack;
	i = 1;
	if (!stack)
		return (0);
	while (new->next != stack)
	{
		i++;
		new = new->next;
	}
	return (i);
}
