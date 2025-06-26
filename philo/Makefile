NAME = philo
CC = cc
RM = rm -rf
CFLAGS = -fsanitize=thread -Wall -Wextra -Werror

SRC_DIR = src/
OBJ_DIR = objects/

SRC =	philo parse_it init routine time utils monitor \
       	eat eat_utils eat_utils2 sleep think \
    	getters_1 getters_2 setters parse_utils

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC)))

OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) 

re: fclean all
.PHONY: all clean fclean re
