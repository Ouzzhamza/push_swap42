/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:59:28 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/07 15:21:05 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void	verify(long int res, int signe, const char *str)
{
	long int	number;
	int			i;
	int			n;
	int			c;

	number = res * signe;
	i = 0;
	c = 0;
	n = number;
	if (number > MAX_INT || number < MIN_INT)
		push_errors();
	while (n != 0)
	{
		n = n / 10;
		c++;
	}
	if (c > 10 && (str[0] != '-' && str[0] != '+'))
		push_errors();
	if ((str[0] == '-' || str[0] == '+') && str[1] == '\0')
		push_errors();
}

int	ft_atoi(const char *str)
{
	int			i;
	long int	res;
	int			signe;

	i = 0;
	res = 0;
	signe = 1;
	while (str[i] == ' ' || str[i] == '\f' || \
	str[i] == '\n' || str[i] == '\r' || \
	str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '\0')
		push_errors();
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	if ((str[i] < '0' || str[i] > '9') && str[i] != '\0' && str[i] != 32)
		push_errors();
	verify(res, signe, str);
	return (res * signe);
}
