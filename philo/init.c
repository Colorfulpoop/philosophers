/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtabilas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:20:19 by jtabilas          #+#    #+#             */
/*   Updated: 2023/03/29 10:20:21 by jtabilas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	alloc(t_data *data)
{
	data->philos = malloc (sizeof(t_philo) * data->philo_num);
	if (!data->philos)
		return (print_error(3));
	data->tid = malloc (sizeof(pthread_t) * data->philo_num);
	if (!data->tid)
		return (print_error(3));
	data->forks = malloc (sizeof(pthread_mutex_t) * data->philo_num);
	if (!data->forks)
		return (print_error(3));
	return (0);
}

int	init_data(int argc, char **argv, t_data *data)
{
	data->philo_num = (int) ft_atoi(argv[1]);
	data->death_time = (unsigned long) ft_atoi(argv[2]);
	data->eat_time = (unsigned long) ft_atoi(argv[3]);
	data->sleep_time = (unsigned long) ft_atoi(argv[4]);
	if (argc == 6)
		data->meals_nb = (int) ft_atoi(argv[5]);
	if (data->philo_num <= 0 || data->philo_num > 200 || data->death_time <= 1
		|| data->eat_time <= 1 || data->sleep_time <= 1)
		return (print_error(2), 1);
	data->dead = 0;
	data->finished = 0;
	pthread_mutex_init (&data->write, NULL);
	pthread_mutex_init (&data->lock, NULL);
	return (0);
}

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_init (&data->forks[i], NULL);
		i++;
	}
	i = 1;
	data->philos[0].r_fork = &data->forks[0];
	data->philos[0].l_fork = &data->forks[data->philo_num - 1];
	while (i < data->philo_num)
	{
		data->philos[i].r_fork = &data->forks[i];
		data->philos[i].l_fork = &data->forks[i - 1];
		i++;
	}
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].time_to_die = data->death_time;
		data->philos[i].eat_count = 0;
		data->philos[i].status = 0;
		data->philos[i].eating = 0;
		pthread_mutex_init (&data->philos[i].lock, NULL);
		i++;
	}
	return (0);
}

int	init(int argc, char **argv, t_data *data)
{
	if (init_data(argc, argv, data))
		return (1);
	if (alloc(data))
		return (1);
	if (init_forks(data))
		return (1);
	init_philo(data);
	return (0);
}
