NAME	= libft.a

SRCS	=	ft_strlen.c\
			ft_strnlen.c\
			ft_strlcpy.c\
			ft_strlcat.c\
			ft_strncat.c\
			ft_strncmp.c\
			ft_atoi.c\
			ft_isalpha.c\
			ft_isprint.c\
			ft_isdigit.c\
			ft_isalnum.c\
			ft_isnumber.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_memset.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_strnstr.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_memmove.c\
			ft_isascii.c\
			ft_calloc.c\
			ft_strdup.c\
			ft_strdup_free.c\
			ft_strndup.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strjoin_space.c\
			ft_strjoin_no_free.c\
			ft_chrjoin.c\
			ft_strtrim.c\
			ft_split.c\
			ft_split_comma.c\
			ft_split_pipe.c\
			ft_split_minishell.c\
			ft_split_minishell_2.c\
			ft_itoa.c\
			ft_strmapi.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_itoa_unsint.c\
			ft_str_tolower.c\
			ft_strcmp.c\
			ft_isspace.c\
			ft_freetab.c\
			ft_freetab_int.c

SRCS_1	=	ft_lstnew.c\
			ft_lstadd_front.c\
			ft_lstsize.c\
			ft_lstlast.c\
			ft_lstadd_back.c\
			ft_lstdelone.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_lstmap.c

OBJS	= ${SRCS:.c=.o}

OBJS_1	= ${SRCS_1:.c=.o}

LIBC	= ar -rcs

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

INCS	= .

.c.o:
		gcc ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

${NAME}:	${OBJS}
			${LIBC} ${NAME} ${OBJS}

bonus:	${NAME}	${OBJS_1}
			${LIBC} ${NAME} ${OBJS_1}

all: ${NAME}

clean:
		rm -rf *.o
		rm -rf .DS_Store
		rm -rf a.out
		rm -rf a.out*
		${RM} ${OBJS} ${OBJS_1}

fclean:	clean
		rm -rf $(NAME)
		rm -rf $(NAME).dSYM
		rm -rf *.a
		${RM} ${NAME} ${bonus}

re: fclean all

.PHONY:	all clean fclean bonus .c.o re
