/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:34:53 by ljerk             #+#    #+#             */
/*   Updated: 2019/09/20 19:38:17 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*res(t_list *node, t_list *(*f)(t_list *node))
{
	node = (*f)(node);
	node = ft_lstnew(node->content, node->content_size);
	return (node);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*out;
	t_list	*tmp;
	t_list	*start;

	if (lst == NULL || f == NULL)
	{
		return (NULL);
	}
	out = res(lst, f);
	if (out == NULL)
		return (NULL);
	tmp = out;
	start = tmp;
	while (lst->next != NULL)
	{
		lst = lst->next;
		tmp->next = res(lst, f);
		if (tmp->next == NULL)
			ft_lstfree(start);
		tmp = tmp->next;
	}
	return (out);
}
