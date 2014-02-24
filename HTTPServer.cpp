#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/HTTPServerParams.h>
#include <Poco/Net/HTTPServer.h>
#include "HTTPEventRequestHandlerFactory.h"
#include "HTTPServer.h"

void HTTPServer::run()
{
	Poco::Net::ServerSocket ss(port);

	Poco::Net::HTTPServerParams *pHTTPServerParams = new Poco::Net::HTTPServerParams();
	// max connection queued
	pHTTPServerParams->setMaxQueued(1000);
	pHTTPServerParams->setMaxThreads(5);
	pHTTPServerParams->setTimeout(30000);
	pHTTPServerParams->setKeepAlive(false);

	pHTTPServer = new Poco::Net::HTTPServer(pHTTPEventRequestHandlerFactory, ss, pHTTPServerParams);

	pHTTPServer->start();
}


