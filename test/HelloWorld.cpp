#include "../HTTPServer.h"
#include <Poco/Thread.h>
#include <signal.h>
#include <unistd.h>
#include <Poco/Exception.h>

using namespace std;

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

	HTTPServer http_server(2);
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



