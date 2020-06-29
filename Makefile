# This Makefile requires GNU make

CC = g++
# Add -msse4.2 to enable SSE instrusctions up to SSE4.2.
# We use optimization level 1 to avoid automatic vectorization with both GCC
# and Clang. GCC versions 4 and 5 will do automatic vectorization only at
# optimization level 3. Clang apparently will do it at level 2 or 3.
CFLAGS =  -Ofast -march=native
ASFLAGS = -g


DIST_FILES =  \
    euler.cpp \
    Makefile

all: euler

euler: euler.cpp
	$(CC) -std=c++11 $(CFLAGS) -fprofile-generate=prof.data -o $@ $^
	./$@ 1500000 > /dev/null
	$(CC) -std=c++11 $(CFLAGS) -fprofile-use=prof.data -o $@ $^

time:
	python -m timeit -s 'import os' 'os.system("./euler 150 > out.txt")'
	python -m timeit -s 'import os' 'os.system("./euler 15000 > out.txt")'
	python -m timeit -s 'import os' 'os.system("./euler 1500000 > out.txt")'

clean:
	rm -f *.o
	rm -f euler
