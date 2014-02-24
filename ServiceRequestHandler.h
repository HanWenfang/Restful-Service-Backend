

#ifndef RESTFUL_SERVICE_REQUEST_HANDLER_H
#define RESTFUL_SERVICE_REQUEST_HANDLER_H
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/NotificationQueue.h>
#include <Poco/Mutex.h>

class ServiceRequestHandler : public Poco::Net::HTTPRequestHandler
{
public:
	ServiceRequestHandler(Poco::NotificationQueue &queue):event_queue(queue) {}
	virtual void handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response);
	void worker(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response);


private:
	Poco::NotificationQueue &event_queue;
	Poco::Mutex mutex;
};








#endif


