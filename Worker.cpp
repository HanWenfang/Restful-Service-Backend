
#include "Worker.h"
#include <Poco/Notification.h>
#include "HTTPEvent.h"
#include <Poco/AutoPtr.h>
#include <iostream>

using namespace std;

void Worker::run()
{
	stopped = false;

	while(!stopped)
	{
		cout << "worker: " << id << endl;

		Poco::AutoPtr<Poco::Notification> pN = event_queue.waitDequeueNotification();

		if(pN)
		{
			HTTPEvent *pHE = dynamic_cast<HTTPEvent *>(pN.get());

			if (pHE->request.getURI() == "/name")
			{
				pHE->response.setContentType("application/json");
				pHE->response.send() << " { \"hanwenfang\"} ";
			}
		}
		
	}
}





