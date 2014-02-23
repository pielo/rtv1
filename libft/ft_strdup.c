/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:21:36 by mlanglet          #+#    #+#             */
/*   Updated: 2014/01/15 15:57:04 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdlib.h>

char		*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	length;

	length = 0;
	while (s1[length] != '\0')
	{
		length++;
	}
	if (!(s2 = (char *) malloc(sizeof(char) * (length + 1))))
		return (NULL);
	length = 0;
	while (s1[length] != '\0')
	{
		s2[length] = s1[length];
		length++;
	}
	s2[length] = '\0';
	return (s2);
}
