INCLUDE = -I. -I/usr/local/include
CPP 	= g++
LIBRARY = -L. -L/usr/local/lib
SYSLIBS = -lPocoFoundation -lPocoNet

obj-HelloWorld += HTTPServer.o
obj-HelloWorld += DefaultHTTPEventHandler.o
obj-HelloWorld += HTTPEventRequestHandlerFactory.o

obj-HelloWorld += test/HelloWorld.o




