/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:35:54 by mlanglet          #+#    #+#             */
/*   Updated: 2013/12/23 18:02:05 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/libft.h"
#include <string.h>

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		d_size;
	size_t		l;
	size_t		r;

	d_size = ft_strlen(dest);
	l = ft_strlen(src);
	r = d_size + l;
	if (size < d_size)
		return (size + l);
	if (d_size < size)
	{
		dest += d_size;
		size -= d_size;
		if (l >= size)
			l = size - 1;
		dest[l] = 0;
		ft_strncpy(dest, src, l);
	}
	return (r);
}

