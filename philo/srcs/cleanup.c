/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:32:55 by miwasa            #+#    #+#             */
/*   Updated: 2024/12/05 20:24:50 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void cleanup(t_params *params)
{
	int	i;

	for (i = 0; i < params->number_of_philosophers; i++)
		pthread_mutex_destroy(&params->forks[i]);
	pthread_mutex_destroy(&params->print_mutex);
	pthread_mutex_destroy(&params->meal_time_mutex);
	pthread_mutex_destroy(&params->finish_mutex);
	free(params->forks);
	free(params->philosophers);
}
