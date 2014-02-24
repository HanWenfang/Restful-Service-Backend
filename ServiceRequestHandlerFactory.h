
#ifndef RESTFUL_SERVICE_REQUEST_HANDLER_FACTORY_H
#define RESTFUL_SERVICE_REQUEST_HANDLER_FACTORY_H
#include "ServiceRequestHandler.h"
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/NotificationQueue.h>

class ServiceRequestHandlerFactory : public Poco::Net::HTTPRequestHandlerFactory
{
public:
	ServiceRequestHandlerFactory(Poco::NotificationQueue &queue):event_queue(queue) {}
	
	virtual Poco::Net::HTTPRequestHandler *createRequestHandler(const Poco::Net::HTTPServerRequest &request)
	{
		return new ServiceRequestHandler(event_queue);
	}

private:
	Poco::NotificationQueue &event_queue;
};







#endif
