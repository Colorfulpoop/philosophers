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
	// if (data.philo_num == 1)
		// caso uno
	if (run_thread(&data))
		return (1);
	// ft_exit
	return (0);
}
