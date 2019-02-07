NAME = ft_ls

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/
DONE = printf "\n\033[1;44m\n ft_ls - created \033[0m\n"

SRC = main.c ft_check_flag.c ft_sort_dir.c ft_start_input.c \
	  ft_sort_file.c ft_input.c ft_input_list.c ft_input_list1.c ft_format.c\
	  ft_add_func.c bonus_part.c ft_hendl.c ft_std_input.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_INC = $(LIBFT_DIR)
HEAD = $(INC_DIR)ft_ls.h

HEADER_FLAGS = -I $(INC_DIR) -I $(LIBFT_INC)

CC_FLAGS = -Wall -Wextra -Werror -O3
CC = gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)
	@$(DONE)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEAD)
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADERS_FLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
