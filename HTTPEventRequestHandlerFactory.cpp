
#include "HTTPEventRequestHandlerFactory.h"



void HTTPEventRequestHandlerFactory::registerHTTPRequestHandlerFactory(char *httpEvent,\
	HTTPRequestHandlerFactory *phttpRequestHandlerFactory)
{
	httpRequestHandlerFactoryTable[httpEvent] = phttpRequestHandlerFactory;
}



