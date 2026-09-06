#ifndef _SECURE_PORTS_
#define _SECURE_PORTS_ 1
#include "/sys/driver/driver_info.h"

/*--------------------------------------------------------------------------
 * /sys/secure/ports.h -- All used ports in and around OSB.
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

/* Ports served by the gamedriver */

#define NORMAL_PORT 2345   // normal login port for players
#define BACKUP_PORT 4252   // backup login port for players
#define WWW_PORT    2350   // access port for mud-served http requests
#define LOCAL_UDP_PORT  query_udp_port()  // usually 4246

/* Ports served by other programs */
#define FTP_PORT    4243   // login port for mudftp
#define HTTP_PORT   8080   // access port for normal http requests

#endif /* _SECURE_PORTS_ */
