Restful-Service-Backend
=======================

A Restful Service Backend

Super Capacity!

Architecture:

	 HttpServer [ Multi-thread ] -> NotificationQueue -> Workers [ Multi-workers ]
	 	|
	 TCP server [ start a new thread ]
	 	|
	 defaultThreadPool [min=2, max=16]



one -> many -> queue -> many



NotificationQueue is Dead!Cry! Because The HTTP Server FrameWork Says You Must Deal With 
http-request-response In The RequestHandle.



So Now It is:

	 HttpServer [ Multi-thread ]
	 	|
	 TCP server [ start a new thread ]
	 	|
	 defaultThreadPool [min=2, max=16]

one -> many -|stop here




