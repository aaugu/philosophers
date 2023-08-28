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
FLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

SRC_P 	= srcs/
OBJ_P 	= objs/

SRC		= main philo input_checks init
SRCS	= $(addprefix  $(SRC_P), $(addsuffix .c, $(SRC)))
OBJ		= $(SRC:%.c=%.o)
OBJS	= $(addprefix $(OBJ_P), $(addsuffix .o, $(OBJ)))
INCLUDE	= -I includes

$(OBJ_P)%.o : $(SRC_P)%.c
			@mkdir -p $(OBJ_P)
			@($(CC) $(FLAGS) $(INCLUDE) -c $< -o $@)

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "$(CYAN) [ .. ] | Compiling $(CYAN_B)philo$(END)$(CYAN)...$(END)"
			@($(CC) $(FLAGS) $(OBJS) -o $(NAME))
			@echo "$(GREEN) [ OK ] | $(GREEN_B)philo$(END) $(GREEN)ready!$(END)"
clean:
			@echo "$(CYAN) [ .. ] | Cleaning objects...$(END)"
			@($(RM) $(OBJ_P))
			@echo "$(GREEN) [ OK ] | Objects removed!$(END)"

fclean: 	clean
			@echo "$(CYAN) [ .. ] | Cleaning executable...$(END)"
			@($(RM) $(NAME))
			@echo "$(GREEN) [ OK ] | Everything is clean!$(END)"

re: 		fclean all

.PHONY:		all clean fclean re
