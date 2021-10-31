/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slertpim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 02:26:25 by slertpim          #+#    #+#             */
/*   Updated: 2021/10/31 13:07:24 by slertpim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	valid_duplicate(int metric[4][4], int height, int position)
{
	int	i;
	int	row;
	int	col;

	i = 0;
	row = position / 4;
	col = position % 4;
	while (i < row)
	{
		if (metric[i][col] == height)
			return (1);
		i++;
	}
	i = 0;
	while (i < col)
	{
		if (metric[row][i] == height)
			return (1);
		i++;
	}
	return (0);
}

int	valid_top(int metric[4][4], int input[16], int position)
{
	int	i;
	int	max;
	int	count_higher;
	int	col;

	i = 0;
	max = 0;
	count_higher = 0;
	col = position % 4;
	if (position / 4 == 3)
	{
		while (i < 4)
		{
			if (metric[i][col] > max)
			{
				max = metric[i][col];
				count_higher++;
			}
			i++;
		}
		if (input[col] != count_higher)
			return (1);
	}
	return (0);
}

int	valid_bottom(int metric[4][4], int input[16], int position)
{
	int	i;
	int	max;
	int	count_higher;
	int	col;

	i = 3;
	max = 0;
	count_higher = 0;
	col = position % 4;
	if (position / 4 == 3)
	{
		while (i >= 0)
		{
			if (metric[i][col] > max)
			{
				max = metric[i][col];
				count_higher++;
			}
			i--;
		}
		if (input[4 + col] != count_higher)
			return (1);
	}
	return (0);
}

int	valid_left(int metric[4][4], int input[16], int position)
{
	int	i;
	int	max;
	int	count_higher;
	int	row;

	i = 0;
	max = 0;
	count_higher = 0;
	row = position / 4;
	if (position % 4 == 3)
	{
		while (i < 4)
		{
			if (metric[row][i] > max)
			{
				max = metric[row][i];
				count_higher++;
			}
			i++;
		}
		if (input[8 + row] != count_higher)
			return (1);
	}
	return (0);
}

int	valid_right(int metric[4][4], int input[16], int position)
{
	int	i;
	int	max;
	int	count_higher;
	int	row;

	i = 3;
	max = 0;
	count_higher = 0;
	row = position / 4;
	if (position % 4 == 3)
	{
		while (i >= 0)
		{
			if (metric[row][i] > max)
			{
				max = metric[row][i];
				count_higher++;
			}
			i--;
		}
		if (input[12 + row] != count_higher)
			return (1);
	}
	return (0);
}
