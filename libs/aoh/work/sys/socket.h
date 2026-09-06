//
// Wunderland Mudlib
//
// sys/daemon/socket.h  --  Makros fuer Socketd
//
// $Log: socket.h,v $
// Revision 1.8  2002/10/22 11:39:00  Fiona
// State info S_WAITS and improved blocking handling
//

#ifndef __SOCKET_H__
#define __SOCKET_H__

#include <secure/wizlevels.h>

#define SOCKETD               "/obj/socketd"
#define SOCKETLOG             "SOCKETD"

// whos allowed to do critical things?
#define SPECIAL_PREVILEGE     IS_WIZARD(this_interactive())
#define VALID_SOCKETS ({ "/secure/", "/obj/", "/p/daemons/" })

// give usefull output, eg: sprintf("%O", x)
#ifndef MIXED2STR
#  define MIXED2STR(x)        sprintf("%O", x)
#endif

// raise an error where the guilty part is our caller
#ifndef RAISE_ERROR
#  define RAISE_ERROR(x)        raise_error("@"+(x));
#endif

#define MAX_SOCKETS           15

// callback actions
#define SOCKET_ACCEPT       0
#define SOCKET_READ         1
#define SOCKET_CLOSE        2
#define SOCKET_ERROR        3
#define SOCKET_READY        4
#define SOCKET_WRITTEN      5
#define SOCKET_INCOMPLETE   6
#define SOCKET_NOPEND       7

// access to the sockets mapping
#define S_SOCKOBJ       0
#define S_TYPE          1
#define S_TICKET        2
#define S_STATE         3
#define S_OPTS          4
#define S_HOST          5
#define S_PORT          6
#define S_LISTEN_FD     6 // for TCP_ACCEPT only
#define S_LPORT         7
#define S_CALLBACK      8
#define S_OBJECT        9
#define S_PENDING      10 // just for written-before-connected
#define S_OWNER        11
#define S_TO_WRITE     12
#define S_WRITTEN      13
#define S_RECEIVED     14
#define S_WAITS        15
#define S_WAIT_DATA    16

// values of S_TYPE
// bit 0: open/listen
// bit 1: tcp/udp
// bit 2: accepter (intern)
#define TCP_OPEN        0
#define TCP_LISTEN      1
#define UDP             3
#define TCP_ACCEPT      5

// values of S_STATE
#define S_UNCONNECTED   0
#define S_CONNECTED     1
#define S_LISTEN        2
#define S_UDP           3
#define S_CLOSING       4

// values of S_OPTS (bits)
#define SOCKET_ASCII    0
#define SOCKET_BINARY   1
#define SOCKET_MUDMODE  2

// values of S_WAITS
#define S_WAITS_NOT     0
#define S_WAITS_ERQ     1
#define S_WAITS_INCOM   2
#define S_WAITS_BLOCK   3

// should be defined by the driver according to the xerq
// configure option --with-erq-max-send=VALUE (default = 1024)
#ifndef __ERQ_MAX_SEND__
# define __ERQ_MAX_SEND__ 256 // for old driver/xerq combinations
#endif

// same as above, --with-erq-max-reply=VALUE (default = 1024)
#ifndef __ERQ_MAX_REPLY__
# define __ERQ_MAX_REPLY__ 1024
#endif

#define WRITE_MAX  (__ERQ_MAX_SEND__ - 9)

// get clone number
#define UNIQUE_ID(x) (to_int(object_name(x)[sizeof(SOCKETD)+1..]))

#ifdef NEED_PROTOTYPES
#ifndef __SOCKET_H_PROTO__
#define __SOCKET_H_PROTO__

// prototypes of daemon functions
object        ___debug(int on);
nosave void   accept_cb(int* msg, int ufd);
nosave void   callback(int ufd, int action, mixed args);
nosave void   debug(varargs mixed* x);
nosave void   flush(int fd);
nosave void   looked_up(int* msg, int ufd);
nosave void   lookup(string host, closure cb);
nosave mixed* note_err(string str, int* msg, int fd);
int           remove();
nosave void   sendbuf(int ufd, int* data, int off);
nosave void   socket_cb(int* msg, int ufd);
int           socket_close(int fd);
nosave string to_ascii(int* msg);
nosave string to_mudmode(mixed data);
nosave int    valid_socket(object ob);

#endif // __SOCKET_H_PROTO__
#endif // NEED_PROTOTYPES

#endif // __SOCKET_H__
