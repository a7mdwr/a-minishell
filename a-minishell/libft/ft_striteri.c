/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:53:13 by aradwan           #+#    #+#             */
/*   Updated: 2024/12/17 09:53:13 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
	s[i] = '\0';
}

// #include <stdio.h>
// #include "libft.h"
// void to_uppercasee(unsigned int index, char *c)
// {
//     if (*c >= 'a' && *c <= 'z')
//         *c -= 32;
// }
// int main(void)
// {
//     char str[] = "Hello, world!";
//     ft_striteri(str, to_uppercasee);
//     printf("%s\n", str);
//     return 0;
// }
