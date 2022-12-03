NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = philo.c parse.c routine.c tools.c init.c free.c
OBJ = $(SRCS:.c=.o)

$(NAME): $(OBJ) philo.h
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all