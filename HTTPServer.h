
#ifndef RESTFUL_HTTP_SERVER_H
#define RESTFUL_HTTP_SERVER_H
#include <Poco/Runnable.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/NotificationQueue.h>
#include <iostream>
#include <vector>
#include "Worker.h"

using namespace std;

class HTTPServer : public Poco::Runnable
{
public:
	HTTPServer(int workerN, ):stopped(true),worker_num(workerN)
	{

	}
	~HTTPServer() 
	{
		for(vector<Worker *>::iterator it=worker_queue.begin(); it != worker_queue.end(); ++it)
		{
			delete *it;
		}
	}

	virtual void run();
	void initialize();
	void startWorkers();

private:
	Poco::Net::HTTPServer *pHTTPServer;
	Poco::NotificationQueue event_queue;
	vector<Worker *> worker_queue;
	bool stopped;
	int worker_num;
};







#endif



