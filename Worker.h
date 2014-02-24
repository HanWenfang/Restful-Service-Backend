

#ifndef RESTFUL_WORKER_H
#define RESTFUL_WORKER_H
#include <Poco/Runnable.h>
#include <Poco/NotificationQueue.h>


class Worker : public Poco::Runnable
{
public:
	Worker(Poco::NotificationQueue &queue, int identity) : event_queue(queue), stopped(true), id(identity)
	{

	}
	void run();

private:
	Poco::NotificationQueue &event_queue;
	bool stopped;
	int id;
};








#endif


