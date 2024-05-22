NAME := push_swap

CC_FLAGS := -Wall -Wextra -Werror
CC_LIBS := -L./lib -I./lib -lft -lftprintf
CC_STACK := ./src/stack/free_stack.c ./src/stack/find_last.c
CC_UTILS := ./src/utils/is_num.c ./src/utils/split_params.c ./src/utils/ft_atol.c
CC_SRC := ./src/init.c ./src/push_swap.c

all:
	@cc $(CC_FLAGS) $(CC_LIBS) $(CC_SRC) $(CC_UTILS) $(CC_STACK) $(CC_LIBS) -o $(NAME)
clean:
fclean:
	@rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re
