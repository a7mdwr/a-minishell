/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:53:51 by aradwan           #+#    #+#             */
/*   Updated: 2024/12/16 16:53:51 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// #include <stdio.h> 
// #include <string.h> 
// int main()
// { 
//     char str[50] = "ajjuuhvhvhv jjhhjg bjgugb "; 
//     ft_memset(str + 13, '.', 8*sizeof(char)); 
//     printf("%s\n", str); 
//     return 0; 
// } 