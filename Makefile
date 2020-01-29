# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/29 17:30:18 by nschat        #+#    #+#                  #
#    Updated: 2020/01/29 19:02:40 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc
AR = ar rcs
IDIR = include
CFLAGS = -Wall -Wextra -Werror -I $(IDIR)

SRC = printf_mediocre.c \
	  printf_mediocre_analyze.c \
	  printf_mediocre_get.c \
	  printf_mediocre_list.c \
	  printf_mediocre_nbr.c \
	  printf_mediocre_print.c \
	  printf_mediocre_str.c \
	  printf_mediocre_utils.c
HDR = $(IDIR)/printf_mediocre.h

ODIR = obj
OBJ = $(addprefix $(ODIR)/,$(SRC:.c=.o))

NAME = libftprintf.a

CRED = \x1b[31m
CGREEN = \x1b[32m
CYELLOW = \x1b[33m
CBLUE = \x1b[34m
CCYAN = \x1b[36m
CDEFAULT = \x1b[39m
CDEF = $(CDEFAULT)

CMINUS = $(CRED)[-]$(CDEF)
CPLUS = $(CGREEN)[+]$(CDEF)
CNORM = $(CYELLOW)[~]$(CDEF)

TIME = $(CCYAN)[$$(date +"%H:%M:%S")]$(CDEF)

vpath %.c src

.PHONY: clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(TIME) $(CPLUS) $(CGREEN)Adding objects to $@...$(CDEF)"
	@$(AR) $@ $^

$(ODIR)/%.o: %.c $(HDR)
	@echo "$(TIME) $(CPLUS) $(CBLUE)Compiling $< to $@...$(CDEF)"
	@mkdir -p $(ODIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(TIME) $(CMINUS) $(CRED)Cleaning object directory...$(CDEF)"
	@$(RM) -r $(ODIR)

fclean: clean
	@echo "$(TIME) $(CMINUS) $(CRED)Cleaning $(NAME)...$(CDEF)"
	@$(RM) $(NAME)

re: fclean all
