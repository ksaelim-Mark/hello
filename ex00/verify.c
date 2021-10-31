/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slertpim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 02:26:25 by slertpim          #+#    #+#             */
/*   Updated: 2021/10/31 13:06:43 by slertpim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str);
int	valid_top(int metric[4][4], int input[16], int position);
int	valid_bottom(int metric[4][4], int input[16], int position);
int	valid_left(int metric[4][4], int input[16], int position);
int	valid_right(int metric[4][4], int input[16], int position);

int	verify_format(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	if (ft_strlen(argv[1]) != 31)
		return (1);
	return (0);
}

int	verify_input(int metric[4][4], int input[16], int position)
{
	if (valid_top(metric, input, position) == 1)
		return (1);
	if (valid_bottom(metric, input, position) == 1)
		return (1);
	if (valid_left(metric, input, position) == 1)
		return (1);
	if (valid_right(metric, input, position) == 1)
		return (1);
	return (0);
}
