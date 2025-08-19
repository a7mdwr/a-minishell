/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:55:57 by aradwan           #+#    #+#             */
/*   Updated: 2024/12/16 19:55:57 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*str;
	size_t	a;
	size_t	j;

	i = 0;
	j = 0;
	a = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1);
	while (j > i && ft_strrchr(set, s1[j - 1]))
		j--;
	str = (char *)malloc(sizeof(char) * (j - i) + 1);
	while (!str)
		return (NULL);
	while (i < j)
		str[a++] = s1[i++];
	str[a] = '\0';
	return (str);
}

#include <stdio.h>
int main()
{
    char *str = ft_strtrim(" yuyuyuyl  ahmlad  ll", " lyu");
    printf("%s\n", str);
    free (str);
}