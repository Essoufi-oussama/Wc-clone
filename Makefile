srcs = wc.c
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : ccwc

ccwc: $(srcs)
	$(CC) $(CFLAGS) -o $@ $^ 

clean: 
	rm -rf ccwc

re: clean all