CC = cc
CFLAGS = -Wall -Wextra -O2 -Iincludes
LIBS = -lm -lSDL2
TARGET = Masami

SRCS = main.c  io/stb_invoke.c io/processing.c io/bottle.c io/lens.c
OBJS = $(SRCS:.c=.o)

all:  $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)