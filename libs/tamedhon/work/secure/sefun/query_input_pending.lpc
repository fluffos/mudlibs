//
// Wunderland Mudlib
//
// secure/sefun/query_input_pending.c -- query_input_pending fuer ldmud 3.5
//
// $Log: query_input_pending.c,v $
// Revision 1.1  2021/03/25 16:07:06  Fuchur
// Update auf ldmud 3.6.3
//

/* This sefun is to provide a replacement for the efun query_input_pending().
 * Feel free to add it to your mudlibs, if you have much code relying on that.
 */

#if ! __EFUN_DEFINED__(query_input_pending)

#include <interactive_info.h>

object query_input_pending(object ob)
{
    if(!efun::interactive(ob))
        return 0;

    return efun::interactive_info(ob, II_INPUT_PENDING);
}

#endif
