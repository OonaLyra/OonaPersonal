CC = cc
CFLAGS = -Wall -Wextra -O2
LIBS = -lm
TARGET = blobtracker

OBJS = blobtracker.o processing.o

HEADERS = core.h stb_image.h stb_image_write.h

all:  $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
	rm -rf $(OBJS) $(TARGET)