/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:01:20 by mlanglet          #+#    #+#             */
/*   Updated: 2013/12/01 19:12:36 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdlib.h>

void		*ft_memset(void *str, int c, size_t length)
{
	unsigned long int		i;

	i = 0;
	while (i < length)
	{
		*((char *)str + i) = (char)c;
		i++;
	}
	return (str);
}
