NAME	=	libft.a

SRCS	= ft_strlcat.c ft_substr.c ft_atoi.c ft_strdup.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_isascii.c ft_bzero.c ft_memcpy.c ft_toupper.c ft_tolower.c ft_strchr.c ft_memcmp.c ft_memchr.c ft_isdigit.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_memmove.c ft_split.c ft_strnstr.c ft_substr.c 

SRCS_EXTRA = ft_substrfree.c ft_strjoinfree.c get_next_line.c
BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJS = ${BONUS:.c=.o}

OBJS = ${SRCS:.c=.o} $(SRCS_EXTRA:.c=.o)

CC		= gcc

CFLAGS	=	-Wall -Werror -Wextra

RM 		= 		rm -f

.c.o:
		$(CC) $(CFLAGS) -c  $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(BONUS_OBJS) 
			ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
			@echo "$(OK_COLOR)libft compiled!$(NO_COLOR)"

all:		$(NAME)

bonus: ${BONUS_OBJS} ${OBJS}
		ar rcs ${NAME} ${BONUS_OBJS} ${OBJS}
clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean  
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re 

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─COLOR──✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m
ERROR_COLOR=\x1b[31;01m
WARN_COLOR=\x1b[33;01m

OK_STRING=$(OK_COLOR)[OK]$(NO_COLOR)
ERROR_STRING=$(ERROR_COLOR)[ERRORS]$(NO_COLOR)
WARN_STRING=$(WARN_COLOR)[WARNINGS]$(NO_COLOR)


