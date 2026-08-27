/*  -*- LPC -*-  */
#ifndef __NETWORK_H 
#define __NETWORK_H 
 
#include "net/socket_errors.h" 
#include "net/config.h"
 
#define MUD                       0 
#define STREAM                    1 
#define DATAGRAM                  2 
#define STREAM_BINARY             3
#define DATAGRAM_BINARY           4
 
#define PORT_FTP                  (mud_port() - 1)
#define PORT_HTTP                 (mud_port() - 5)
#define PORT_OOB                  (mud_port() + 5)
#define PORT_RCP                  (mud_port() - 10)
#define PORT_UDP                  (mud_port() + 8) 

#endif /* __NETWORK_H */ 
