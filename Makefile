# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tel-bara <tel-bara@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/08/02 17:28:56 by tel-bara      #+#    #+#                  #
#    Updated: 2021/08/05 17:38:02 by tel-bara      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=   push_swap
BONUS	=	checker
SRCS	=	srcs/error.c \
			srcs/stacks.c \
			srcs/free_stacks.c \
			srcs/checker/check_sort.c \
			srcs/getnextline/getnextline.c \
			srcs/getnextline/getnextline_utils.c \
			srcs/instructions/instructions.c \
			srcs/utils/ft_atoi.c \
			srcs/utils/ft_bzero.c \
			srcs/utils/ft_isdigit.c \
			srcs/utils/ft_putstr.c \
			srcs/utils/ft_strlen_without_padding.c \
			srcs/utils/is_valid_number_string.c \
			srcs/utils/no_duplicates.c
SRCS_PS	=	srcs/dup_stacks.c \
			srcs/instructions/wrapper.c \
			srcs/push_swap/algorithm.c \
			srcs/push_swap/main.c \
			srcs/push_swap/optimizations.c \
			srcs/push_swap/solve_chunk_in_a.c \
			srcs/push_swap/solve_chunk_in_b.c \
			srcs/push_swap/stack_sort.c \
			srcs/push_swap/stack_sort_utils.c \
			srcs/push_swap/tree_sort.c
SRCS_B	=	srcs/checker/main.c \
			srcs/instructions/process_instructions.c \
			srcs/instructions/read_instructions.c
OBJS	= $(SRCS:.c=.o)
OBJS_PS	= $(SRCS_PS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)
CC		= cc
INCS	= -Iincludes/
FLAGS	= -O3 -g3 -Wall -Wextra -Werror

ifdef APPLEPIE
FLAGS += -D CHECKER
endif

%.o: %.c
	${CC} ${FLAGS} -c -o $@ $< ${INCS}

$(NAME): ${OBJS} ${OBJS_PS}
	gcc ${OBJS} ${OBJS_PS} ${FLAGS} -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS) $(OBJS_PS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

checker_all: ${OBJS} ${OBJS_B}
	gcc ${OBJS} ${OBJS_B} ${FLAGS} -o $(BONUS)

$(BONUS):
	${MAKE} APPLEPIE=1 checker_all

bonus: ${BONUS}

.PHONY: all clean fclean re .c.o libs
