# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/20 15:24:11 by vvaucoul          #+#    #+#              #
#    Updated: 2022/08/20 16:34:37 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	garbage_collector_library.a

CC				=	clang-11
CFLAGS			=	-g3 -Wall -Wextra
INCLUDES		=	-I includes

SRCS_DIR 		=	srcs
SRCS 			=	$(shell find $(SRCS_DIR) -name '*.c')
OBJS 			=	$(SRCS:.c=.o)

SRCS_TEST_DIR	=	tests
SRCS_TEST		=	$(shell find $(SRCS_TEST_DIR) -name '*.c')
OBJS_TEST		=	$(SRCS_TEST:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf '%s\n' "Compiling $<"

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: $(NAME) $(OBJS_TEST)
	$(CC) $(INCLUDES) $(OBJS_TEST) -L $(NAME) $(NAME) -o test

.PHONY: all clean fclean re