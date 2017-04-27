/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:08:08 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/06 13:08:09 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXTRA_H
# define FT_EXTRA_H

# include "../libft/libft.h"

void			*ft_memnncpy(void *dst, const void *src, size_t beg, size_t n);
char			*ft_itoa_base_uintmax(uintmax_t value, uintmax_t base);
char			*ft_itoa_base(intmax_t value, intmax_t base);
char			*ft_strdel_begn(char *str, size_t n);
char			*ft_strdupn(const char *str, size_t n);
size_t			ft_wcharlen(wchar_t wchar);
int				ft_atoi_werror(const char *str, int *error);
char			**ft_split_by_last_char(const char *str, char c);

#endif
