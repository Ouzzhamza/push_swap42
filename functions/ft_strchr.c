/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:40:54 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/06 17:06:41 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	a;
	char	*b;

	b = ((char *) s);
	i = 0;
	a = (char) c;
	if (c == 0)
		return (b + ft_strlen(b));
	while (b[i])
	{
		if (b[i] == a)
			return (&b[i]);
		i++;
	}
	return (NULL);
}
