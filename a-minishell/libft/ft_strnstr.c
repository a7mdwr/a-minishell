/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:59:48 by aradwan           #+#    #+#             */
/*   Updated: 2024/12/16 19:59:48 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!*needle)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (haystack[i] && i + ft_strlen(needle) <= len)
	{
		if (needle[j] == haystack[i])
		{
			if (ft_memcmp(needle, &haystack[i], ft_strlen(needle)) == 0)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include "libft.h"

// int main(void)
// {
//     const char haystack[] = "Hello, World!llllllllllllllll00000000l";
//     const char needle[] = "World";
//     size_t len = 13;
//     char *result;
//     result = ft_strnstr(haystack, needle, len);
//     printf("%s\n", result);
// }