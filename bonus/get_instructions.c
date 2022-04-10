/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:02:51 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/10 14:12:59 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../mandatory/push_swap.h"

void	swap_two(t_node **stack_a, t_node **stack_b)
{
	(void)(stack_b);
	swap_first_two(stack_a, "sa", 0);
	swap_first_two(stack_b, "sb", 0);
}

void	rotate_two(t_node **stack_a, t_node **stack_b)
{
	first_to_end(stack_a, "ra", 0);
	first_to_end(stack_b, "rb", 0);
}

void	re_rotete_two(t_node **stack_a, t_node **stack_b)
{
	first_to_end(stack_a, "rra", 0);
	end_to_first(stack_b, "rrb", 0);
}

void	others(char *buff, t_node **stack_a, t_node **stack_b)
{
	if (!ft_strncmp(buff, "pa\n"))
		push_to(stack_b, stack_a, "pa", 0);
	else if (!ft_strncmp(buff, "ra\n"))
		first_to_end(stack_a, "ra", 0);
	else if (!ft_strncmp(buff, "rb\n"))
		first_to_end(stack_b, "rb", 0);
	else if (!ft_strncmp(buff, "rra\n"))
		end_to_first(stack_a, "rra", 0);
	else if (!ft_strncmp(buff, "rrb\n"))
		end_to_first(stack_b, "rrb", 0);
	else
		push_errors();
	free(buff);
}

void	get_instructions(t_node **stack_a, t_node **stack_b)
{
	char	*buff;

	buff = get_next_line(0);
	while (buff)
	{
		if (!ft_strncmp(buff, "sa\n"))
			swap_first_two(stack_a, "sa", 0);
		else if (!ft_strncmp(buff, "sb\n"))
			swap_first_two(stack_b, "sb", 0);
		else if (!ft_strncmp(buff, "ss\n"))
			swap_two(stack_a, stack_b);
		else if (!ft_strncmp(buff, "rr\n"))
			rotate_two(stack_a, stack_b);
		else if (!ft_strncmp(buff, "rrr\n"))
			re_rotete_two(stack_a, stack_b);
		else if (!ft_strncmp(buff, "pb\n") && (*stack_a) != (*stack_a)->next)
			push_to(stack_a, stack_b, "pb", 0);
		else
			others(buff, stack_a, stack_b);
		buff = get_next_line(0);
	}
}
