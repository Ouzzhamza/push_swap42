/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:59:14 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/15 22:23:07 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* **************************************************** */
/*                    🆃🅷🅴 🅼🅰🅸🅽                      */
/* **************************************************** */

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	stack_a = initiate_linked_list(ac, av, stack_a, data);
	data->av_limit_number = ft_lstsize(stack_a);
	if (sorted(&stack_a, ASCENDING, data->av_limit_number))
		return (0);
	push_to_b(&stack_a, &stack_b, data, data->av_limit_number);
	free_all(&stack_a, &stack_b, data);
	return (0);
}
