/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:05:56 by miwasa            #+#    #+#             */
/*   Updated: 2024/12/05 12:27:01 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo(int argc, char **argv)
{
	t_params	params;

	if (parse_arguments(argc, argv, &params) != 0)
	{
		printf("Invalid arguments\n");
		return (1);
	}
	if (init_simulation(&params) != 0)
	{
		printf("Failed to initialize simulation\n");
		return (1);
	}
	if (start_simulation(&params) != 0)
	{
		printf("Failed to start simulation\n");
		return (1);
	}
	cleanup(&params);
	return (0);
}
