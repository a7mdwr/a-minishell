/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:07:02 by aradwan           #+#    #+#             */
/*   Updated: 2024/12/17 09:07:02 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

// #include <stdio.h>
// int main()
// {
//     char *str1 ="fsgwqx";
//     char *str2 = "sfwo2";
//     char *str3 = "shfhsh";
//     t_list *list1 = ft_lstnew(str1);
//     t_list *list2 = ft_lstnew(str2);
//     t_list *list3 = ft_lstnew(str3);
//     list1->next = list2;
//     list2->next = list3;
//     t_list *tmp = list1;
//     while (tmp)
//     {
//         printf("%s\n",(char*)tmp->content );
//         tmp = tmp->next;
//     }
//     t_list *next;
//     while (list1)
//     {
//         next = list1->next;
//         free(list1);
//         list1 = next;
//     }
// }
// int main()
// {
//     char *str = "kla";
//     char *str1 = "ahmad";
//     char *str2 = "mohamed";
//     t_list *list = ft_lstnew(str);
//     t_list *list2 = ft_lstnew(str1);
//     t_list *list3 = ft_lstnew(str2)
//     list->next = list2;
//     list2->next = list3;
//     t_list *tmp = list;
//     while(tmp)
//     {
//         printf("%s\n", (char *)tmp->content);
//         tmp = tmp->next;
//     }
//     t_list *next;
//     while (list)
//     {
//         next = list->next;
//         free(list);
//         list = next;
//     }
//     list = NULL;
// }
