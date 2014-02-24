

#ifndef RESTFUL_SERVICE_REQUEST_HANDLER_H
#define RESTFUL_SERVICE_REQUEST_HANDLER_H
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Mutex.h>
#include <map>
#include <string>

using namespace std;

// Thread-Safe!
class DefaultHTTPEventHandler : public Poco::Net::HTTPRequestHandler
{
public:
	virtual void handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
	{
		response.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
		response.send();
	}
};







#endif


