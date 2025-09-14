/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/12/17 09:19:37 by aradwan           #+#    #+#             */
/*   Updated: 2024/12/17 09:19:37 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*sc;

	i = 0;
	sc = (unsigned char *)src;
	dst = (unsigned char *)dest;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		dst[i] = sc[i];
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char s[] = "ahmad";
// 	char d[100] = "l";

// 	ft_memcpy(d, s, 3);
// 	printf("%s\n", d);
// }
