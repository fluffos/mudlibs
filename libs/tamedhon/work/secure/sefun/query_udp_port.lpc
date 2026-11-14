//
// Wunderland Mudlib
//
// secure/sefun/query_udp_port.c -- query_udp_port fuer ldmud 3.5
//
// $Log: query_udp_port.c,v $
// Revision 1.1  2021/03/25 16:07:06  Fuchur
// Update auf ldmud 3.6.3
//

/* This sefun is to provide a replacement for the efun query_udp_port().
 * Feel free to add it to your mudlibs, if you have much code relying on that.
 */

#if ! __EFUN_DEFINED__(query_udp_port)

#include <driver_info.h>

int query_udp_port()
{
    return efun::driver_info(DI_UDP_PORT);
}

#endif
