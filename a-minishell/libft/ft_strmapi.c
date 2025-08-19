/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:02:50 by aradwan           #+#    #+#             */
/*   Updated: 2024/12/16 20:02:50 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;
	size_t	len;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>
// #include "libft.h"
// char to_uppercase(unsigned int i, char c)
// {
// 	(void)i;
//     if (c >= 'a' && c <= 'z')
//         return (c - 32);
//     return c;
// }
// int main(void)
// {
//     char *str = "hello, world!";
//     char *new_str = ft_strmapi(str, to_uppercase);
//     printf("%s\n", str);
//     printf("%s\n", new_str);
//     free(new_str);
//     return 0;
// }
