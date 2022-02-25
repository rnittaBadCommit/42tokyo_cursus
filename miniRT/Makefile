CC = gcc
FLAG = -Wall -Wextra -Werror 
SANI = -g -fsanitize=address
FLAGSEC = -L./lib/ -lmlx_Linux -Wall -lXext -lX11 -lm
NAME = miniRT

COLLISION_DETECT = collision_detect.c collision_plane.c collision_sphere_cylinder.c collision_triangle_square.c
FILE_CHECK = err_exit.c filecheck.c filecheck2.c read_file.c
MAKE_OBJ = make_obj.c make_obj_utils.c make_obj1_2.c make_obj2.c
RAY = make_ray.c ray_process.c ray_to_light.c
UTILS = image_utils.c math_utils.c math_utils2.c utils.c utils2.c
OTHERS = key_handle.c main.c make_bpm.c
SRCS = ${COLLISION_DETECT:%=collision_detect/%} ${FILE_CHECK:%=file/%} ${MAKE_OBJ:%=make_obj/%} ${RAY:%=ray/%} ${UTILS:%=utils/%} ${OTHERS}

RM = rm -f
INCS = includes
OJ = $(SRCS:%.c=srcs/%.o)

.c.o:
	$(CC) $(FLAG) -c $< -o $@ -I $(INCS)

$(NAME): $(OJ)
	$(CC) $(FLAG) -o $(NAME) $(OJ) $(FLAGSEC)

all: $(NAME)

sani: $(NAME)
	$(CC) $(FLAG) $(SANI) -o $(NAME) $(OJ) $(FLAGSEC)

clean:
	$(RM) $(OJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean sani
