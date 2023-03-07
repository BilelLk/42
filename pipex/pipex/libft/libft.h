/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakehal <blakehal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:03:16 by blakehal          #+#    #+#             */
/*   Updated: 2023/03/07 14:40:17 by blakehal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
char	**ft_split(char const *s, char c);
void	*ft_memset(void *v, int c, size_t i);
void	*ft_memmove(void *v, const void *t, size_t i);
void	*ft_memcpy(void *v, const void *t, size_t i);
char	*ft_strchr(const char *s, int i);
char	*ft_strrchr(const char *s, int i);
char	*ft_strnstr(const char *s, const char *si, size_t i);
void	*ft_memchr(const void *v, int i, size_t j);
void	*ft_calloc(size_t i, size_t j);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int i, size_t j);
char	*ft_strjoin(char const *s, char const *s1);
char	*ft_strtrim(char const *s, char const *s1);
char	*ft_itoa(int i);
char	*ft_strmapi(char const *s, char (*f)(unsigned int i, char c));
size_t	ft_strlen(const char *s1);
size_t	ft_strlcpy(char *s, const char *s1, size_t i);
size_t	ft_strlcat(char *s, const char *s1, size_t i);
void	ft_bzero(void *v, size_t i);
void	ft_striteri(char *s, void (*f)(unsigned int i, char *s));
void	ft_putchar_fd(char c, int i);
void	ft_putstr_fd(char *s, int i);
void	ft_putendl_fd(char *s, int i);
void	ft_putnbr_fd(int i, int j);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int i);
int		ft_tolower(int i);
int		ft_strncmp(const char *s, const char *s1, size_t i);
int		ft_memcmp(const void *v, const void *s1, size_t i);
int		ft_atoi(const char *s);
int		ft_wordcount(char const *s, char c);
char	*ft_strndup(char *s, size_t n);
char	*ft_strncpy(char *dest, char *src, unsigned int n);

//GNL
char	*get_next_line(int fd);
char	*ft_read(int fd, char *tmp);
char	*ft_strjoint(char *line, char *buff);
char	*ft_implement(char *tmp);
char	*ft_clean(char *tmp);
int		ft_strerchr(char *s, char c);

//PRINTF
int		ft_putchar(char c);
int		ft_putnbr_base(unsigned int nbr, char *base);
int		ft_putstr(char *s);
int		ft_putnbr(int nbr);
int		ft_putptr_base(unsigned long long nbr, char *base);
int		ft_putunbr_base(unsigned int nbr, char *base);
int		ft_printf(const char *format, ...);

#endif
