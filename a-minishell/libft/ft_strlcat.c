/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:05:39 by aradwan           #+#    #+#             */
/*   Updated: 2024/12/16 20:05:39 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	delen;
	unsigned int	slen;

	i = 0;
	j = 0;
	while (dst[j] != '\0')
	{
		j++;
	}
	delen = j;
	slen = ft_strlen(src);
	if (size == 0 || size <= delen)
	{
		return (slen + size);
	}
	while (src[i] != '\0' && i < size - delen - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (delen + slen);
}

// int main(void)
// {
//     char dst[20] = "Hello";
//     const char *src = " World!";
//     size_t size = 15;
//     size_t result = ft_strlcat(dst, src, size);
//     printf("Result: %d, Destination: %s\n", result, dst);
//     return 0;
// }