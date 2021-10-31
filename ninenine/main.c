/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slertpim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 00:58:24 by slertpim          #+#    #+#             */
/*   Updated: 2021/10/31 15:17:23 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		verify_format(int argc, char **argv);
int		algorithm(int metric[9][9], int input[36], int position);
int		*transform_int(char *argv);
void	print_result(int metric[9][9]);
void	ft_putstr(char *str);
void	ft_putchar(char c);

int	main(int argc, char **argv)
{
	int	*input;
	int	metric[9][9];

	if (verify_format(argc, argv) == 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	input = transform_int(argv[1]);
	if (algorithm(metric, input, 0) == 1)
	{
		print_result(metric);
	}
	else
		ft_putstr("Error\n");
	return (0);
}
