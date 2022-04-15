/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:11:56 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/08 01:24:39 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>
# include	<fcntl.h>
# include	<stdbool.h>
# include	"../mandatory/push_swap.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define ERROR "Error\n"
# define ASCENDING 1
# define DESCENDING 0

char	*get_next_line(int fd);
t_node	*initiate_linked_list(int ac, char **av, t_node *stack_a, t_data *data);
void	get_instructions(t_node **stack_a, t_node **stack_b);

#endif