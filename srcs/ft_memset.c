/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:55:01 by tle-dref          #+#    #+#             */
/*   Updated: 2024/10/14 20:55:01 by tle-dref         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	val;

	i = 0;
	p = s;
	val = (unsigned char)c;
	while (i < n)
	{
		p[i] = val;
		i++;
	}
	return (s);
}

/*#include <stdio.h>
int	main(void)
{
	char str[10] = "Bonjour";

	printf("Avant memset: %s\n", str);

	ft_memset(str, 'A', 5);

	printf("Après memset: %s\n", str);

	return (0);
}*/