/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:23:47 by miwasa            #+#    #+#             */
/*   Updated: 2024/12/05 11:35:52 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_params *params, int philo_id, char *action)
{
	long long	timestamp;

	timestamp = get_timestamp() - params->start_time;
	pthread_mutex_lock(&params->print_mutex);
	if (!params->someone_died)
		printf("%lld %d %s\n", timestamp, philo_id, action);
	pthread_mutex_unlock(&params->print_mutex);
}
