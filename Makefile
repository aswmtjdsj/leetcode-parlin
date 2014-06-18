SRC=word-search
SUF=cpp
FILE=$(SRC).$(SUF)
CC=g++

OSX_CPP_0x=
LINUX_CPP_0X=-std=c++11
CPP0X=$(LINUX_CPP_0X)
CFLAGS=-g -Wall -O2 $(CPP0X)

main: $(FILE)
	$(CC) $(CFLAGS) $^ -o $@ $#

clean:
	-rm main
