/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:09:41 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/06 15:09:42 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static intmax_t	ft_return_value(intmax_t v)
{
	if (v < 0)
		return (-(v));
	else
		return (v);
}

static void		ft_a(intmax_t val, intmax_t base, char *ret, intmax_t *i)
{
	char		*b;

	if (val <= -base || base <= val)
		ft_a((val / base), base, ret, i);
	b = ft_strdup("0123456789abcdef");
	ret[(*i)++] = b[ft_return_value(val % base)];
	free(b);
}

char			*ft_itoa_base(intmax_t val, intmax_t base)
{
	char		*ret;
	intmax_t	i;

	if (base < 2 || base > 16 || !(ret = ft_strnew(35)))
		return (NULL);
	i = 0;
	if (base == 10 && val < 0)
		ret[i++] = '-';
	ft_a(val, base, ret, &i);
	ret[i] = '\0';
	return (ret);
}
