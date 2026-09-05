
#ifndef SOCKET_H
#define SOCKET_H

#define MUD 0
#define STREAM 1
#define DATAGRAM 2
#define STREAM_BINARY 3

#define SOCKET_LISTEN  1
#define SOCKET_CONNECT 2
#define SOCKET_UDP     3

#define SOCKET_LISTEN_B  10
#define SOCKET_CONNECT_B 11
#define SOCKET_UDP_B     12

#define SOCKET_LISTEN_M  20
#define SOCKET_CONNECT_M 21

#define SOCKET_ACQUIRE	30

#endif /* SOCKET_H */

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

