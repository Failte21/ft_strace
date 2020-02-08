CC =			gcc

CFLAGS =		-Werror -Wall -Wextra -g

SRCS_DIR =		srcs
INC_DIR =		inc
OBJS_DIR =		objs

NAME = 			ft_strace

SRC_NAMES =		main.c \
				error.c

SRCS = 			$(addprefix $(SRCS_DIR)/, $(NM_SRC_NAMES))

OBJ_NAMES = 	$(SRC_NAMES:.c=.o)
OBJS = 			$(addprefix $(OBJS_DIR)/, $(OBJ_NAMES))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $^

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
