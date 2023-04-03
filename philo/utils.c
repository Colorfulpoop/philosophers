/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtabilas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:53:07 by jtabilas          #+#    #+#             */
/*   Updated: 2023/03/29 09:53:08 by jtabilas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
	{
		return (1);
	}
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	nb;
	int	i;
	int	neg;

	nb = 0;
	i = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]) == 1)
		nb = nb * 10 + str[i++] - 48;
	return (neg * nb);
}

int	print_error(int flag)
{
	if (flag == 1)
	{
		printf("Try ./philo number_of_philosophers"
			" time_to_die time_to_eat time_to_sleep"
			" [number_of_times_each_philosopher_must_eat] \n");
	}
	else if (flag == 0)
		printf("Error\n");
	else if (flag == 2)
		printf("Invalid input\n");
	else if (flag == 3)
		printf("Invalid alloc\n");
	return (0);
}

int	ft_usleep(useconds_t time)
{
	u_int64_t	start;

	start = get_time();
	while ((get_time() - start) < time)
	{
		usleep(time / 10);
	}
	return (0);
}

int	input_checker(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
			{
				j++;
				continue ;
			}
			else if ((argv[i][j] < 48 || argv[i][j] > 57))
				return (print_error(0), 1);
			j++;
		}
		i++;
	}
	return (0);
}
