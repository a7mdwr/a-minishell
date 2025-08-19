/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:35:35 by aradwan           #+#    #+#             */
/*   Updated: 2024/12/16 18:35:35 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_count(int *n, size_t *count)
{
	int	i;

	i = *n;
	while (i)
	{
		i = i / 10;
		(*count)++;
	}
}

char	*ft_sign(int *n, int *sign, char **itoa)
{
	if (*n == 0)
	{
		*itoa = ft_calloc(2, 1);
		*itoa[0] = '0';
		return (*itoa);
	}
	if (*n < 0)
	{
		*n = (*n) * -1;
		*sign = 1;
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	size_t	count;
	char	*itoa;
	int		sign;

	count = 0;
	sign = 0;
	itoa = NULL;
	if (ft_sign(&n, &sign, &itoa) != NULL)
		return (itoa);
	ft_count(&n, &count);
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	itoa = malloc(sizeof(char) * (count + sign + 1));
	if (!itoa)
		return (NULL);
	itoa[count + sign] = '\0';
	if (sign == 1 && count++)
		itoa[0] = '-';
	while (n)
	{
		count--;
		itoa[count] = n % 10 + '0';
		n = n / 10;
	}
	return (itoa);
}

// int main()
// {
// 	int i = 1333;
// 	char *str = ft_itoa(i);
// 	printf("%s\n", str);
// 	free(str);
// }