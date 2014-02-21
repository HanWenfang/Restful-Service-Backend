#include "../HTTPServer.h"
#include <Poco/Thread.h>
#include <signal.h>
#include <unistd.h>

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

	
	::HTTPServer http_server;
	http_server.run();


	int sig;
	sigwait(&newmask, &sig);

	return 0;
}



