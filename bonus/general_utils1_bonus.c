/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitabde <aaitabde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:47:47 by aaitabde          #+#    #+#             */
/*   Updated: 2025/01/31 20:48:06 by aaitabde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	isnegative(int *len, int *isng, int *n)
{
	*len = 1;
	*isng = -1;
	*n = -*n;
}

static char	*ft_assigner(int len, char *result, int n)
{
	while (len >= 0)
	{
		result[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (result);
}

static int	digit_calculator(int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*result;
	int		isng;

	isng = 1;
	len = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		isnegative(&len, &isng, &n);
	if (n == 0)
		return (ft_strdup("0"));
	len = len + digit_calculator(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len--] = '\0';
	ft_assigner(len, result, n);
	if (isng == -1)
		result[0] = '-';
	return (result);
}
