//
// Wunderland Mudlib
//
// secure/sefun/query_editing.c -- query_editing fuer ldmud 3.5
//
// $Log: query_editing.c,v $
// Revision 1.1  2021/03/25 16:07:06  Fuchur
// Update auf ldmud 3.6.3
//

/* This sefun is to provide a replacement for the efun query_editing().
 * Feel free to add it to your mudlibs, if you have much code relying on that.
 */

#if ! __EFUN_DEFINED__(query_editing)

#include <interactive_info.h>

int|object query_editing(object ob)
{
    if(!efun::interactive(ob))
        return 0;

    return efun::interactive_info(ob, II_EDITING);
}

#endif
