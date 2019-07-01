/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:09:29 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/28 00:13:34 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

# define MIN_INT -2147483648
# define MAX_INT 2147483647
# define BUFF_SIZE 1000
# define MAX_FD 4864

typedef struct s_list	t_list;
typedef struct s_string	t_string;

struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
};
struct	s_string
{
	char	*s;
	size_t	size;
};
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char const *str);
void	ft_putendl(char const *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strcat(char *s1, char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);
void	*ft_realloc(void *ptr, size_t oldsize, size_t newsize);
char	**ft_push_str(char **tab, char *s);
char	*ft_push_char(char *tab, char c);
char	*ft_push_nbr(char *s, int n);
size_t	ft_nbrlen(int n);
size_t	ft_bsize(const void *ptr);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_next_char(const char *s);
char	*ft_build_nbr(const char *s);
void	*ft_next_byte(const void *s);
int		ft_atonbr(char *s);
int		ft_todigit(int c);
int		ft_atoi(const char *str);
void	*ft_memdup(void const *src, size_t n);
void	*ft_lstset(t_list **elm, void const *content, size_t content_size);
t_list	*ft_lstnew(void	const *content, size_t content_size);
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void	ft_lstadd(t_list **alst, t_list *new);
t_list	*ft_lstpush(t_list *elm, t_list *new);
void	*ft_memdupz(void const *src, size_t n);
void	*ft_memjoin(void *s1, void const *s2,
		size_t s_size, size_t b_size);
ssize_t	ft_memichr(const void *s, int c, size_t n);
int		get_next_line(int fd, char **line);
#endif
