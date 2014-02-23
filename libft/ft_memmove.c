/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:32:47 by mlanglet          #+#    #+#             */
/*   Updated: 2013/12/05 11:26:01 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*p;

	if (!n)
		return (dest);
	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	p = dest + n;
	src += n;
	while (n--)
		*--p = *(char*)--src;
	return (dest);
}
