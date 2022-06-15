CC ?= gcc
CFLAGS=-O3 -Wall -I../common -I. -I./include -fPIC -g -fcommon -L/usr/include

# Use X11
CFLAGS+=-DUSE_X11

# Use screen size from server.
# CFLAGS+=-DGLS_USE_SRVSIZE

# Try to emulate client arrays with VBO.
CFLAGS+=-DGLS_EMULATE_VBO

LIBS=-pthread -ldl -lX11
CFLAGS+= $(LIBS)
OBJS=fifo.o server.o clientegl.o clientgles.o glclient.o

LIB_GLES=libGLESv2.so.2

GLS_LIB_DIR=/usr/local/lib/gl-streaming

EXES=$(LIB_GLES)

all: $(EXES)

fifo.o: ../common/fifo.c ../common/fifo.h
	$(CC) -c -o fifo.o $(CFLAGS) ../common/fifo.c

server.o: ../common/server.c ../common/server.h fifo.o
	$(CC) -c -o server.o $(CFLAGS) ../common/server.c

clientegl.o: clientegl.c include/EGL/egl.h
	$(CC) -c -o clientegl.o $(CFLAGS) clientegl.c

clientgles.o: clientgles.c include/GLES2/gl2.h
	$(CC) -c -o clientgles.o $(CFLAGS) clientgles.c

glclient.o: glclient.c glclient.h ../common/gls_command.h server.o
	$(CC) -c -o glclient.o $(CFLAGS) glclient.c

$(LIB_GLES): $(OBJS)
	$(CC) -shared -o $(LIB_GLES) $(CFLAGS) $(OBJS) -Wl,-init,gls_init_library,--no-undefined $(LIBS)

install:
	mkdir -p $(GLS_LIB_DIR)
	cp libGLESv2.so.2 $(GLS_LIB_DIR)/
	ln -s $(GLS_LIB_DIR)/libGLESv2.so.2 $(GLS_LIB_DIR)/libEGL.so.1; echo "To use streaming, type: export LD_LIBRARY_PATH=$(GLS_LIB_DIR)\nThen you are ready to get hardware acceleration!"

clean:
	rm $(EXES) $(OBJS)
