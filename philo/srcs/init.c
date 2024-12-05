/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:29:01 by miwasa            #+#    #+#             */
/*   Updated: 2024/12/05 12:53:40 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_simulation(t_params *params)
{
	int i;

	params->forks = malloc(sizeof(pthread_mutex_t) * params->number_of_philosophers);
	if (!params->forks)
		return (1);
	for (i = 0; i < params->number_of_philosophers; i++)
		pthread_mutex_init(&params->forks[i], NULL);
	pthread_mutex_init(&params->print_mutex, NULL);
	params->philosophers = malloc(sizeof(t_philosopher) * params->number_of_philosophers);
	if (!params->philosophers)
		return (1);

	// start_time を哲学者の初期化前に設定
	params->start_time = get_timestamp();

	init_philosophers(params);
	params->someone_died = 0;
	return (0);
}

void	init_philosophers(t_params *params)
{
	int	i;

	for (i = 0; i < params->number_of_philosophers; i++)
	{
		params->philosophers[i].id = i + 1;
		params->philosophers[i].left_fork_id = i;
		params->philosophers[i].right_fork_id = (i + 1) % params->number_of_philosophers;
		params->philosophers[i].last_meal_time = params->start_time; // start_time を使用
		params->philosophers[i].meals_eaten = 0;
		params->philosophers[i].params = params;

		// 関数ポインタの割り当て
		params->philosophers[i].take_forks = philo_take_forks;
		params->philosophers[i].put_forks = philo_put_forks;
		params->philosophers[i].eat = philo_eat;
		params->philosophers[i].sleep = philo_sleep;
		params->philosophers[i].think = philo_think;
	}
}