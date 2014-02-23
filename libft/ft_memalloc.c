/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:46:04 by mlanglet          #+#    #+#             */
/*   Updated: 2013/12/01 19:07:14 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	char			*alloc;
	unsigned int	i;

	if (size == 0)
		return (NULL);
	alloc = (char *)malloc(sizeof(char *) * size);
	if (!alloc)
		return (NULL);
	i = 0;
	while (i < size)
	{
		alloc[i] = '\0';
		i++;
	}
	return ((void *)alloc);
}
