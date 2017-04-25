/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 12:35:37 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/07 12:35:38 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static long long	ft_ai(const char *str, int *error, int *sign, size_t *len)
{
	long long	result;

	result = 0;
	while (ft_isspace(*str))
	{
		str++;
		(*len)--;
	}
	if (*str == '-')
		*sign = -1;
	if (*str == '+' || *str == '-')
	{
		str++;
		(*len)--;
	}
	while (ft_isdigit(*str))
	{
		result = 10 * result + (*str - '0');
		(*error)++;
		str++;
		(*len)--;
	}
	return (result);
}

int					ft_atoi_werror(const char *str, int *error)
{
	long long	result;
	int			sign;
	size_t		len;

	sign = 1;
	result = 0;
	*error = 0;
	len = 0;
	if (str)
	{
		len = ft_strlen(str);
		result = ft_ai(str, *&error, &sign, &len);
	}
	if (len >= 1)
		return (*error = 0);
	if (*error == 0)
		return (*error = 0);
	if (result < MININT || result > MAXINT)
		return (*error = 0);
	return ((int)result * sign);
}
