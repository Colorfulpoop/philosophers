/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtabilas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:55:23 by jtabilas          #+#    #+#             */
/*   Updated: 2023/03/28 13:55:24 by jtabilas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
#include <string.h>

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		t1;
	int				id;
	int				eat_count;
	int				status;
	int				eating;
	unsigned long	time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_data
{
	pthread_t		*tid;
	int				philo_num;
	int				meals_nb;
	int				dead;
	int				finished;
	t_philo			*philos;
	unsigned long	death_time;
	unsigned long	eat_time;
	unsigned long	sleep_time;
	unsigned long	start_time;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
	pthread_mutex_t	*forks;
}	t_data;

int				print_error(int flag);
void			messagges(char *str, t_philo *philo);
void			take_forks(t_philo *philo);
void			drop_forks(t_philo *philo);
void			eat(t_philo *philo);
int				input_checker(char **argv);
int				ft_atoi(const char *str);
int				init(int argc, char **argv, t_data *data);
int				ft_usleep(useconds_t time);
int				run_thread(t_data *data);
unsigned long	get_time(void);


#endif
