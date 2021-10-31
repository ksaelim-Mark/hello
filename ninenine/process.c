/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slertpim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 01:18:17 by slertpim          #+#    #+#             */
/*   Updated: 2021/10/31 15:56:11 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		valid_duplicate(int metric[9][9], int height, int position);
int		algorithm(int metric[9][9], int input[36], int position);
int		verify_input(int metric[9][9], int input[36], int position);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);

int	*transform_int(char *argv)
{
	int	i;
	int	j;
	int	*input;

	i = 0;
	j = 0;
	input = malloc(sizeof(int) * 36);
	while (argv[i])
	{
		if (argv[i] >= '0' && argv[i] <= '9')
		{
			input[j] = argv[i] - 48;
			j++;
		}
		i++;
	}
	return (input);
}

int	algorithm(int metric[9][9], int input[36], int position)
{
	int	height;
	int	col;
	int	row;

	height = 1;
	if (position == 72)
		return (1);
	while (height <= 9)
	{
		if (valid_duplicate(metric, height, position) == 0)
		{
			col = position % 9;
			row = position / 9;
			metric[row][col] = height;
			if (verify_input(metric, input, position) == 0)
			{
				if (algorithm(metric, input, position + 1) == 1)
					return (1);
			}
			else
				metric[row][col] = 0;
		}
		height++;
	}
	return (0);
}

void	print_result(int metric[9][9])
{
	int	i;
	int	j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			ft_putnbr(metric[i][j]);
			if (j < 8)
				ft_putstr(" ");
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}
