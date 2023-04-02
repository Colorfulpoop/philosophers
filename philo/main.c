/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtabilas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:55:14 by jtabilas          #+#    #+#             */
/*   Updated: 2023/03/28 13:55:16 by jtabilas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	case_one(t_data *data)
{
	data->start_time = get_time();
	if (pthread_create(&data->tid[0], NULL, &routine, &data->philos[0]))
			return (print_error(0));
	pthread_detach(data->tid[0]);
	while (data->dead == 0)
	{
		ft_usleep(0);
	}
	return (0);
}

void	clear_alloc(t_data *data)
{
	if (data->philos)
			free(data->philos);
	if (data->tid)
			free(data->tid);
	if (data->forks)
			free(data->forks);
}

void	ft_exit(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].lock);
		i++;
	}
	pthread_mutex_destroy(&data->lock);
	pthread_mutex_destroy(&data->write);
	clear_alloc(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
	{
		print_error(1);
		return (1);
	}
	if (input_checker(argv))
			return (1);
	if (init(argc, argv, &data))
			return (1);
	if (data.philo_num == 1)
			case_one(&data);
	if (run_thread(&data))
			return (1);
	ft_exit(&data);
	return (0);
}
