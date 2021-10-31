/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slertpim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 00:58:24 by slertpim          #+#    #+#             */
/*   Updated: 2021/10/31 15:17:50 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		verify_format(int argc, char **argv);
int		algorithm(int metric[4][4], int input[16], int position);
int		*transform_int(char *argv);
void	print_result(int metric[4][4]);
void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	int	*input;
	int	metric[4][4];
	int	i;

	i = 0;
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
