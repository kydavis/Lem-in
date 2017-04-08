# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdavis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/21 14:59:51 by kdavis            #+#    #+#              #
#    Updated: 2017/04/06 14:30:36 by kdavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=lem-in

MAKE		=make

FILENAMES	=	main.c\
				li_cleanup.c\
				read_file.c\
				get_rooms.c\
				get_links.c\
				add_line.c\
				validate_numbers.c\
#				test_mallocwrap.c\

SRCDIR		=src/
IDIR		=includes/
LIB			=libft

SRC			=$(addprefix $(SRCDIR), $(FILENAMES))

CFLAGS		=-Wall -Werror -Wextra
IFLAGS		=-I $(IDIR) -I $(LIB)/$(IDIR)
LFLAGS		=-L $(LIB) -lft

CC			=gcc

.PHONY: all clean fclean re

all: $(LIB)/$(LIB).a $(NAME)

$(LIB)/$(LIB).a:
	$(MAKE) -C $(LIB)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(SRC) -o $@

clean:
	$(MAKE) -C $(LIB) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIB) fclean

re: fclean all
