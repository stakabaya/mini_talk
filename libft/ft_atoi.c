/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:00:36 by stakabay          #+#    #+#             */
/*   Updated: 2021/11/05 09:54:38 by stakabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_errno(int num)
{
	int	errno;

	errno = num;
	return (0);
}

int	check_flags(const char **str, int *sign)
{
	if (**str == '\0' || *str == 0)
		return (0);
	while (**str == ' ' || **str == '\t' || **str == '\n' || \
			**str == '\v' || **str == '\f' || **str == '\r')
		(*str)++;
	if (**str == '-')
		*sign *= -1;
	if (**str == '-' || **str == '+')
		(*str)++;
	if (**str == '0' && ('0' <= *(*str + 1) && *(*str + 1) <= '9'))
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (!check_flags(&str, &sign))
		return (ft_errno(22));
	while ('0' <= *str && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		if (!('0' <= *(str + 1) && *(str + 1) <= '9'))
		{
			num = num * sign;
			if (num < INT32_MIN || INT32_MAX < num)
				return (ft_errno(22));
			return (num);
		}
		str++;
	}
	return (ft_errno(22));
}
