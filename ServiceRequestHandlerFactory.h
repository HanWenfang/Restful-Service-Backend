
#ifndef RESTFUL_SERVICE_REQUEST_HANDLER_FACTORY_H
#define RESTFUL_SERVICE_REQUEST_HANDLER_FACTORY_H
#include "ServiceRequestHandler.h"
#include <Poco/Net/HTTPRequestHandlerFactory.h>

class ServiceRequestHandlerFactory : public Poco::Net::HTTPRequestHandlerFactory
{
public:
	virtual Poco::Net::HTTPRequestHandler *createRequestHandler(const Poco::Net::HTTPServerRequest &request)
	{
		
		return new ServiceRequestHandler();
	}

};







#endif
