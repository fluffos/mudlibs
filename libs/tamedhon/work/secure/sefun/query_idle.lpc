//
// Wunderland Mudlib
//
// secure/sefun/query_idle.c -- query_idle fuer ldmud 3.5
//
// $Log: query_idle.c,v $
// Revision 1.1  2021/03/25 16:07:06  Fuchur
// Update auf ldmud 3.6.3
//

/* This sefun is to provide a replacement for the efun query_idle().
 * Feel free to add it to your mudlibs, if you have much code relying on that.
 */

#if ! __EFUN_DEFINED__(query_idle)

#include <interactive_info.h>

int query_idle(object ob)
{
    return efun::interactive_info(ob, II_IDLE);
}

#endif
