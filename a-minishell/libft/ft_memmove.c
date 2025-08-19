/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/12/17 09:20:46 by aradwan           #+#    #+#             */
/*   Updated: 2024/12/17 09:20:46 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*sc;

	i = 0;
	dst = (unsigned char *)dest;
	sc = (unsigned char *)src;
	if (dst > sc)
	{
		while (n > 0)
		{
			n--;
			dst[n] = sc[n];
		}
	}
	else
	{
		while (i < n)
		{
			dst[i] = sc[i];
			i++;
		}
	}
	return (dst);
}

// #include <string.h>
// int	main(void)
// {
// 	char *s = NULL;
// 	char dst[10] = "12456";

// 	ft_memmove(dst ,s, 5);
// 	printf("%s\n", s);
// }
