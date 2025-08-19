/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:46:56 by aradwan           #+#    #+#             */
/*   Updated: 2024/12/16 15:46:56 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*cal;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	cal = malloc(count * size);
	if (!cal)
		return (NULL);
	ft_bzero(cal, count * size);
	return (cal);
}

// #include <stdio.h>
// int main()
// {
// 	char *m = ft_calloc(sizeof(char), 232);
// 	int i;
// 	i = 0;
// 	while (i < 232)
// 	{
// 		printf("%d", (int)m[i]);
// 		i++;
// 	}
// 	free (m);
// }
