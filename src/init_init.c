/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:38:14 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/28 15:47:59 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/split_params.h"

static int	count_argc(char **argv)
{
	int	len;

	len = 0;
	while (argv[len])
		++len;
	return (len);
}

void	init_init(int *i, int *argc, char ***argv)
{
	*i = 0;
	++(*argv);
	--(*argc);
}

void	set_argv_argc(int *argc, char ***argv, int *flag_clean_argv)
{
	*argv = split_params((*argv)[0], ' ');
	*argc = count_argc(*argv);
	*flag_clean_argv = 1;
}
