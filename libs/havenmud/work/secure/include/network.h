#ifndef __NETWORK_H
#define __NETWORK_H

#include "socket.h"
#include "config.h"

#define MUD                       0
#define STREAM                    1
#define DATAGRAM                  2
#define STREAM_BINARY             3
#define DATAGRAM_BINARY           4

#define PORT_ADMIN                17010
#define PORT_FTP                  (query_host_port() - 1)
#define PORT_HTTP                 80
#define PORT_OOB                  (query_host_port() + 5)
#define PORT_RCP                  (query_host_port() - 10)
#define PORT_UDP                  (query_host_port() + 8)

#define HOST_IP                   "23.253.225.109"
#define EXTERNAL_SMTP_SERVER      "127.0.0.1"
//#define HOST_IP                   "107.223.75.101"
//#define EXTERNAL_SMTP_SERVER      "192.168.1.9"   // Use resolved IPs only

//#define HOST_IP			 "24.160.100.128"
//#define EXTERNAL_SMTP_SERVER 	 "192.168.1.102"
#endif /* __NETWORK_H */
