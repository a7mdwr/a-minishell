/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:06:03 by aradwan           #+#    #+#             */
/*   Updated: 2024/12/17 09:06:03 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

//  int main()
//  {
// 	char *str = "sakjlagjlkjsg";
// 	char *str1 = "sakjlasrgjlkjsg";
// 	char *str2 = "5sakjlfdagjlkjsg";
// 	t_list *lst = ft_lstnew(str);
// 	t_list *lst2 = ft_lstnew(str1);
// 	t_list *lst3 = ft_lstnew(str2);
// 	lst->next = lst2;
// 	lst2->next = lst3;
// 	t_list *tmp = ft_lstlast(lst);
// 	printf("%s\n", (char *)tmp->content);
//  }

//  int main()
//  {
// 	char *str1 = "1gfgg";
// 	char *str2 = "2fgf";
// 	char *str3 = "3gfg";
// 	char *str4 = "4gfgf";
// 	char *str5 = "5gfg";
// 	t_list *lst1 = ft_lstnew(str1);
// 	t_list *lst2 = ft_lstnew(str2);
// 	t_list *lst3 = ft_lstnew(str3);
// 	t_list *lst4 = ft_lstnew(str4);
// 	t_list *lst5 = ft_lstnew(str5);
// 	lst1->next = lst2;
// 	lst2->next = lst3;
// 	lst3->next = lst4;
// 	lst4->next = lst5;
// 	t_list *tmp;
// 	tmp = ft_lstlast(lst1);
// 	printf("%s\n", (char *)tmp->content);
//  }