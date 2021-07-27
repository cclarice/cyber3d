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
#    Created/Updated: 2021/07/27 04:51:41  /  2021/07/27 14:19:36 @cclarice    #
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
PARCER	= parcer.c
UTILS	= strtouint.c
SRC		= $(addprefix parcer/, $(PARCER))\
		  $(addprefix engine/, $(ENGINE))\
		  $(addprefix utils/, $(UTILS))\
		  cyber3d.c
SRCS	= $(addprefix $(SRCF)/, $(SRC))

# Objects
OBJF	= objs
OBJFS	= $(addprefix $(OBJF)/, parcer engine utils)
OBJS	= $(patsubst src/%.c, obj/%.o, $(SRCS))

# Bonus #

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

all:
	@$(ECHO) $(GREEN)Checking if custom header is needed$(RESET)
bonus:
	@$(ECHO) $(RED)Empty$(RESET)
clean:
fclean:
re:
norm: 