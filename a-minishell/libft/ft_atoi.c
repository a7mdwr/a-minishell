/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:07:50 by aradwan           #+#    #+#             */
/*   Updated: 2024/12/18 15:07:50 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		result;
	int		sign;

	sign = 1;
	result = 0;
	i = 0;
	while (((str[i] >= TAB && str[i] <= CARRIAGE) || (str[i] == SPACE)))
		i++;
	if ((str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main() 
// {
// 	char str[] = "314";
// 	int num = ft_atoi(str);
// 	int num1 = atoi(str);

// 	printf("%d\n", num);
// 	printf("%d\n", num1);
// }