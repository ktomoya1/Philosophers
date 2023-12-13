NAME = philo

INC_DIR = ./includes
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

SRCS_FILES = main.c \
	init_philos.c \
	set_philo_value.c \
	check_input.c \
	nonnegative_atoi.c \
	put_error.c \
	put_err_ret.c \
	set_errno_ret.c \
	ft_isspace.c \
	ft_isdigit.c \
	ft_strlen.c \
	validate_pthread_count.c \

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)
DEBUGFLAGS = -g3 -fsanitize=address -O0
RMFLAGS = -rf

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	mkdir -p objs

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(RMFLAGS) $(OBJS_DIR)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

ifeq ($(MAKECMDGOALS), debug)
CFLAGS += $(DEBUGFLAGS)
endif

debug: re

.PHONY: all clean fclean re debug
