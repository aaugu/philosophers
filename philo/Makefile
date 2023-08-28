# Colour codes
END		= \033[0m
GRAY 	= \033[0;30m
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
CYAN	= \033[0;36m
WHITE	= \033[0;37m
CYAN_B	= \033[1;96m
GREEN_B	= \033[1;92m

NAME	= philo
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -pthread
RM		= rm -rf

SRC_P 	= srcs/
OBJ_P 	= objs/

SRC		= main philosophers_dining handle_philos handle_forks time utils
SRCS	= $(addprefix  $(SRC_P), $(addsuffix .c, $(SRC)))
OBJ		= $(SRC:%.c=%.o)
OBJS	= $(addprefix $(OBJ_P), $(addsuffix .o, $(OBJ)))
INCLUDE	= -I includes

$(OBJ_P)%.o : $(SRC_P)%.c
			@mkdir -p $(OBJ_P)
			@($(CC) $(FLAGS) $(INCLUDE) -c $< -o $@)

all:		$(NAME)

$(NAME):	$(OBJS)
			@($(CC) $(FLAGS) $(OBJS) -o $(NAME))
			@echo "$(CYAN) [ OK ] | $(CYAN_B)philo$(END) $(CYAN)ready!$(END)"
clean:
			@($(RM) $(OBJ_P))
			@echo "$(GREEN) [ OK ] | Objects removed!$(END)"

fclean: 	clean
			@($(RM) $(NAME))
			@echo "$(GREEN) [ OK ] | Everything is clean!$(END)"

re: 		fclean all

.PHONY:		all clean fclean re
