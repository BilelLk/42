/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:39:27 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/12 12:39:27 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_stack
{
	int	*a;
	int	len_a;
	int	*b;
	int	len_b;
	int	print;
	int	len;
}	t_stack;

typedef enum e_stacks
{
	NONE,
	A,
	B = 0,
	ALL,
}	t_stacks;

typedef enum e_find
{
	BIGGER,
	SMALLER,
}	t_find;

typedef enum e_bool
{
	false,
	true
}	t_bool;

	/*------------------------------------------/
	/				ALGORITHM					/
	/------------------------------------------*/

void	ft_sort_three(t_stack *stack);
void	ft_sort_little(t_stack *stack);
int		ft_side(int i, int len);
void	ft_best_move(t_stack *stack, t_stacks s, int index);
void	ft_best_rr(t_stack *stack, int *a, int *b);
int		ft_min(t_stack *stack);
int		ft_min_index(t_stack *stack);
void	ft_min_rotate(t_stack *stack, int *a, int *b);
int		ft_max(t_stack *stack);
int		ft_max_index(t_stack *stack);
int		ft_abs(int nb);

	/*------------------------------------------/
	/				UTILS						/
	/------------------------------------------*/

void	ft_error(t_stack *stack);
void	*ft_free_stack(t_stack *stack, t_stacks stacks);
void	ft_putstr(char *str);
void	ft_rotate_up(int *stack, int *len);
void	ft_rotate_down(int *stack, int *len);

	/*------------------------------------------/
	/				PARSING						/
	/------------------------------------------*/

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
t_stack	*ft_parsing_stack(int argc, char **argv);
int		ft_is_not_sorted(t_stack *a);
int		ft_duplicates_stack(t_stack *a);

	/*------------------------------------------/
	/				INSTRUCTIONS				/
	/------------------------------------------*/

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

	/*------------------------------------------/
	/				GET_NEXT_LINE				/
	/------------------------------------------*/

char	*get_next_line(int fd);
int		ft_strrchr(char *s, char c);
size_t	ft_strlen(const char *str);

#endif
