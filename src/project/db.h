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
# include <stdarg.h>

# pragma GCC diagnostic ignored "-Wunused-parameter"
# pragma GCC diagnostic ignored "-Wunused-variable"
# pragma GCC diagnostic ignored "-Wunused-function"

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
# define ISEQUAL 0
# define NONPRINTABLE 0
# define STRING 1
# define INT 2
# define PAIRSEPARATOR ':'
# define SEPARATOR ','
<<<<<<< HEAD

# define CREATE_DATABASE "CREATE DATABASE"
# define CREATE_TABLE "CREATE TABLE"
# define CREATE_COLUMN "CREATE COLUMN"
# define ADD_RECORD "ADD RECORD"
# define CHANGE_RECORD "CHANGE RECORD"
# define DELETE_RECORD "DELETE RECORD"
//# define SELECT_
=======
>>>>>>> be270d3794cb92b9a0bde32764473fb0e5a8cdc5

typedef enum boolean
{
	False,
	True
}			bool;

typedef struct			s_db
{
	char 				*name;
	int					amountTables;		// how many tables
	struct s_table		*firstTable;		// first table in DB
	struct s_table		*lastTable;			// last table in DB
	bool				error;				// any errors?
	char 				*nameError;			// name of error
}						t_db;

typedef struct			s_table
{
	char 				*nameTable;			// name of table
	size_t	 			amountColumns; 		// how many columns
	size_t	 			amountRecords; 		// how many records
	size_t	 			amountRows; 		// how many records
	bool				empty;				// is empty table? True/False
	struct s_column		*firstColumn;		// first column in Table
	struct s_column		*lastColumn;		// first column in Table
	struct s_table		*nextTable;			// next table in DB
}						t_table;

typedef struct			s_column
{
	char 				*nameColumn;		// name of column
	char 				*typeColumn;		// type of column
	size_t	 			amountRecords; 		// how many records
	struct s_record		*firstRow;			// first Record (in column)
	struct s_record		*lastRow;			// last Record (in column)
	struct s_column		*nextColumn;		// next Column (right)
}						t_column;

typedef struct			s_record
{
	bool				isID;				// is first record in row? True/False
	bool				empty;				// is empty record? True/False
	size_t				id;					// id record record (row uniq id)
	void 				*value;				// value of record (union?)

	char 				*typeRecord;		// type of record
	struct s_record		*right;				// pointer in table
	struct s_record		*left;
	struct s_record		*down;
	struct s_record		*up;

	struct s_column		*column;			// pointer to column
	struct s_record		*firstID;			// pointer to first record in row
}						t_record;

typedef struct 			s_query				// wrapper for query
{
	char				*command;
	char				*tag;
	t_db 				*database;
	t_table				*table;
	t_column			*column;
	t_record			*row;
//	t_record			*record;
	char				*nameDB;
	char				*nameTable;
	char				*nameColumn;
	char				*typeColumn;
	void				*record;
	bool				error;				// True if error
	char				*error_name;
	struct s_query		*firstQuery;
	struct s_query		*next;
}						t_query;

void 					ft_db_parser(t_query **query, const char *format);
t_query					*ft_db_add_query(t_query *query, char *command, char *tag);
int	 					ft_db_action(t_query *query, va_list list);
t_db					*ft_init_db(char *nameDB);
void					ft_set_error(t_db *database, char *nameError);
void					ft_clean_error(t_db *database);
void					ft_print_db_error(t_db *database);
void					ft_new_table(t_db *database, char *name);
t_table					*ft_return_table(t_db *database, char *name);
void					ft_new_table(t_db *database, char *name);
void 					ft_new_column(t_db *database, char *nameTable, char *nameColumn, char *typeColumn);
t_column				*ft_return_column(t_table *table, char *nameColumn);
int						ft_check_type_of_column(char *typeColumn);
void 					ft_new_record(t_db *database, char *tableName, char *nameColumn, char *type, void *record);
void					ft_create_row(t_db *database, t_table *table, t_column *column);
int 					ft_db(const char *restrict format, ...);


int 					ft_is_all_print(const char *str);
void					ft_db_print_all_db(t_db *database);

#endif
