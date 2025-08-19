/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:40:26 by aradwan           #+#    #+#             */
/*   Updated: 2024/12/16 19:40:26 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c -= 32;
	}
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>

// int main() 
// {
//     char c = 'b';
//     printf("%c\n", ft_toupper(c));
//     return 0;
// }