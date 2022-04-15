/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_first_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:41:53 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/09 22:12:29 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"
#include "../bonus/checker.h"

void	swap_first_two(t_node **head, char *operation, int type)
{
	int	temp;
	int	temp2;

	if (protect(head) == true)
	{
		temp = (*head)->data;
		temp2 = (*head)->next->data;
		(*head)->data = temp2;
		(*head)->next->data = temp;
		if (type == 1)
		{
			write(1, operation, 2);
			write(1, "\n", 1);
		}
	}
}
