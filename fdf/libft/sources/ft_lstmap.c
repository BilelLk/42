/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 07:24:06 by blakehal          #+#    #+#             */
/*   Updated: 2022/11/14 10:57:29 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*temp;

	if (!lst || !f || !del)
		return (0);
	lst_new = 0;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&lst_new, del);
			return (0);
		}
		ft_lstadd_back(&lst_new, temp);
		lst = lst->next;
	}
	return (lst_new);
}
