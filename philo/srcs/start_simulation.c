/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:38:09 by miwasa            #+#    #+#             */
/*   Updated: 2024/12/05 16:17:15 by miwasa           ###   ########.fr       */
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
	if (params->number_of_philosophers == 1)
		return (0);
	for (i = 0; i < params->number_of_philosophers; i++)
		pthread_join(params->philosophers[i].thread, NULL);
	return (0);
}

// int start_simulation(t_params *params)
// {
//     int i;

//     for (i = 0; i < params->number_of_philosophers; i++)
//     {
//         printf("Creating thread for philosopher %d\n", params->philosophers[i].id);
//         if (pthread_create(&params->philosophers[i].thread, NULL, philosopher_routine, &params->philosophers[i]) != 0)
//             return (1);
//         usleep(100); // スレッド開始のタイミングをずらす
//     }
//     printf("All philosopher threads created\n");

//     monitor_philosophers(params);

//     for (i = 0; i < params->number_of_philosophers; i++)
//     {
//         pthread_join(params->philosophers[i].thread, NULL);
//         printf("Joined thread for philosopher %d\n", params->philosophers[i].id);
//     }
//     return (0);
// }
