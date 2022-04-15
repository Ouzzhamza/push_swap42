

CC  	= cc
CFLAGS	= -Wall -Wextra -Werror 

FSRC_DIR = functions/
FSRC 	 = ft_atoi.c  ft_putstr.c ft_lstnew.c ft_lstadd_back.c ft_lstlast.c \
		 ft_lstadd_front.c ft_lstsize.c ft_strlen.c ft_strncmp.c ft_calloc.c \
		 ft_strchr.c ft_bzero.c ft_split.c ft_strdup.c ft_strjoin.c \
		
SFRC_DIR = swaping_functions/
SFRC	 = end_to_first.c push_to.c first_to_end.c swap_first_two.c swap_both.c rotate_both.c\

MFRC_DIR = mandatory/
SRC		 =  pivot_chose.c useful.c stack_a.c stack_b.c check_err.c\

BSFC_DIR = bonus/
BSRC     = checker.c get_instructions.c get_next_line.c \


FPATH	= $(addprefix $(FSRC_DIR), $(FSRC))
SFPATH	= $(addprefix $(SFRC_DIR), $(SFRC))
MFPATH	= $(addprefix $(MFRC_DIR), $(SRC))
BFPATH  = $(addprefix $(BSFC_DIR), $(BSRC))


FOBJ	= $(FPATH:%.c=%.o)
SFOBJ	= $(SFPATH:%.c=%.o)
OBJ		= $(MFPATH:%.c=%.o)
BOBJ    = $(BFPATH:%.c=%.o)

NAME	= push_swap
BNAME   = checker

all		: $(NAME)

$(NAME)	: $(FOBJ) $(SFOBJ) $(OBJ) 
		@$(CC) $(FOBJ) $(SFOBJ) $(OBJ) mandatory/main.c -o $(NAME) 
		@echo "$(BOLD)$(GREEN)DONE $(RESET)"

bonus	: $(BNAME)

$(BNAME)	: $(FOBJ) $(SFOBJ) $(BOBJ) $(OBJ) 
		@$(CC) $(FOBJ) $(SFOBJ) $(BOBJ) $(OBJ)   -o $(BNAME)
		@echo "$(BOLD)$(GREEN)BONUS DONE $(RESET)"

%.o 	:%.c mandatory/push_swap.h bonus/checker.h
			$(CC) $(CFLAGS) -c $< -o $@
clean	:
		rm -f $(OBJ) $(BOBJ) $(FOBJ) $(SFOBJ)
		@echo "$(BOLD)$(ORANGE)OBJECT FILE DELETED !$(RESET)"

fclean   : clean
	     rm -f $(NAME) $(BNAME)
	     @echo "$(BOLD)$(RED)ALL DELETED !$(RESET)"

re       : fclean all


.PHONY  : all bonus clean fclean re
.SILENT :


#COLOR

GREEN = \033[1;32m
RED = \033[1;31m
ORANGE = \033[0;33m
RESET = \033[0m