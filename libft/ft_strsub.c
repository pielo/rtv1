/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:41:01 by mlanglet          #+#    #+#             */
/*   Updated: 2013/12/01 19:17:36 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*tab;
	size_t		i;

	if (s != NULL)
	{
		tab = (char *)malloc(sizeof(tab) * (len + 1));
		i = 0;
		while (i < len)
		{
			tab[i] = s[start + i];
			i++;
		}
		tab[i] = '\0';
		return (tab);
	}
	return (NULL);
}
