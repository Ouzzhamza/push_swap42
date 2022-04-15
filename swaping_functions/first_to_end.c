/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_to_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:13:12 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/07 14:22:57 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"
#include "../bonus/checker.h"

void	first_to_end(t_node **node, char *operation, int type)
{
	if (protect(node) == true)
	{
		(*node) = (*node)->next;
		if (type == 1)
		{
			write(1, operation, 2);
			write(1, "\n", 1);
		}
	}
}
