/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_24_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem Kalmykov <akalmyko@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:12:20 by akalmyko          #+#    #+#             */
/*   Updated: 2017/05/03 15:47:13 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

static t_record	*ft_malloc_record(void)
{
	t_record	*new;

	new = (t_record*)malloc(sizeof(t_record) * 1);
	if (!new)
		return (NULL);
	new->isID = False;
	new->empty = True;
	new->id = 0;
	new->value = NULL;
	new->right = NULL;
	new->left = NULL;
	new->down = NULL;
	new->up = NULL;
	new->column = NULL;
	new->firstID = NULL;
	new->typeRecord = NULL;
	return (new);
}

static void 	ft_set_first_in_row(t_record *new, t_table *table, t_column	*column_, t_record **firstID)
{
	new->isID = True;
	new->id = table->amountRows + 1;
	new->firstID = new;
	*firstID = new;
	if (!column_->firstRow)
		column_->firstRow = new;
}

static void		ft_set_new(t_record *new, t_column	*column_, t_record *firstID, t_record *lastRow)
{
	new->typeRecord = column_->typeColumn;
	new->column = column_;
	new->firstID = firstID;
	new->id = firstID->id;
	new->typeRecord = column_->typeColumn;
	new->up = lastRow;
}

static void		ft_set_new2(t_record *new, t_record	**left, t_column **column_, t_record **lastRow)
{
	new->left = *left;
	new->typeRecord = ft_strdup((*column_)->typeColumn);
	if (*left)
		(*left)->right = new;
	*left = new;
	(*column_)->lastRow = new;
	if (*lastRow)
	{
		(*lastRow)->down = new;
		*lastRow = (*lastRow)->right;
	}
}

void			ft_create_row(t_db *database, t_table *table, t_column *column)
{
	t_column	*column_;
	t_record	*new;
	t_record	*left;
	t_record	*firstID;
	t_record	*lastRow;
	bool		first;

	column_ = table->firstColumn;
	left = NULL;
	firstID = NULL;
	first = True;
	if (column_->lastRow)
		lastRow = column_->lastRow->firstID;
	else
		lastRow = NULL;
	while(column_)
	{
		new = ft_malloc_record();
		if (first)
		{
			ft_set_first_in_row(new, table, column_, &firstID);
			first = False;
		}
		ft_set_new(new, column_, firstID, lastRow);
		ft_set_new2(new, &left, &column_, &lastRow);
		if (!column_->firstRow)
			column_->firstRow = new;
		column_ = column_->nextColumn;
	}
	table->amountRows += 1;
	database->unused = True;
	column->unused = True;
}
