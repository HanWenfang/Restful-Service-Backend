INCLUDE = -I. -I/usr/local/include
CPP 	= g++
LIBRARY = -L. -L/usr/local/lib
SYSLIBS = -lPocoFoundation -lPocoNet

obj-HelloWorld += HTTPServer.o
obj-HelloWorld += ServiceRequestHandler.o
obj-HelloWorld += ServiceRequestHandlerFactory.o
obj-HelloWorld += test/HelloWorld.o




