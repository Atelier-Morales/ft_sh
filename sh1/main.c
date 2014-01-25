/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 15:45:26 by fmorales          #+#    #+#             */
/*   Updated: 2014/01/25 16:10:52 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "ftsh.h"

extern char **environ;

char		**copy_env(char **env, char **environ)
{
	int		i;

	i = 0;
	env = (char **)malloc(sizeof(char *));
	while (environ[i] != NULL)
	{
		env[i] = ft_strdup(environ[i]);
		i++;
	}
	return (env);
}

void		print_env(char **env)
{
	int		i;

	i = 0;
	while (env[i] != NULL)
	{
		ft_putendl(env[i]);
		i++;
	}
}

void		start_process(t_env *e, pid_t father)
{
	if (father == -1)
		kill(father, SIGINT);
	else if (father == 0)
	{
		get_next_line(0, &e->data);
		e->var = ft_strsplit(e->data, ' ');
		if (ft_strcmp("exit", e->var[0]) == 0)
			kill(father, SIGINT);
		if (ft_strcmp("cd", e->var[0]) == 0\
				|| ft_strcmp("env", e->var[0]) == 0\
				|| ft_strcmp("setenv", e->var[0]) == 0 \
				|| ft_strcmp("unsetenv", e->var[0]) == 0)
			treat_case(e->var, e->env, e);
		else
		{
			e->var[0] = ft_strjoin("/", e->var[0]);
			e->cmd = test_cmd(e->lib, e->var[0], e->i);
			execve(e->cmd, e->var, e->env);
		}
	}
	else
		if (waitpid(father, &e->status, 0) != father)
			e->status = -1;
}

static void	set_counters(t_env *e)
{
	while (ft_strstr(e->env[e->i], "PATH") == NULL)
		e->i++;
	while (ft_strstr(e->env[e->j], "PWD") == NULL)
		e->j++;
	while (ft_strstr(e->env[e->k], "OLDPWD") == NULL)
		e->k++;
	while (ft_strstr(e->env[e->l], "HOME") == NULL)
		e->l++;
}

int			main(void)
{
	pid_t	father;
	t_env	e;

	if (!*environ)
		return (-1);
	e.i = 0;
	e.j = 0;
	e.k = 0;
	e.l = 0;
	e.env = copy_env(e.env, environ);
	set_counters(&e);
	e.lib = ft_strsplit(e.env[e.i], ':');
	print_header();
	while (1)
	{
		print_prompt(e);
		father = fork();
		start_process(&e, father);
		write(1, "\n", 1);
	}
	return (e.status);
}
