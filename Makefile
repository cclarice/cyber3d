# **************************************************************************** #
#                                                                              #
#        ::::::    ::::::   :::  ::::::::  ::::::::   :::  ::::::    :::::::   #
#      :+:   :+: :+:   :+: :+: :+:   :+:  :+:    :+: :+: :+:   :+: :+:    :+:  #
#     +:+       +:+       +:+ +:+   +:+  +:+    +:+     +:+       +:+    +:+   #
#    +#+       +:+       +#+ +:+   +#+  +:+    +#+ +:+ +#+       +#+:+:+#+:    #
#   +#+       +#+       +#+   +#+#+#+# #+#+#+#+   +#+ +#+       +#+            #
#  #+#   #+# #+#   #+# #+#            #+#    #+# #+# #+#   #+# #+#    #+#      #
#   ######    ######  ############## ###    ### ###   ######    #######        #
#                                                                              #
# **************************************************************************** #
#                                                                              #
#    Makefile                                 cclarice@student.21-school.ru    #
#                                                                              #
#    Created/Updated: 2021/07/29 00:16:26  /  2021/08/01 15:05:44 @cclarice    #
#                                                                              #
# **************************************************************************** #

# Name
NAME	= cub3d

# Headers
HEAD	= srcs/cyber3d.h\
		  srcs/engine/engine.h\
		  srcs/parcer/parcer.h\
		  srcs/utils/utils.h

# Sources
SRCF	= srcs
ENGINE	= engine.c
PARCER	= parcer.c parce_arg.c parce_map.c parce_map_valid.c
UTILS	= strtouint.c error.c readtostr.c ft_strlen.c ft_atoi.c
SRC		= $(addprefix parcer/, $(PARCER))\
		  $(addprefix engine/, $(ENGINE))\
		  $(addprefix utils/, $(UTILS))\
		  cyber3d.c
SRCS	= $(addprefix $(SRCF)/, $(SRC))

# Objects
OBJF	= objs
IFOBJF	= $(shell ls | grep $(OBJF))
OBJFS	= $(addprefix $(OBJF)/, parcer engine utils)
OBJS	= $(patsubst srcs/%.c, objs/%.o, $(SRCS))

# Bonus

# Make Settings
SYSTEM	= $(shell uname)
CLANG	= clang
CFLAG	= -Wall -Wextra -Werror -O3
REMOVE	= rm -rf
MKDIR	= mkdir -p
ifeq ($(SYSTEM), Linux)
ECHO	= echo -e
else
ECHO	= echo
endif

# Color
RESET	= \\e[0m
BOLT	= \\e[1m
DARK	= \\e[2m
CURCIVE	= \\e[3m
UNDER	= \\e[4m
BLINK	= \\e[5m
BACK	= \\e[7m
CROSS	= \\e[9m
BLACK	= \\e[30m
RED		= \\e[31m
GREEN	= \\e[32m
YELLOW	= \\e[33m
BLUE 	= \\e[34m
MAGENTA	= \\e[35m
CYAN	= \\e[36m
WHITE	= \\e[37m

# Rules
all: $(OBJF) $(NAME)
	

$(OBJF):
	@if [ ! -a "$(OBJF)" ]; then \
		$(MKDIR) $(OBJF); \
		$(MKDIR) $(OBJFS); \
		$(ECHO) "Created $(CURCIVE)$(GREEN)$(OBJF) $(OBJFS)$(RESET) folders."; \
	fi

objs/%.o: srcs/%.c $(HEAD)
	@$(CC) $(FLAG) -c $< -o $@
	@$(ECHO) \
	"Compiled $(CYAN)$<$(RESET) $(WHITE)$(BOLT)->$(RESET) $(GREEN)$@$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(FLAG) $(OBJS) -o $(NAME)
	@$(ECHO) "Compiled $(BOLT)$(GREEN)$(NAME)$(RESET)"

bonus:
	@$(ECHO) "$(RED)Empty$(RESET)"

clean:
	@if [ -a $(OBJF) ]; then \
		$(REMOVE) $(OBJF); \
		$(ECHO) "Removed $(BOLT)$(RED)$(OBJF)$(RESET) folder."; \
	fi

fclean: clean
	@if [ -a $(NAME) ]; then \
		$(REMOVE) $(NAME); \
		$(ECHO) "Removed $(BOLT)$(RED)$(NAME)$(RESET) executable."; \
	fi

re: fclean all

norm:
	norminette $(SRCS)