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





