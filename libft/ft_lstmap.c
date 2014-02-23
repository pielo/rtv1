/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 12:00:07 by mlanglet          #+#    #+#             */
/*   Updated: 2013/12/23 18:01:31 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*new2;

	new = (t_list *)malloc(sizeof(new));
	new = ft_lstnew(lst->content, lst->content_size);
	while (lst != NULL)
	{
		new2 = (t_list *)malloc(sizeof(new2));
		new2 = f(lst);
		ft_lstadd(&new, new2);
		lst = lst->next;
	}
	return (new);
}
