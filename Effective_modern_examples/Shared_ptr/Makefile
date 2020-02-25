# Shared ptr

all: run
CC:=g++
CFLAGS = -g -O0 -Wall -Wextra -pedantic -MD -Wno-ignored-qualifiers
SRC = $(wildcard *.cpp)
OBJS = $(SRC:.cpp=.o)
RM = /bin/rm -rf

-include *.d

run: $(OBJS)
	$(CC) -o run $(OBJS)
%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $(@) $<
clean:
	$(RM) $(OBJS) *.d run


