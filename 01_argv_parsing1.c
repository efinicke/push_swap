/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_argv_parsing1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:23:27 by efinicke          #+#    #+#             */
/*   Updated: 2021/09/21 16:37:52 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** parsing verification : 
*/
int	argv_parsing(int argc, char **argv)
{
	if (is_digit(argc, argv) == 0 || is_integer(argc, argv) == 0
		|| is_duplicated(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

/*
 ** return 1 : is integer
 */
int	is_integer(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if ((atoll(argv[i]) > INT_MAX) || (atoll(argv[i]) < INT_MIN))
			return (0);
	}
	return (1);
}

/*
** Return 1 : argv sorted.
*/
int	is_arg_sorted(int argc, char **argv)
{
	int	i;

	i = 0;
	while ((++i < argc) && argv[i + 1])
	{
		if (ft_atoll(argv[i]) > ft_atoll(argv[i + 1]))
			return (0);
	}
	return (1);
}

/*
** Return 1 : argv duplicated.
*/
int	is_duplicated(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while ((i < argc) && argv[i + 1])
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoll(argv[i]) == ft_atoll(argv[j++]))
				return (1);
		}
		i++;
	}
	return (0);
}

/*
** Return 1 : argv are digits. 
*/
int	is_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (j == 0 && (argv[i][j] == '-' || argv[i][j] == '+'))
			{
				if (argv[i][j + 1] < '0' || argv[i][j + 1] > '9')
					return (0);
			}
			else if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
		}
	}
	return (1);
}
