#ifndef _SOCKET_H_
#define _SOCKET_H_

#define SOCKET "/obj/socket"                          /* the socket object */

#define SOCKET_LOG   "SOCKET"                        /* the socket logfile */

#define TIME_OUT           30           /* 30 secs till connection timeout */

/* --------------------------------------------------------------------------
 * Socket styles for open()
 * --------------------------------------------------------------------------
 */

#define SKT_STYLE_CONNECT_MUD        1   /* Mud-mode stream socket connect */
#define SKT_STYLE_CONNECT_STREAM     2            /* Stream socket connect */

#define SKT_STYLE_LISTEN_MUD         3    /* Mud-mode stream socket listen */
#define SKT_STYLE_LISTEN_STREAM      4             /* Stream socket listen */

#define SKT_STYLE_DATAGRAM           5                  /* Datagram socket */

#define SKT_STYLE_INT_ACQUIRE        7       /* internal! transfer control */ 

#define SKT_STYLE_BINARY           128           /* Binary flag to be |'ed */

/* --------------------------------------------------------------------------
 * Socket mode defines
 * --------------------------------------------------------------------------
 */

#define SKT_MODE_MUD        0                    /* Mud-mode stream socket */
#define SKT_MODE_STREAM     1                             /* Stream socket */
#define SKT_MODE_DATAGRAM   2                           /* Datagram socket */

#define SKT_MODE_BINARY   128                    /* Binary flag to be |'ed */

/* --------------------------------------------------------------------------
 * Socket state defines
 * --------------------------------------------------------------------------
 */

#define SKT_STATE_UNCONNECTED  0                /* socket is not connected */
#define SKT_STATE_CONNECTED    1     /* socket is connected (datagram too) */
#define SKT_STATE_LISTEN       2  /* stream socket listens for connections */
#define SKT_STATE_ACCEPT       3   /* stream socket awaits connection data */

/* --------------------------------------------------------------------------
 * Misc defines
 * --------------------------------------------------------------------------
 */

/* fix length replies from erq */
#define FIX_REPLY

/* log invalid data received in mud-mode and close socket upon receive */
#define DEBUG_MUDMODE

/* log all erq-tickets */
#undef DEBUG_TICKET

/* log all errors that lead to socket close */
#undef DEBUG_CLOSE

/* remember times of last send and receive and a total amount for both */
#define DEBUG_READWRITE

#endif
