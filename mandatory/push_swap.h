/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:21:03 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/15 19:03:57 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>
# include	<stdbool.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define ERROR "Error\n"
# define ASCENDING 1
# define DESCENDING 0

/* **************************************************** */
/*                 🅻🅸🅽🅺🅴🅳 🅻🅸🆂🆃                   */
/* **************************************************** */
typedef struct node
{
	int			data;
	struct node	*next;
	struct node	*prev;

}	t_node;

/* **************************************************** */
/*                  🅳🅰🆃🅰 🆂🆃🆁🆄🅲🆃                  */
/* **************************************************** */
typedef struct data
{
	char	**holder;
	int		av_limit_number;
	int		pivot;
	int		limiter1;
	int		limiter2;
	t_node	*head;
	t_node	*pointer1;
	t_node	*pointer2;
}	t_data;

/* **************************************************** */
/*             🆁🅴🅶🆄🅻🅰🆁 🅵🆄🅽🅲🆃🅸🅾🅽🆂              */
/* **************************************************** */

long long int	ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *c);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2);

t_node	*initiate_linked_list(int ac, char **av, t_node *stack_a, t_data *data);

/* **************************************************** */
/*             🆂🅾🆁🆃🅸🅽🅶 🅵🆄🅽🅲🆃🅸🅾🅽🆂             */
/* **************************************************** */

void	push_to(t_node **stack_from, t_node **stack_to, char *operation, \
		int type);
void	delete_node(t_node **node);
void	first_to_end(t_node **node, char *operation, int type);
void	end_to_first(t_node **node, char *operation, int type);
void	swap_first_two(t_node **head, char *operation, int type);
void	ss(t_node **stack_a, t_node **stack_b, char *operation);
void	rrr(t_node **stack_a, t_node **stack_b, char *operation);
void	optimisation(t_node **stack_a, t_node **stack_b, t_data *data, int len);
void	benefits(t_node **stack_a, t_node **stack_b, int type);
int		push_to_b(t_node **stack_a, t_node **stack_b, t_data *data, int len);
int		push_to_a(t_node **stack_a, t_node **stack_b, t_data *data, int len);

/* **************************************************** */
/*                       🆄🆂🅴🅵🆄🅻                     */
/* **************************************************** */

int		sorted(t_node **stack, int order, int len);
void	push_errors(void);
int		protect(t_node **stack);
void	free_all(t_node **stack_a, t_node **stack_b, t_data *data);

/* **************************************************** */
/*                  🅿🅸🆅🅾🆃_🅲🅷🅾🆂🅴                   */
/* **************************************************** */

void	pivot_chose(t_node *stack, t_data *data, int len);

/* **************************************************** */
/*        🅻🅸🅽🅺🅴🅳 🅻🅸🆂🆃 🅵🆄🅽🅲🆃🅸🅾🅽🆂            */
/* **************************************************** */

t_node	*ft_lstnew(int data);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_back(int data, t_node **lst, t_node *new);
void	ft_lstadd_front(t_node *new_node, t_node **stack);
int		ft_lstsize(t_node *stack);

#endif