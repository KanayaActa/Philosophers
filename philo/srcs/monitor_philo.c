/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:30:44 by miwasa            #+#    #+#             */
/*   Updated: 2024/12/05 13:16:41 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void monitor_philosophers(t_params *params)
{
	int i;
	int all_eaten;

	while (!params->someone_died)
	{
		i = 0;
		all_eaten = 1;
		while (i < params->number_of_philosophers)
		{
			pthread_mutex_lock(&params->print_mutex);
			if (get_timestamp() - params->philosophers[i].last_meal_time > params->time_to_die)
			{
				print_action(params, params->philosophers[i].id, "died");
				params->someone_died = 1;
				pthread_mutex_unlock(&params->print_mutex);
				break;
			}
			if (params->number_of_times_each_philosopher_must_eat != -1 &&
				params->philosophers[i].meals_eaten < params->number_of_times_each_philosopher_must_eat)
			{
				all_eaten = 0;
			}
			pthread_mutex_unlock(&params->print_mutex);
			i++;
		}
		if (all_eaten && params->number_of_times_each_philosopher_must_eat != -1)
		{
			params->someone_died = 1;
			break;
		}
		usleep(1000); // 1ms 待機
	}
}
