//
// Wunderland Mudlib
//
// secure/sefun/query_snoop.c -- query_snoop fuer ldmud 3.5
//
// $Log: query_snoop.c,v $
// Revision 1.1  2021/03/25 16:07:06  Fuchur
// Update auf ldmud 3.6.3
//

/* This sefun is to provide a replacement for the efun query_snoop().
 * Feel free to add it to your mudlibs, if you have much code relying on that.
 */

#if ! __EFUN_DEFINED__(query_snoop)

#include <interactive_info.h>

private object efun_query_snoop(object ob)
{
    if(!efun::interactive(ob))
        return 0;

/*
    object prev = efun::previous_object();
    efun::set_this_object(prev);
*/

    return efun::interactive_info(ob, II_SNOOP_NEXT);
}

#else

#define efun_query_snoop efun::query_snoop

#endif
