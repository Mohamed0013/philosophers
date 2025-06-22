NAME = philo_bonus

SRC_DIR = src/
SRCS = philo_bonus.c utils_bonus.c parse_bonus.c\
	   init_bonus.c eat.c parse_bonus.c\
	   monitor_bonus.c routine.c all_full_routine.c\
	   sleep.c think.c semaphores.c parse_bonus_utils.c

SRC = $(addprefix $(SRC_DIR), $(SRCS))

OBJS = $(SRC:.c=.o)
CC = cc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS = -fsanitize=thread -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -lpthread

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: clean fclean re
