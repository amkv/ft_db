/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_by_last_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:51:26 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/28 12:51:27 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char			**ft_split_by_last_char(const char *str, char c)
{
	size_t		index;
	size_t		qt;
	size_t		len;
	char		**result;

	if (!str)
		return (NULL);
	if ((len = ft_strlen(str)) <= 1)
		return (NULL);
	if ((qt = ft_strchr_qt(str, c)) == 0 || (len - qt) < 2)
		return (NULL);
	if (str[len - 1] == c)
		return (NULL);
	index = 0;
	while (str[index] != '\0' && qt != 0)
	{
		if (str[index] == c)
			qt--;
		index++;
	}
	result = (char**)malloc(sizeof(char**) * 2);
	result[0] = ft_strnew(index);
	ft_strncpy(result[0], str, index - 1);
	result[1] = ft_strdup(((char*)(str + index)));
	return (result);
}
