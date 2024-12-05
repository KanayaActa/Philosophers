/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:04:58 by miwasa            #+#    #+#             */
/*   Updated: 2024/12/05 13:41:37 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philosopher
{
	int				id;
	int				left_fork_id;
	int				right_fork_id;
	long long		last_meal_time;
	int				meals_eaten;
	pthread_t		thread;
	struct s_params	*params;
	void			(*take_forks)(struct s_philosopher *self);
	void			(*put_forks)(struct s_philosopher *self);
	void			(*eat)(struct s_philosopher *self);
	void			(*sleep)(struct s_philosopher *self);
	void			(*think)(struct s_philosopher *self);
}	t_philosopher;

typedef struct s_params
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t meal_time_mutex; 
	t_philosopher	*philosophers;
	int				someone_died;
}	t_params;

// void		philo(int argc, char **argv);

// // == philo_action ==
// void		philo_take_forks(t_philosopher *self);
// void		philo_put_forks(t_philosopher *self);
// void		philo_eat(t_philosopher *self);
// void		philo_sleep(t_philosopher *self);
// void		philo_think(t_philosopher *self);

// // == get_timestamp ==
// long long	get_timestamp(void);

// // == print_action ==
// void		print_action(t_params *params, int philo_id, char *action);

int			philo(int argc, char **argv);
int			parse_arguments(int argc, char **argv, t_params *params);
int			init_simulation(t_params *params);
void		init_philosophers(t_params *params);
int			start_simulation(t_params *params);
void		*philosopher_routine(void *arg);
void		monitor_philosophers(t_params *params);
void		print_action(t_params *params, int philo_id, char *action);
long long	get_timestamp();
void		sleep_ms(int milliseconds);
void		cleanup(t_params *params);

// 哲学者の行動関数
void		philo_take_forks(t_philosopher *self);
void		philo_put_forks(t_philosopher *self);
void		philo_eat(t_philosopher *self);
void		philo_sleep(t_philosopher *self);
void		philo_think(t_philosopher *self);

#endif