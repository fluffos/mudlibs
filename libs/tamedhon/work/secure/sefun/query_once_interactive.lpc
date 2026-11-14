//
// Wunderland Mudlib
//
// secure/sefun/query_once_interactive.c -- query_once_interactive fuer ldmud 3.5
//
// $Log: query_once_interactive.c,v $
// Revision 1.1  2021/03/25 16:07:06  Fuchur
// Update auf ldmud 3.6.3
//

/* This sefun is to provide a replacement for the efun query_once_interactive().
 * Feel free to add it to your mudlibs, if you have much code relying on that.
 */

#if ! __EFUN_DEFINED__(query_once_interactive)

#include <object_info.h>

int query_once_interactive(object ob)
{
    return efun::object_info(ob, OI_ONCE_INTERACTIVE);
}

#endif
