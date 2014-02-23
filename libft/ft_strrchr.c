/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:23:02 by mlanglet          #+#    #+#             */
/*   Updated: 2013/12/01 19:00:57 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	int				nb;
	char			ch;

	i = 0;
	nb = - 1;
	ch = c;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			nb = i;
		i++;
	}
	if (ch == '\0')
		nb = i;
	if (nb == - 1)
		return (NULL);
	return ((char *)&s[nb]);
}
