/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 00:18:22 by fmorales          #+#    #+#             */
/*   Updated: 2013/12/29 23:32:47 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftsh.h"

void	print_header(void)
{
	ft_putstr("\n\n");
	ft_putstr("\t\t\t\t\t     :::   :::   ::::::::::: ::::    ::: ");
	ft_putstr("::::::::::: ");
	ft_putstr("::::::::  :::    ::: :::::::::: :::        :::\n");
	ft_putstr("\t\t\t\t\t   :+:+: :+:+:      :+:     :+:+:   :+:     ");
	ft_putstr(":+:    ");
	ft_putstr(":+:    :+: :+:    :+: :+:        :+:        :+:\n");
	ft_putstr("\t\t\t\t\t +:+ +:+:+ +:+     +:+     :+:+:+  +:+     ");
	ft_putstr("+:+    +:+");
	ft_putstr("\t     +:+    +:+ +:+        +:+        +:+\n");
	ft_putstr("\t\t\t\t        +#+  +:+  +#+     +#+     +#+ +:+ ");
	ft_putstr("+#+     +#+    ");
	ft_putstr("+#++:++#++ +#++:++#++ +#++:++#   +#+        +#+\n");
	ft_putstr("\t\t\t\t       +#+       +#+     +#+     +#+  +#+#+#");
	ft_putstr("	 +#+\t       +#+ ");
	ft_putstr("+#+    +#+ +#+        +#+        +#+\n");
	ft_putstr("\t\t\t\t      #+#       #+#     #+#     #+#   #+#+#");
	ft_putstr("\t#+#    #+#    #+# #+#\t ");
	ft_putstr("#+# #+#        #+#        #+#\n");
	ft_putstr("\t\t\t\t     ###       ### ########### ###");
	ft_putstr("    #### ########### ########  ###\t");
	ft_putendl("### ########## ########## ##########");
	ft_putendl("\n\n\t\t\t\t\t\t\t\t\t   L'ANCETRE D'INTERNECHE\n\n\n");
}

void	print_prompt(t_env e)
{
	ft_putstr(ft_strsub(e.env[e.j], 4, ft_strlen(e.env[e.j])));
	write(1, " >> ", 4);
}
