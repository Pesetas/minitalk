/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antramir <antramir@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:45:01 by antramir          #+#    #+#             */
/*   Updated: 2023/03/10 01:38:02 by antramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static char	*char_to_binary(char *bin, char c)
{
	int		i;

	i = 0;
	while ((c / 2) >= 1)
	{
		bin[i++] = (c % 2) + '0';
		c = c / 2;
	}
	bin[i++] = c + '0';
	while (i < 8)
		bin[i++] = '0';
	bin[i] = '\0';
	return (bin);
}

static void	ft_signal_send(pid_t server_pid, char argv)
{
	char	*bin;
	int		i;

	bin = malloc(sizeof(char) * 8 + 1);
	bin = char_to_binary(bin, argv);
	i = 0;
	while (bin[i] != '\0')
	{
		if (ft_strncmp(&bin[i], "0", 1) == 0)
			kill(server_pid, SIGUSR1);
		if (ft_strncmp(&bin[i], "1", 1) == 0)
			kill(server_pid, SIGUSR2);
		i++;
		usleep(50);
	}
	free(bin);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	int		i;

	if (argc != 3)
	{
		write(STDOUT_FILENO, "Error de input", 14);
		return (0);
	}
	server_pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		ft_signal_send(server_pid, argv[2][i]);
		i++;
	}
	return (0);
}
