NAME	= libftprintf.a

CC		= gcc 
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

SRCS	= formatter.c	ft_putchar_pf.c	ft_putunsigned_pf.c ft_printhex_pf.c	ft_putnumber_pf.c \
			ft_printptr_pf.c	ft_putstr_pf.c	printf.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@
		
clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re