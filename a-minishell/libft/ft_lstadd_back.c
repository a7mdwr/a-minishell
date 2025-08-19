/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:16:34 by aradwan           #+#    #+#             */
/*   Updated: 2024/12/16 19:16:34 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			tmp->next = new;
			return ;
		}
		tmp = tmp->next;
	}
}

// #include <stdio.h>
//  int main()
//  {
//     char *str = "asakjlagjlkjsg";
//     char *str1 = "bsakjlasrgjlkjsg";
//     char *str2 = "csakjlfdagjlkjsg";
//     t_list *lst = ft_lstnew(str);
//     ft_lstadd_back(&lst, ft_lstnew(str));
//     ft_lstadd_back(&lst, ft_lstnew(str1));
//     ft_lstadd_back(&lst, ft_lstnew(str2));
//     t_list *tmp = lst;
//     while (tmp)
//     {
//         printf("%s\n", (char *)tmp->content);
//         tmp = tmp->next;
//     }
//  }