/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:51:12 by akalmyko          #+#    #+#             */
/*   Updated: 2016/11/22 16:19:32 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_extract_end(t_node *list, int fd)
{
	t_node			*temp;

	temp = list;
	if (!temp)
		return (NULL);
	while (temp)
	{
		if (fd == temp->fd)
			return (temp->end);
		temp = temp->next;
	}
	return (NULL);
}

static t_node		*new_list(t_node *list, int fd, char *end)
{
	t_node			*newlist;

	newlist = (t_node*)malloc(sizeof(t_node) * 1);
	newlist->fd = fd;
	newlist->end = NULL;
	if (end)
		newlist->end = end;
	newlist->next = NULL;
	if (list)
		newlist->next = list;
	return (newlist);
}

static char			*ft_cut_the_line(char **str, char **end, size_t i)
{
	char			*newstr;
	char			*tmp;

	tmp = *str;
	while (*tmp)
	{
		if (*tmp == '\n' || *tmp++ == '\0')
			break ;
		i++;
	}
	(i == 0 && *tmp == '\n') ? (i = 1) : (i);
	ft_strncpy((newstr = ft_strnew(i + 1)), *str, i);
	ft_strcpy((*end = ft_strnew(ft_strlen(tmp) + 1)), tmp);
	free(*str);
	*str = NULL;
	*str = newstr;
	if (**end == '\0')
	{
		free(*end);
		*end = NULL;
	}
	else
		(*end)++;
	return (*str);
}

static int			ft_reader(int fd, char **str)
{
	char			buf[BUFF_SIZE + 1];
	ssize_t			num;
	char			*tmp;

	ft_bzero(buf, BUFF_SIZE + 1);
	if (*str == NULL)
		*str = ft_strnew(1);
	if ((num = read(fd, buf, BUFF_SIZE)) < 0)
		return (-1);
	if (num == 0)
		return (0);
	tmp = ft_strjoin(*str, buf);
	free(*str);
	*str = tmp;
	if (ft_strchr(*str, '\n') == NULL)
		ft_reader(fd, *&str);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	char			*str;
	char			*end;
	char			*tmp;
	static t_node	*list;

	str = NULL;
	if (fd < 0 || !line || (ft_reader(fd, &str) < 0))
		return (GNL_ERROR);
	if ((end = ft_extract_end(list, fd)) != NULL)
	{
		tmp = ft_strjoin(end, str);
		free(str);
		str = NULL;
		str = tmp;
	}
	*line = ft_cut_the_line(&str, &end, 0);
	if (end != NULL)
		if (ft_strcmp(str, end) == 0)
			end = NULL;
	list = new_list(list, fd, end);
	if (end == NULL && *str == '\0')
		return (GNL_ENDFILE);
	if (*str == '\n' && *(str + 1) == '\0')
		*str = '\0';
	return (GNL_CONTINUE);
}
