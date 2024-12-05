/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:16:31 by miwasa            #+#    #+#             */
/*   Updated: 2024/12/05 20:48:13 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	*philosopher_routine(void *arg)
// {
// 	t_philosopher	*philo;
// 	t_params		*params;

// 	philo = (t_philosopher *)arg;
// 	params = philo->params;
// 	if (philo->id % 2 == 0)
// 		usleep(1000);
// 	while (!params->someone_died)
// 	{
// 		philo->think(philo);
// 		philo->take_forks(philo);
// 		philo->eat(philo);
// 		philo->put_forks(philo);
// 		philo->sleep(philo);
// 	}
// 	return (NULL);
// }

void *philosopher_routine(void *arg)
{
    t_philosopher *philo = (t_philosopher *)arg;
    t_params *params = philo->params;

    // printf("Philosopher %d started\n", philo->id);

    if (philo->id % 2 == 0)
    {
        // printf("Philosopher %d is even, sleeping to prevent deadlock\n", philo->id);
        usleep(100); // デッドロック防止のための待機
    }
    while (/*!params->someone_died && !params->all_philosophers_finished*/ 1)
    {
		 // **ここで食事回数のチェックを行う**
        pthread_mutex_lock(&params->meal_time_mutex);
        if (params->number_of_times_each_philosopher_must_eat != -1 &&
            philo->meals_eaten >= params->number_of_times_each_philosopher_must_eat)
        {
            pthread_mutex_unlock(&params->meal_time_mutex);
            break;
        }
        pthread_mutex_unlock(&params->meal_time_mutex);

        // 誰かが死亡していないか確認
        if (params->someone_died)
            break;

        philo->think(philo);
        philo->take_forks(philo);

        // **食事前に再度チェック**
        pthread_mutex_lock(&params->meal_time_mutex);
        if (params->number_of_times_each_philosopher_must_eat != -1 &&
            philo->meals_eaten >= params->number_of_times_each_philosopher_must_eat)
        {
            pthread_mutex_unlock(&params->meal_time_mutex);
            philo->put_forks(philo); // フォークを戻す
            break;
        }
        pthread_mutex_unlock(&params->meal_time_mutex);
        // philo->think(philo);
        // philo->take_forks(philo);
        philo->eat(philo);
        philo->put_forks(philo);
        philo->sleep(philo);
    }

    // printf("Philosopher %d finished\n", philo->id);
    return (NULL);
}
