/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:43:50 by mlanglet          #+#    #+#             */
/*   Updated: 2013/12/05 11:27:49 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*tab;
	unsigned int	i;

	if (s != NULL && f != NULL)
	{
		i = ft_strlen(s);
		tab = (char *)malloc(sizeof(tab) * (i + 1));
		if (!tab)
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			tab[i] = f(s[i]);
			i++;
		}
		tab[i] = '\0';
		return (tab);
	}
	return (NULL);
}
