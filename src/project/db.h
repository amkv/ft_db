/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:44:18 by akalmyko          #+#    #+#             */
/*   Updated: 2017/03/17 18:02:48 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DB_H
# define DB_H

# include "../lib/libft/libft.h"

# pragma GCC diagnostic ignored "-Wunused-parameter"
# pragma GCC diagnostic ignored "-Wunused-variable"
# pragma GCC diagnostic ignored "-Wunused-function"

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
# define ISEQUAL 0

enum boolean
{
	False,
	True
};

typedef struct			s_db
{
	char 				*name;
	int					amountTables;		// how many tables
	struct s_table		*firstTable;		// first table in DB
	struct s_table		*lastTable;			// last table in DB
}						t_db;

typedef struct			s_table
{
	char 				*nameTable;			// name of table
	size_t	 			amountColumn; 		// how many columns
	struct s_column		*firstColumn;		// first column in Table
	struct s_column		*lastColumn;		// first column in Table
	struct s_table		*nextTable;			// next table in DB
}						t_table;

typedef struct			s_column
{
	char 				*nameColumn;		// name of column
	struct s_record		*downRecord;		// next Record (down)
	struct s_column		*nextColumn;		// next Column (right)
}						t_column;

typedef struct			s_record
{
	enum boolean		isID;				// is first record in row? True/False
	size_t				id;					// uniq id of record if first record
	int 				value;				// value of record (union?)
	struct s_record		*rowRecord;			// next record (right)
	struct s_record		*columnRecord;		// next record (down)
}						t_record;

t_db					*ft_init_db(char *name);
void					ft_new_table(t_db *database, char *name);
t_table					*ft_return_table(t_db *database, char *name);
void					ft_new_table(t_db *database, char *name);

#endif
