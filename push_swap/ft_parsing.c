/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:39:38 by blakehal          #+#    #+#             */
/*   Updated: 2023/01/25 16:37:38 by blakehal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_wordcounter(char const *s, char c)
{
	int	wordcount;
	int	i;

	wordcount = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
			i++;
		}
		if (s[i] == '\0')
			break ;
		while (s[i] && s[i] != c)
			i++;
		wordcount++;
	}
	return (wordcount);
}

static t_stack	*ft_malloc_parsing(int ac, char **av)
{
	t_stack	*stack;
	int		i;
	int		wordcount;

	i = 0;
	wordcount = 0;
	while (i < ac)
		wordcount += ft_wordcounter(av[i++], ' ');
	if (!wordcount)
		return (write(2, "Error\n", 6), exit(1), NULL);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		exit (0);
	ft_bzero(stack, sizeof(t_stack));
	stack->a = malloc(wordcount * sizeof(int));
	stack->b = malloc(wordcount * sizeof(int));
	if (!stack->a || !stack->b)
		return (ft_free_all(stack, BIGGER), NULL);
	stack->len_a = wordcount;
	stack->len_b = 0;
	return (stack);
}

static void	ft_is_eligible(char *argv, int k, t_stack *stack)
{
	long long int	max;
	int				i;
	int				sign;

	i = 0;
	max = 0;
	sign = 1;
	if (argv[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	if (!argv[i])
		return (ft_error(stack));
	if (argv[i] <= '0' && argv[i] >= '9')
		return (ft_error(stack));
	while (argv[i] >= '0' && argv[i] <= '9')
	{
		max = max * 10 + ((argv[i] - '0') * sign);
		i++;
	}
	if (argv[i] || (max < INT_MIN || max > INT_MAX))
		return (ft_error(stack));
	stack->a[k] = (int)max;
}

static void	ft_malloc_clear_parsing(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

t_stack	*ft_parsing_stack(int argc, char **argv)
{
	t_stack	*sta;
	int		i;
	int		j;
	int		k;
	char	**split;

	sta = ft_malloc_parsing(argc, argv);
	j = 0;
	i = 0;
	k = 0;
	while (j < argc)
	{
		if (argv[j][0] == '\0')
			return (ft_error(sta), NULL);
		split = ft_split(argv[j], ' ');
		if (!split)
			ft_free_all(sta, BIGGER);
		while (split[i])
			ft_is_eligible(split[i++], k++, sta);
		ft_malloc_clear_parsing(split);
		i = 0;
		j++;
	}
	return (sta);
}
