/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:21:20 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/17 18:46:57 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../bonus/checker.h"

void	re_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->holder[i])
		i++;
	if (i == 0)
		push_errors();
	if (i == 1)
		exit(0);
	i = 0;
	while (data->holder[i])
	{
		j = i + 1;
		while (data->holder[j])
		{
			if (ft_atoi(data->holder[i]) == ft_atoi(data->holder[j]))
				push_errors();
			j++;
		}
		i++;
	}
}

/* **************************************************** */
/*                 🅲🅷🅴🅰🅲🅺_🅳🅾🆄🅱🅻🅴                */
/* **************************************************** */
void	cheack_double(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	ft_atoi(av[1]);
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				push_errors();
			j++;
		}
		i++;
	}
}

/* **************************************************** */
/*              🅷🅰🅽🅳🅻🅴_🅰🆁🅶🆄🅼🅴🅽🆃🆂              */
/* **************************************************** */

void	handle_arguments(int ac, char **av, t_data *data)
{
	int		i;
	char	*temp;

	temp = NULL;
	i = 0;
	while (i++ < ac - 1)
	{
		temp = ft_strjoin(temp, av[i]);
		if (i < ac - 1)
			temp = ft_strjoin(temp, " ");
	}
	i = 0;
	data->holder = ft_split(temp, ' ');
	free(temp);
	while (++i < ac)
	{
		if (data->holder == NULL || av[i][0] == '\0')
			push_errors();
	}
	re_check(data);
}

/* **************************************************** */
/*          🅸🅽🅸🆃🅸🅰🆃🅴_🅻🅸🅽🅺🅴🅳_🅻🅸🆂🆃            */
/* **************************************************** */

t_node	*initiate_linked_list(int ac, char **av, t_node *stack_a, t_data *data)
{
	t_node	*node;
	t_node	*new_node;
	int		i;

	node = NULL;
	i = 1;
	cheack_double(ac, av);
	handle_arguments(ac, av, data);
	node = ft_lstnew(ft_atoi(data->holder[0]));
	free(data->holder[0]);
	stack_a = node;
	while (data->holder[i])
	{
		new_node = (t_node *)malloc(sizeof(t_node));
		ft_lstadd_back(ft_atoi(data->holder[i]), &stack_a, new_node);
		free(data->holder[i]);
		i++;
	}
	free(data->holder[i]);
	free(data->holder);
	new_node->next = stack_a;
	stack_a->prev = new_node;
	return (stack_a);
}
