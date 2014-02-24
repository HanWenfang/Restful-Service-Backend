#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPServerParams.h>
#include <Poco/Net/HTTPServer.h>
#include "ServiceRequestHandlerFactory.h"
#include "HTTPServer.h"
#include <Poco/ThreadPool.h>


void HTTPServer::run()
{
	stopped = false;
	
	initialize();

	Poco::Net::ServerSocket ss(8190);

	//max connection Queue:
	Poco::Net::HTTPServerParams *pHTTPServerParams = new Poco::Net::HTTPServerParams();
	pHTTPServerParams->setMaxQueued(1000);
	pHTTPServerParams->setMaxThread(5);
	pHTTPServerParams->setTimeout(30000);
	pHTTPServerParams->setKeepAlive(false);

	ServiceRequestHandlerFactory *pServiceRequestHandlerFactory = new ServiceRequestHandlerFactory(event_queue);

	pHTTPServer = new Poco::Net::HTTPServer(pServiceRequestHandlerFactory, ss, pHTTPServerParams);

	startWorkers();
	pHTTPServer->start();
}

void HTTPServer::initialize()
{
	for(int i=0; i<worker_num; ++i)
	{
		worker_queue.push_back(new Worker(event_queue, i));
	}
}

void HTTPServer::startWorkers()
{
	for(vector<Worker *>::iterator it=worker_queue.begin(); it != worker_queue.end(); ++it)
	{
		ThreadPool::defaultPool().start(*it);
	}
}




