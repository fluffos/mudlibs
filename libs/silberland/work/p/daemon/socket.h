// SilberLand MUDlib
//
// p/daemon/socket.h -- socket daemon header file
//
// $Date: 1997/11/09 19:18:25 $
/* $Revision: 1.1 $
 * $Log: socket.h,v $
 * Revision 1.1  1997/11/09 19:18:25  Woody
 * Initial revision
 *
 */

#ifndef __SOCKET_H__
#define __SOCKET_H__

#include <erq.h>

#define SOCKETD	"/p/daemon/socketd"

#define MAX_SOCKETS	15

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

#endif

