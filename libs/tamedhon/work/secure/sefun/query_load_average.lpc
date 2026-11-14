//
// Wunderland Mudlib
//
// secure/sefun/query_load_average.c -- query_load_average fuer ldmud 3.5
//
// $Log: query_load_average.c,v $
// Revision 1.1  2021/03/25 16:07:06  Fuchur
// Update auf ldmud 3.6.3
//

/* This sefun is to provide a replacement for the efun query_load_average().
 * Feel free to add it to your mudlibs, if you have much code relying on that.
 */

#if ! __EFUN_DEFINED__(query_load_average)

#include <driver_info.h>

string query_load_average()
{
    return efun::sprintf("%.2f cmds/s, %.2f comp lines/s",
        efun::driver_info(DI_LOAD_AVERAGE_COMMANDS),
        efun::driver_info(DI_LOAD_AVERAGE_LINES));
}

#endif
