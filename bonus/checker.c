/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:28:37 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/08 06:55:52 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	get_instructions(&stack_a, &stack_b);
	if (sorted(&stack_a, ASCENDING, data->av_limit_number))
		write(1, "OK\n", 3);
	else if (!sorted(&stack_a, ASCENDING, data->av_limit_number))
		write(1, "KO\n", 3);
	free_all(&stack_a, &stack_b, data);
	return (0);
}
