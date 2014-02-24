#include "../HTTPServer.h"
#include "../HTTPEventRequestHandlerFactory.h"
#include <Poco/Thread.h>
#include <Poco/Exception.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <signal.h>
#include <unistd.h>

using namespace std;

class AuthorEvent :  public Poco::Net::HTTPRequestHandler
{
public:	
	virtual void handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
	{
		if (request.getURI() == "/name")
		{
			response.setContentType("application/json");
			response.send() << " { \"hanwenfang\"} ";
		}
	}
};


class AuthorEventFactory : public  Poco::Net::HTTPRequestHandlerFactory
{
public:	
	AuthorEventFactory(string uri):uriEvent(uri) {}

	virtual Poco::Net::HTTPRequestHandler *createRequestHandler(const Poco::Net::HTTPServerRequest &request)
	{
		return new AuthorEvent;
	}

	string getURIEvent()
	{
		return uriEvent;
	}
private:
	string uriEvent;  // httpEvent
};



int main(int argc, char *argv[])
{
	sigset_t newmask;
	sigset_t oldmask;

	//no return value check
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGQUIT);
	sigaddset(&newmask, SIGINT);
	sigaddset(&newmask, SIGTERM);
	sigprocmask(SIG_BLOCK, &newmask, &oldmask);
	
	Poco::Net::HTTPRequestHandlerFactory *pAuthorEventFactory = new AuthorEventFactory("/name");

	HTTPEventRequestHandlerFactory *phttpEventRequestHandlerFactory = new HTTPEventRequestHandlerFactory;
	
	phttpEventRequestHandlerFactory->\
	registerHTTPRequestHandlerFactory("/name", pAuthorEventFactory);

	HTTPServer http_server(8190, *phttpEventRequestHandlerFactory);

	try
	{
		http_server.run();
	}
	catch (Poco::NoThreadAvailableException &e)
	{
		cout << e.displayText() << endl;
	}
	catch (Poco::Exception &e)
	{
		cout << e.displayText() << endl;
	}
	


	int sig;
	sigwait(&newmask, &sig);

	return 0;
}



