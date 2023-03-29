/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtabilas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:36:50 by jtabilas          #+#    #+#             */
/*   Updated: 2023/03/29 13:36:52 by jtabilas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	routine(t_data *data)
{
	
}

int	run_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_create(&data->tid[i], NULL, &routine, &data->philos[i]);
		i++;
	}
}
