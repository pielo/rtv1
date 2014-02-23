/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:44:10 by mlanglet          #+#    #+#             */
/*   Updated: 2013/12/05 11:28:18 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/libft.h"
#include <stdlib.h>

static int	ft_count(char const *s)
{
	int		i;
	int		j;

	j = ft_strlen(s);
	i = j - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		j--;
		i--;
	}
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		j--;
		i++;
	}
	return (j);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		max;
	char	*tab;

	j = 0;
	if (s != NULL)
	{
		max = ft_count(s);
		if (max <= 0)
			return (tab = (char *)malloc(sizeof(tab)));
		tab = (char *)malloc(sizeof(tab) * (max + 1));
		i = 0;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		while (j < max)
		{
			tab[j] = s[i];
			i++;
			j++;
		}
		tab[j] = '\0';
		return (tab);
	}
	return (NULL);
}
