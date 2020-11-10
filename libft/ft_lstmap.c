/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <pferdina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:59:11 by pferdina          #+#    #+#             */
/*   Updated: 2019/12/26 20:03:33 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (lst && f)
	{
		new = f(lst);
		new->next = ft_lstmap(lst->next, f);
		if (!(new->next) && lst->next)
		{
			new->content = NULL;
			free(new->next);
			new->next = NULL;
			free(new);
			new = NULL;
		}
		return (new);
	}
	return (NULL);
}
