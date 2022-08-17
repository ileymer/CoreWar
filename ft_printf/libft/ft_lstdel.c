/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:57:08 by ljerk             #+#    #+#             */
/*   Updated: 2019/09/17 15:36:28 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *nextlst;
	t_list *lst;

	lst = *alst;
	while (lst != NULL)
	{
		nextlst = lst->next;
		ft_lstdelone(&lst, del);
		lst = nextlst;
	}
	*alst = NULL;
}
