CC     = gcc
CFLAGS_WARN_OK = -Wall -Wno-unused-variable -I/usr/include/ImageMagick -g3
CFLAGS = $(CFLAGS_WARN_OK) -Werror 
ASAN_FLAGS = -fsanitize=address -fno-omit-frame-pointer -Wno-format-security

LIBS = -lpthread
ASAN_LIBS = -static-libasan

MAGICK_FLAGS = `pkg-config --cflags MagickCore`
MAGICK_LIBS = `pkg-config --libs MagickCore`

GENERATE := $(shell rpcgen -C -M resize.x)

all: server client 

server: resize_xdr.c resize_svc.c rpc_implementation.c
	gcc -o server resize_xdr.c resize_svc.c rpc_implementation.c $(LIBS)

client: rpc_client.c resize_clnt.c resize_xdr.c 
	gcc -o client rpc_client.c resize_clnt.c resize_xdr.c 

#### Cleanup ####
clean:
	rm -f *.o server client resize_* resize.h

