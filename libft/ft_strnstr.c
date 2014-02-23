/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:21:48 by mlanglet          #+#    #+#             */
/*   Updated: 2013/12/31 18:25:44 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

static char		*ft_fct(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	nb;

	i = 0;
	j = 0;
	while (i < n && s1[i] != '\0')
	{
		if (s1[i] == s2[j])
		{
			nb = i;
			while (s1[i] == s2[j++] && i < n && s1[i] != '\0')
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


char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	if (s2[0] == '\0')
		return ((char *)s1);
	return (ft_fct(s1, s2, n));
}
