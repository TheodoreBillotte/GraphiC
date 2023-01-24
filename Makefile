##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile to compile GraphiC lib
##

CC = gcc
CFLAGS = -W -Wall -Wextra -Werror -Iinclude -g3
CFLAGS_TEST = -L. -lgraphic -lcriterion

SRC = $(wildcard *.c)
SRC += $(wildcard lib/list/*.c)
OBJ = $(SRC:.c=.o)
TARGET = libgraphic.a

all: $(TARGET)

$(TARGET): $(OBJ)
	$(AR) rsc $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

build: re clean
