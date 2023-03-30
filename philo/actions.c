/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtabilas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:45:17 by jtabilas          #+#    #+#             */
/*   Updated: 2023/03/29 13:45:20 by jtabilas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

unsigned long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (printf("Error time \n"));
	return ((tv.tv_sec * (unsigned long)1000) + (tv.tv_usec / 1000));
}

void	messagges(char *str, t_philo *philo)
{
	unsigned long	time;
	printf("Sono qui\n");
	pthread_mutex_lock(&philo->data->write);
	time = get_time() - philo->data->start_time;
	if (strcmp("died", str) && philo->data->dead == 0)
	{
		printf("%lu %d %s\n", time, philo->id, str);
		philo->data->dead = 1;
	}
	if (!philo->data->dead)
		printf("%lu %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->write);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	messagges("is take a fork", philo);
	pthread_mutex_lock(philo->l_fork);
	messagges("is take a fork", philo);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	messagges("is sleeping", philo);
	ft_usleep(philo->data->sleep_time);
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->data->lock);
	philo->time_to_die = get_time() + philo->data->death_time;
	messagges("is eating ",philo);
	philo->eating = 1;
	philo->eat_count++;
	ft_usleep(philo->data->eat_time);
	pthread_mutex_unlock(&philo->data->lock);
	philo->eating = 0;
	drop_forks(philo);
}
