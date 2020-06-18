# This Makefile requires GNU make

CC = g++
# Add -msse4.2 to enable SSE instrusctions up to SSE4.2.
# We use optimization level 1 to avoid automatic vectorization with both GCC
# and Clang. GCC versions 4 and 5 will do automatic vectorization only at
# optimization level 3. Clang apparently will do it at level 2 or 3.
CFLAGS =  -O2
ASFLAGS = -g


DIST_FILES =  \
    euler.cpp \
    Makefile

all: euler

euler: euler.cpp
	$(CC) -std=c++14 $(CFLAGS) -o $@ $^

clean:
	rm -f *.o
