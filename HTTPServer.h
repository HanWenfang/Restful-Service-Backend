
#ifndef RESTFUL_HTTP_SERVER_H
#define RESTFUL_HTTP_SERVER_H
#include <Poco/Runnable.h>
#include <Poco/Net/HTTPServer.h>
#include <iostream>

using namespace std;

class HTTPServer : public Poco::Runnable
{
public:
	HTTPServer() {}
	~HTTPServer() {}

	virtual void run();

private:
	Poco::Net::HTTPServer *pHTTPServer;

};







#endif



