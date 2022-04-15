/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:59:28 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/15 22:41:27 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void	verify(long long int res, int signe, const char *str)
{
	long long int	number;
	int			i;
	int			n;
	int			c;

	number = res * signe;
	i = 0;
	c = 0;
	n = number;
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

long long int	ft_atoi(const char *str)
{
	int			i;
	long long int	res;
	int			signe;

	i = 0;
	res = 0;
	signe = 1;
	while (str[i] == ' ' || str[i] == '\f' || \
	str[i] == '\n' || str[i] == '\r' || \
	str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '\0' || ((str[i] != '-' && str[i] != '+') && str[i + 1] == 32))
		push_errors();
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > MAX_INT || res < MIN_INT)
		push_errors();
		res = res * 10 + str[i++] - '0';
	}
	if ((str[i] < '0' || str[i] > '9') && str[i] != '\0' && str[i] != 32)
		push_errors();
	verify(res, signe, str);
	return (res * signe);
}
