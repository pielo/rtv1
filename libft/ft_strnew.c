/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:22:00 by mlanglet          #+#    #+#             */
/*   Updated: 2013/12/01 19:14:08 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char		*tab;
	size_t		i;

	i = 0;
	if (size == 0)
		size = 1;
	tab = (char *)malloc(sizeof(tab) * size);
	if (!tab)
		return (NULL);
	while (i < size - 1)
	{
		tab[i] = '\0';
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
