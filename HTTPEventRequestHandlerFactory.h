
#ifndef RESTFUL_SERVICE_REQUEST_HANDLER_FACTORY_H
#define RESTFUL_SERVICE_REQUEST_HANDLER_FACTORY_H
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include "DefaultHTTPEventHandler.h"
#include <map>
#include <iostream>
using namespace std;

class HTTPEventRequestHandlerFactory : public Poco::Net::HTTPRequestHandlerFactory
{
public:	
	virtual Poco::Net::HTTPRequestHandler *createRequestHandler(const Poco::Net::HTTPServerRequest &request)
	{
		cout << request.getURI() << endl;
		if(httpRequestHandlerFactoryTable.find(request.getURI()) != httpRequestHandlerFactoryTable.end()){
			return httpRequestHandlerFactoryTable[request.getURI()]->createRequestHandler(request);
		}
		//default

		return new DefaultHTTPEventHandler;
	}

	void registerHTTPRequestHandlerFactory(char *httpEvent, HTTPRequestHandlerFactory *phttpRequestHandlerFactory);

private:
	map<string, HTTPRequestHandlerFactory *> httpRequestHandlerFactoryTable;
};







#endif
