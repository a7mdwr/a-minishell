/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:42:11 by aradwan           #+#    #+#             */
/*   Updated: 2024/12/16 19:42:11 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c += 32;
	}
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>

// int main() 
// {
//     char c = 'B';
//     printf("%c\n", ft_tolower(c));
//     return 0;
// }