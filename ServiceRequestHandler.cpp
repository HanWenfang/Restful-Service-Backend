#include "ServiceRequestHandler.h"

void ServiceRequestHandler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
	if (request.getURI() == "/name")
	{
		response.setContentType("application/json");
		response.send() << " { \"hanwenfang\"} ";
	}


}

