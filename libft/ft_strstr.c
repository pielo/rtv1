/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:53:25 by mlanglet          #+#    #+#             */
/*   Updated: 2013/12/01 19:01:32 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	nb;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[j])
		{
			nb = i;
			while (s1[i] == s2[j++] && s1[i] != '\0')
			{
				i++;
				if (s2[j] == '\0')
					return ((char *)&s1[nb]);
			}
			j = 0;
			i = nb;
		}
		i++;
	}
	return (NULL);
}
