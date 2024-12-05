/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:16:31 by miwasa            #+#    #+#             */
/*   Updated: 2024/12/05 13:48:51 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;
	t_params		*params;

	philo = (t_philosopher *)arg;
	params = philo->params;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!params->someone_died)
	{
		philo->think(philo);
		philo->take_forks(philo);
		philo->eat(philo);
		philo->put_forks(philo);
		philo->sleep(philo);
	}
	return (NULL);
}
