#include "ServiceRequestHandler.h"
#include "Worker.h"
#include "HTTPEvent.h"

void ServiceRequestHandler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
	Mutex::ScopedLock lock(mutex);
	event_queue.enqueueNotification(new HTTPEvent(request, response));
}

void ServiceRequestHandler::worker(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
	if (request.getURI() == "/name")
	{
		response.setContentType("application/json");
		response.send() << " { \"hanwenfang\"} ";
	}
}





