/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:47:10 by ljerk             #+#    #+#             */
/*   Updated: 2019/09/20 19:57:38 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list *lst)
{
	t_list	*cur;
	t_list	*n;

	cur = lst;
	while (cur->next != NULL)
	{
		n = cur->next;
		free(cur->content);
		cur->content = NULL;
		cur->content_size = 0;
		free(cur);
		cur = n;
	}
	lst = NULL;
}
