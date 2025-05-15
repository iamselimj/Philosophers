#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_rules	t_rules;
typedef struct s_philo	t_philo;

struct					s_rules
{
	int					nb_philos;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					meals_required;
	int					someone_died;
	long				start_time;
	pthread_mutex_t		*forks;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		meal_check;
	t_philo				*philos;
};

struct					s_philo
{
	int					id;
	int					meals_eaten;
	long				last_meal_time;
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_rules				*rules;
};

int						init_all(t_rules *rules, int argc, char **argv);
void					cleanup(t_rules *rules);
void					*philo_routine(void *arg);
void					start_simulation(t_rules *rules);

long					get_time(void);
void					safe_print(t_philo *philo, char *msg);
void					ft_usleep(long duration);
int						ft_atoi(const char *str);
int						error_exit(char *msg);

#endif
