NAME = philo

INC_DIR = ./includes
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

SRCS_FILES = main.c \
	thread.c \
	validate_input.c \
	routine.c \
	fork.c \
	condition.c \
	output.c \
	utils.c \
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
