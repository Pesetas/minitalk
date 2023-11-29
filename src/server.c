/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antramir <antramir@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:45:08 by antramir          #+#    #+#             */
/*   Updated: 2023/03/10 01:23:44 by antramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static char	*g_str;

static void	ft_print_char(char *str)
{
	int	pos;
	int	num;
	int	bit;
	int	exp;

	num = 0;
	pos = 0;
	exp = 2;
	while (str[pos])
	{
		if (str[pos] == '0')
			bit = 0;
		else
			bit = 1;
		if (pos == 0)
			num = bit;
		else
		{
			num = num + (bit * exp);
			exp = exp * 2;
		}
		pos++;
	}
	write(STDOUT_FILENO, &num, 1);
}

static void	ft_handle(int sig)
{
	static int	i;

	if (sig == SIGUSR1)
		g_str[i++] = '0';
	if (sig == SIGUSR2)
		g_str[i++] = '1';
	usleep(5);
	if (i == 8)
	{
		g_str[i] = '\0';
		ft_print_char(g_str);
		i = 0;
	}
}

int	main(void)
{
	g_str = malloc(sizeof(char) * 8 + 1);
	write(STDOUT_FILENO, "pid: ", 6);
	ft_putnbr_fd(getpid(), 1);
	write(STDOUT_FILENO, "\n", 1);
	signal(SIGUSR1, ft_handle);
	signal(SIGUSR2, ft_handle);
	while (1)
		pause();
}
