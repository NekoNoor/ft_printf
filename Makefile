# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/29 17:30:18 by nschat        #+#    #+#                  #
#    Updated: 2019/12/02 18:24:53 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc
AR = ar rcs
CFLAGS = -L libft -lft -Wall -Wextra -Werror -I includes -I libft

SRC = ft_printf.c
#BSRC =

ODIR = obj
OBJ = $(addprefix $(ODIR)/,$(SRC:.c=.o))
BOBJ = $(addprefix $(ODIR)/,$(BSRC:.c=.o))

LIBFT= libft/libft.a

NAME = libftprintf.a

define ASCII
   ___  __                                       __       ___
 /'___\\/\\ \\__                         __        /\\ \\__  /'___\\
/\\ \\__/\\ \\ ,_\\          _____   _ __ /\\_\\    ___\\ \\ ,_\\/\\ \\__/
\\ \\ ,__\\\\ \\ \\/         /\\ '__`\\/\\`'__\\/\\ \\ /' _ `\\ \\ \\/\\ \\\
 ,__\\
 \\ \\ \\_/ \\ \\ \\_        \\ \\ \\L\\ \\ \\ \\/ \\ \\ \\/\\ \\/\\ \\ \\\
 \\_\\ \\ \\_/
  \\ \\_\\   \\ \\__\\        \\ \\ ,__/\\ \\_\\  \\ \\_\\ \\_\\ \\_\\\
 \\__\\\\ \\_\\
   \\/_/    \\/__/  _______\\ \\ \\/  \\/_/   \\/_/\\/_/\\/_/\\/__/ \\/_/
                 /\\______\\\\ \\_\\
                 \\/______/ \\/_/
endef

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

all: ascii $(NAME)

export ASCII
ascii:
	@echo "\n$(CYELLOW)$$ASCII$(CDEF)\n"

$(NAME): $(LIB) | $(OBJ)
	@echo "$(TIME) $(CPLUS) $(CGREEN)Adding objects to $@...$(CDEF)"
	@$(AR) $@ $|

$(LIB):
	$(MAKE) -C $(dir $@)

bonus: $(NAME) | $(BOBJ)
	@echo "$(TIME) $(CPLUS) $(CGREEN)Adding bonus objects to $(NAME)...$(CDEF)"
	@$(AR) $(NAME) $|

%.o: %.c
	@echo "$(TIME) $(CPLUS) $(CBLUE)Compiling $< to $@...$(CDEF)"
	@mkdir $(ODIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(TIME) $(CMINUS) $(CRED)Cleaning object directory...$(CDEF)"
	@$(RM) $(ODIR)

fclean: clean
	@echo "$(TIME) $(CMINUS) $(CRED)Cleaning $(NAME)...$(CDEF)"
	@$(RM) $(NAME)

re: fclean all
