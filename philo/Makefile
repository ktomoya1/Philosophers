NAME = philo

INC_DIR = ./includes
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

SRCS_FILES = main.c \
	thread.c \
	setup_shared_data.c \
	init_philo.c \
	validate_input.c \
	routine.c \
	fork.c \
	put_err_ret.c \
	ft_isspace.c \
	ft_isdigit.c \
	ft_strlen.c \
	ft_atoi.c \
	get_cur_time.c \
	is_hungry.c \
	is_alive.c \
	is_alive_and_eating.c \
	has_eaten.c \
	print_message.c \
	free_ret_nul.c \

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)
DEBUGFLAGS = -fsanitize=thread
RMFLAGS = -rf

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	mkdir -p objs

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm $(RMFLAGS) $(OBJS_DIR)

fclean: clean
	rm $(RMFLAGS) $(NAME)

re: fclean all

ifeq ($(MAKECMDGOALS), debug)
CFLAGS += $(DEBUGFLAGS)
endif

debug: re

.PHONY: all clean fclean re debug
