#ifndef __NETWORK_H 
#define __NETWORK_H 
 
#include "socket_errors.h" 
 
#define MUD                       0 
#define STREAM                    1 
#define DATAGRAM                  2 
#define STREAM_BINARY             3
#define DATAGRAM_BINARY           4

#define PORT_MUD                  (__PORT__)
#define PORT_FTP                  (__PORT__+2)
#define PORT_HTTP                 (__PORT__+3)
#define PORT_OOB                  (__PORT__+5)
#define PORT_FTPAUTH              (__PORT__+10)
#undef  PORT_RCP
#undef  PORT_UDP

#define CLIENT                    "/net/inherit/client"
#define SERVER                    "/net/inherit/server"
#define INTERMUD_D                "/net/intermud3/intermud"
#define SERVICES_D                "/net/intermud3/services"
#define OOB_D                     "/net/intermud3/oob_server"

 
#endif /* __NETWORK_H */ 
