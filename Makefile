# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/20 15:24:11 by vvaucoul          #+#    #+#              #
#    Updated: 2022/09/08 12:20:28 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include mk-dependencies/Colors.mk

NAME			=	vgcl.a

CC				=	clang-11
CFLAGS			=	-g3 -Wall -Wextra -MD
INCLUDES		=	-I includes

SRCS_DIR 		=	srcs
SRCS 			=	$(wildcard $(SRCS_DIR)/*.c)
OBJS 			=	$(SRCS:.c=.o)

SRCS_TEST_DIR	=	tests
SRCS_TEST		=	$(shell find $(SRCS_TEST_DIR) -name '*.c')
OBJS_TEST		=	$(SRCS_TEST:.c=.o)

DEPENDS			=	$(OBJS:.o=.d)
DEPENDS_TEST	=	$(OBJS_TEST:.o=.d)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(_LWHITE)Compiling: $(_LGREEN)%s $(_END)\n" $< 

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@printf "$(_LWHITE)Creating Library: $(_LCYAN)%s $(_END)\n" $(NAME)

clean:
	@rm -f $(OBJS) $(OBJS_TEST) $(DEPENDS) $(DEPENDS_TEST)

fclean: clean
	@rm -f $(NAME)
	@rm -f test

re: fclean all

test: $(NAME) $(OBJS_TEST)
	@$(CC) $(INCLUDES) $(OBJS_TEST) -L $(NAME) $(NAME) -o test
	@printf "$(_LWHITE)Create binary: $(_LGREEN)%s $(_END)\n" test

.PHONY: all clean fclean re test

-include $(DEPENDS)
-include $(DEPENDS_TEST)