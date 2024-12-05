/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:38:09 by miwasa            #+#    #+#             */
/*   Updated: 2024/12/05 12:38:36 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_simulation(t_params *params)
{
	int	i;

	params->start_time = get_timestamp();
	for (i = 0; i < params->number_of_philosophers; i++)
	{
		if (pthread_create(&params->philosophers[i].thread, NULL, philosopher_routine, &params->philosophers[i]) != 0)
			return (1);
		usleep(100);
	}
	monitor_philosophers(params);
	for (i = 0; i < params->number_of_philosophers; i++)
		pthread_join(params->philosophers[i].thread, NULL);
	return (0);
}
