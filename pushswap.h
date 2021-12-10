/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:55:33 by efinicke          #+#    #+#             */
/*   Updated: 2021/09/21 15:24:28 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int					data;
	int					position;
	struct s_list		*prev;
	struct s_list		*next;
}			t_list;

typedef struct s_loc
{
	t_list		*first;
	t_list		*last;
}			t_loc;

typedef struct s_config
{
	int		stack_sz;
	int		chunk_sz;
	int		chunk_nb;
	int		rest;
	int		top_moves;
	int		bot_moves;
	int		min;
	int		max;
}			t_config;

/*
 ** create stack functions :
 */
void				init_lst(t_loc *stack, char **argv);
void				add_new(t_list *prev, char *str, t_loc *stack);
void				create_stack_a(char **argv, t_loc *stack);

/*
 ** argv parsing functions :
 */
int					is_duplicated(int argc, char **argv);
int					is_digit(int argc, char **argv);
int					is_integer(int argc, char **argv);
int					is_arg_sorted(int argc, char **argv);
int					argv_parsing(int argc, char **argv);
int					is_nodes_sorted(t_list *first_node);

/*
 ** libft functions :
 */
long long int		ft_atoll(const char *str);
void				ft_putstr(char *str);
int					ft_strcmp(const char *s1, const char *s2);

/*
 ** lst tests functions :
 */
void				display_lst(t_loc *stack);
void				display_reversed_lst(t_loc *stack);

/*
 ** other lst functions :
 */
int					lstsize(t_loc *stack);
void				lstclear(t_loc *stack);

/*
 ** commands :
 */
void				command(t_loc *stack_a, t_loc *stack_b, char *str);
int					sa_sb(t_loc *stack);
int					ss(t_loc *stack_a, t_loc *stack_b);
int					ra_rb(t_loc *stack);
int					rr(t_loc *stack_a, t_loc *stack_b);
int					rra_rrb(t_loc *stack);
int					rrr(t_loc *stack_a, t_loc *stack_b);
int					pa_pb(t_loc *stack_a, t_loc *stack_b);
void				ergo_pa_pb(t_list *front, t_loc *stack_dest, int i);

/*
 ** stack parsing :
 */
int					is_ready_to_sort(t_loc *stack);
int					find_mid(t_loc *stack_a);
void				define_position(t_loc *stack_a);
int					find_smallest_nbr_position(t_loc *stack_a);
int					find_highest_nbr_position(t_loc *stack);
int					find_highest_nbr(t_loc *stack);
int					find_smallest_nbr(t_loc *stack);
int					define_chunks_nbr(int len);
void				chunks_config(t_config *config, t_loc *stack_a);
void				define_chunk_limits(t_config *config, int chunk);
int					is_chunk_nbr_here(t_config *config, t_loc *stack);
int					find_top_moves_nbr(t_loc *stack, t_config *config);
int					find_bot_moves_nbr(t_loc *stack, t_config *config);
void				move_smallest_up(t_loc *stack_a, t_loc *stack_b);

/*
 ** algo1
 */
void				go_algo(t_loc *stack_a, t_loc *stack_b, t_config *config);
void				until_three_sort(t_loc *stack_a, t_loc *stack_b);
void				pb_mid_sort(t_loc *stack_a, t_loc *stack_b);
void				algo_five(t_loc *stack_a, t_loc *stack_b);
int					simple_sort(t_loc *stack_a, t_loc *stack_b);

/*
 ** algo2
 */
void				chunks_pb(t_config *config, t_loc *stack_a, t_loc *stack_b);
void				chunk_pb(t_config *config, t_loc *stack_a, t_loc *stack_b);
void				move_at_first_place(t_loc *stack_a, t_loc *stack_b,
						t_config *config);
void				optim(t_loc *stack_a, t_loc *stack_b);
void				pa_mid_sort(t_loc *stack_src, t_loc *stack_dst);

#endif
