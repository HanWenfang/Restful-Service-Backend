
#ifndef RESTFUL_HTTP_EVENT_H
#define RESTFUL_HTTP_EVENT_H
#include <Poco/Notification.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPServerRequest.h>

class HTTPEvent : public Poco::Notification
{
public:
	HTTPEvent(Poco::Net::HTTPServerRequest  &rq, Poco::Net::HTTPServerResponse &rs):request(rq), response(rs) 
	{

	}

	~HTTPEvent() { }


	Poco::Net::HTTPServerRequest  &request;
	Poco::Net::HTTPServerResponse &response;
};




#endif
