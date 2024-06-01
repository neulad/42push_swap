NAME := push_swap
NAME_BONUS := bonus

CC_FLAGS := -Wall -Wextra -Werror
CC_LIBS := -L./lib -I./lib -lft -lftprintf
CC_STACK := ./src/stack/free_stack.c \
	./src/stack/find_last.c \
	./src/stack/is_sorted.c \
	./src/stack/stack_len.c \
	./src/stack/find_max.c \
	./src/stack/find_min.c
CC_SORT := ./src/sort/sort_three.c \
	./src/sort/sort_stacks.c \
	./src/sort/set_targets_a.c \
	./src/sort/set_targets_b.c \
	./src/sort/set_costs_a.c \
	./src/sort/set_costs_b.c \
	./src/sort/push_cheapest_a.c \
	./src/sort/push_cheapest_b.c \
	./src/sort/rrx_moves.c \
	./src/sort/op_times.c
CC_UTILS := ./src/utils/is_num.c ./src/utils/split_params.c ./src/utils/ft_atol.c
CC_SRC := ./src/init.c ./src/push_swap.c ./src/init_init.c
CC_OPERATIONS := ./src/operations/push.c \
	./src/operations/rev_rotate.c \
	./src/operations/rotate.c \
	./src/operations/swap.c

CC_BONUS_SRC := ./bonus_src/checker.c ./src/init.c ./src/init_init.c
CC_BONUS_UTILS := ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
CC_SILENT_OPERATIONS := ./bonus_src/silent_operations/push.c \
	./bonus_src/silent_operations/rev_rotate.c \
	./bonus_src/silent_operations/rotate.c \
	./bonus_src/silent_operations/swap.c

all:
	@cc $(CC_FLAGS) $(CC_SRC) $(CC_UTILS) $(CC_STACK) $(CC_SORT) $(CC_OPERATIONS) $(CC_LIBS) -o $(NAME)
bonus:
	@cc $(CC_BONUS_SRC) $(CC_SILENT_OPERATIONS) $(CC_BONUS_UTILS) $(CC_FLAGS) $(CC_UTILS) $(CC_STACK) $(CC_SORT) $(CC_OPERATIONS) $(CC_LIBS) -o $(NAME_BONUS)
clean:
fclean:
	@rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re bonus
