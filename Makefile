PROJ = dtree 
CC = g++
CFLAGS = -g
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

$(PROJ): $(OBJS) 
	$(CC) $^ -o $@ -lcurses

%.o:%.cpp
	$(CC) $< $(CFLAGS) -c -o $@

clean:
	@rm *.o $(PROJ) -rvf
