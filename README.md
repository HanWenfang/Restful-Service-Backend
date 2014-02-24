Restful-Service-Backend-Framework
=======================

A Restful Service Backend Framework

Super Capacity!

Architecture:

	 HttpServer [ Multi-thread ] -> NotificationQueue -> Workers [ Multi-workers ]
	 	|
	 TCP server [ start a new thread ]
	 	|
	 defaultThreadPool [min=2, max=16]



one -> many -> queue -> many



NotificationQueue is Dead!Cry! Because The HTTP Server Framework Says You Must Deal With 
http-request-response In The RequestHandle.



So Now It is:

	 HttpServer [ Multi-thread ]
	 	|
	 TCP server [ start a new thread ]
	 	|
	 defaultThreadPool [min=2, max=16]

one -> many -|stop here

Framework:







But..

I Believe You Can Make It More Powerful! Like request processing etc.





