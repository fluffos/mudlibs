#include "net/socket_errors.h"

#ifndef __EVIL_H__
#define __EVIL_H__
#define MUD 0
#define STREAM 1
#define DATAGRAM 2
#define STREAM_BINARY 3
#define DATAGRAM_BINARY 4

/*
** Styles of socket objects
*/
#define SKT_STYLE_LISTEN	1	/* listen for connections (text) */
#define SKT_STYLE_CONNECT	2	/* connect to remote skt (text) */
#define SKT_STYLE_UDP		3	/* UDP transfers (text) */

#define SKT_STYLE_LISTEN_B	11	/* listen for connections (binary) */
#define SKT_STYLE_CONNECT_B	12	/* connect to remote skt (binary) */
#define SKT_STYLE_UDP_B		13	/* UDP transfers (binary) */

#define SKT_STYLE_LISTEN_M	21	/* listen for connections (mud) */
#define SKT_STYLE_CONNECT_M	22	/* connect to remote skt (mud) */

#define SKT_STYLE_INT_ACQUIRE	100	/* internal */


/*
** SKT_STYLE_LISTEN
**
** These sockets are created as:
**
**	new(SOCKET, SKT_STYLE_LISTEN,
**	    int listenport,
**	    function read_func,
**	    function close_func
**	    );
**
** When a connection arrives, a new socket object will be cloned for the
** connection.  The read_func will be evaluated whenever data arrives,
** and close_func will be called when the socket closed prematurely.
**
** The prototypes for the functions are:
**
**	void read_func(object socket, string data)
**	void close_func(object socket)
**
** Note: this is not a binary socket.
*/

/*
** SKT_STYLE_CONNECT
**
** These sockets are created as:
**
**	new(SOCKET, SKT_STYLE_CONNECT,
**	    string addr,
**	    function read_func,
**	    function close_func
**	    );
*/

/*
** SKT_STYLE_UDP
**
** These sockets are created as:
**
**	new(SOCKET, SKT_STYLE_UDP,
**	    int listenport,
**	    function read_func
**	    );
**
** When a connection arrives, a new socket object will be cloned for the
** connection.  The read_func will be evaluated whenever data arrives.
**
** The prototypes for the function are:
**
**	void read_func(object socket, string data, string address)
**
** Note: this is not a binary socket.
*/

#endif /* __SOCKET_H__ */
