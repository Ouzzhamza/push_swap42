/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_to_first.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:50:53 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/07 14:23:08 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"
#include "../bonus/checker.h"

void	end_to_first(t_node **node, char *operation, int type)
{
	if (protect(node) == true)
	{
		(*node) = (*node)->prev;
		if (type == 1)
		{
			write(1, operation, 3);
			write(1, "\n", 1);
		}
	}
}
