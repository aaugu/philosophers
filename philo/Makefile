NAME = philo
CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDE = -I includes
RM = rm -f

SRCS_FILES = 	main.c \
				libft_utils.c \
				philo.c \
				checks.c \

SRCS = $(addprefix ./srcs/, $(SRCS_FILES))
OBJS = $(SRCS:%.c=%.o)

%.o : %.c
			@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo " [ .. ] | Compiling philo.."
			@($(CC) $(FLAGS) $(INCLUDE) $(OBJS) -o $(NAME))
			@echo " [ OK ] | philo ready!"
clean:
			@echo " [ .. ] | Cleaning objects.."
			@($(RM) $(OBJS))
			@echo " [ OK ] | Objects removed!"

fclean: 	clean
			@echo " [ .. ] | Cleaning executable.."
			@($(RM) $(NAME))
			@echo " [ OK ] | Everything is clean!"

re: 		fclean all

.PHONY:		all clean fclean re
