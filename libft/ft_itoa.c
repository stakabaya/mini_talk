/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 19:55:59 by stakabay          #+#    #+#             */
/*   Updated: 2021/11/25 12:25:12 by stakabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*setnum(char *num, int keta, int n)
{
	int	flag;

	flag = 1;
	if (n < 0)
	{
		num[0] = '-';
		n *= -1;
		flag = 0;
	}
	num[keta--] = '\0';
	while (keta > 0)
	{
		num[keta--] = (n % 10) + '0';
		n /= 10;
	}
	if (flag == 1)
		num[0] = (n % 10) + '0';
	return (num);
}

char	*int_min(char *num)
{
	num = (char *)ft_calloc(12, sizeof(char));
	if (!num)
		return (NULL);
	setnum(num, 10, -214748364);
	num[10] = '8';
	return (num);
}

char	*ft_itoa(int n)
{
	int		keta;
	int		tmp;
	char	*num;

	num = NULL;
	if (n == -2147483648)
		return (int_min(num));
	keta = 0;
	if (n < 0)
		keta++;
	tmp = n;
	if (n == 0)
		keta++;
	while (tmp)
	{
		tmp /= 10;
		keta++;
	}
	num = malloc(keta + 1);
	if (!num)
		return (NULL);
	return (setnum(num, keta, n));
}
