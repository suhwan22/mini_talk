/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 01:56:50 by suhkim            #+#    #+#             */
/*   Updated: 2022/09/30 02:49:20 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void	send_character(int pid, int c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (c % 2)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c /= 2;
		usleep(50);
	}
}

int	is_space(char c)
{
	if (c == '\n' || c == '\t' || c == '\r'
		|| c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	int		minus;
	int		ans;

	minus = 1;
	ans = 0;
	i = 0;
	while (is_space(*(str + i)))
		i++;
	while (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
			minus *= -1;
		i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		ans = ans * 10 + *(str + i) - '0';
		i++;
	}
	return (ans * minus);
}

int	main(int argc, char **argv)
{
	int	server_pid;

	server_pid = ft_atoi(argv[1]);
	if (argc != 3)
		return (0);
	else
	{
		while (*argv[2])
		{
			send_character(server_pid, *argv[2]);
			argv[2]++;
		}
	}
	return (0);
}
