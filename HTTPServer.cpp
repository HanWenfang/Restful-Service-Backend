#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPServerParams.h>
#include <Poco/Net/HTTPServer.h>
#include "ServiceRequestHandlerFactory.h"
#include "HTTPServer.h"

void HTTPServer::run()
{
	Poco::Net::ServerSocket ss(8190);
	Poco::Net::HTTPServerParams *pHTTPServerParams = new Poco::Net::HTTPServerParams();
	ServiceRequestHandlerFactory *pServiceRequestHandlerFactory = new ServiceRequestHandlerFactory();

	pHTTPServer = new Poco::Net::HTTPServer(pServiceRequestHandlerFactory, ss, pHTTPServerParams);

	pHTTPServer->start();
}


