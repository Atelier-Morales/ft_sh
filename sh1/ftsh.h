/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 09:44:06 by fmorales          #+#    #+#             */
/*   Updated: 2013/12/29 23:21:00 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTSH_H
# define FTSH_H
# include <string.h>
# include "./libft/libft.h"

# define BUFF_SIZE 90960

typedef struct		s_read
{
	int				size;
	int				index;
	int				fd;
	char			*read;
	struct s_read	*next;
}					t_read;

typedef struct		s_env
{
	int				status;
	int				i;
	int				j;
	int				k;
	int				l;
	int				m;
	char			*data;
	char			*cmd;
	char			**var;
	char			**lib;
	char			**test;
	char			*home;
	char			*pwd;
	char			*env_args;
	char			**env;
	char			**buf;
}					t_env;

int					main(void);
int					get_next_line(int const fd, char **line);
void				print_header(void);
void				print_cderror(char *var, int i);
void				treat_case(char **var, char **env, t_env *e);
void				print_env(char **env);
char				*test_cmd(char **lib, char *var, int i);
char				**copy_env(char **env, char **environ);
void				set_env(t_env *e, char **var);
void				unset_env(t_env *e, char **var);
void				print_prompt(t_env e);

#endif
