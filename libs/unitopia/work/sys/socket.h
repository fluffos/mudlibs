// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/socket.h
// Description:	Defines fuer den SocketD
// Author:	
//
// $Log: socket.h,v $
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef SOCKET_H
#define SOCKET_H 1

#define SOCKETD "/apps/socketd"

#define MAX_SOCKETS	150

#define SOCKET_ACCEPT	0
#define SOCKET_READ	1
#define SOCKET_CLOSE	2
#define SOCKET_ERROR	3
#define SOCKET_READY	4
#define SOCKET_TRANSFER	5

#define SOCKET_BINARY	1

#ifndef __ERQ_MAX_REPLY__
#define __ERQ_MAX_REPLY__ 1024
#endif

#ifndef __ERQ_MAX_SEND__
#define __ERQ_MAX_SEND__ 256
#endif

#endif // SOCKET_H
