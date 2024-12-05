/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:10:11 by miwasa            #+#    #+#             */
/*   Updated: 2024/12/05 12:58:41 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_take_forks(t_philosopher *self)
{
	t_params	*params;

	params = self->params;
	pthread_mutex_lock(&params->forks[self->left_fork_id]);
	print_action(params, self->id, "has taken a fork");
	pthread_mutex_lock(&params->forks[self->right_fork_id]);
	print_action(params, self->id, "has taken a fork");
}

void	philo_put_forks(t_philosopher *self)
{
	t_params	*params;

	params = self->params;
	pthread_mutex_unlock(&params->forks[self->left_fork_id]);
	pthread_mutex_unlock(&params->forks[self->right_fork_id]);
}

void	philo_eat(t_philosopher *self)
{
	t_params	*params;

	params = self->params;
	pthread_mutex_lock(&params->print_mutex);
	self->last_meal_time = get_timestamp();
	print_action(params, self->id, "is eating");
	pthread_mutex_unlock(&params->print_mutex);

	sleep_ms(params->time_to_eat);
	self->meals_eaten++;
}

void	philo_sleep(t_philosopher *self)
{
	t_params	*params;

	params = self->params;
	print_action(params, self->id, "is sleeping");
	sleep_ms(params->time_to_sleep);
}

void	philo_think(t_philosopher *self)
{
	t_params	*params;

	params = self->params;
	print_action(params, self->id, "is thinking");
}
