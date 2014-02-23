/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:01:01 by mlanglet          #+#    #+#             */
/*   Updated: 2013/12/01 19:11:13 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

size_t		ft_strlen(const char *s)
{
	size_t		count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}
