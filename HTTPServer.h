
#ifndef RESTFUL_HTTP_SERVER_H
#define RESTFUL_HTTP_SERVER_H
#include <Poco/Runnable.h>
#include <Poco/Net/HTTPServer.h>
#include <iostream>
#include <vector>
#include "HTTPEventRequestHandlerFactory.h"

using namespace std;

// could be used as a thread in Poco
class HTTPServer : public Poco::Runnable
{
public:
	HTTPServer(int p, HTTPEventRequestHandlerFactory &httpEventRequestHandlerFactory):port(p),\
	pHTTPEventRequestHandlerFactory(&httpEventRequestHandlerFactory)
	{ 
	}
	
	~HTTPServer() { }

	virtual void run();

private:
	Poco::Net::HTTPServer *pHTTPServer;
	int port;
	HTTPEventRequestHandlerFactory *pHTTPEventRequestHandlerFactory;
};







#endif



