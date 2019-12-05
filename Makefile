CFLAGS=-g -Wall
CXXFLAGS=-g -Wall

LDLIBS=-lX11 -lm

LINK.o = $(CXX) $(LDFLAGS) $(TARGET_ARCH)

runtests: runtests.o gfx.o Complex.o

clean:
	rm -f runtests *.o
	rm -f gfx *.o
	rm -f Complex *.o
