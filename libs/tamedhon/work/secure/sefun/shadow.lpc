//
// Wunderland Mudlib
//
// secure/sefun/shadow.c -- query_shadowing() fuer ldmud 3.5
//
// $Log: shadow.c,v $
// Revision 1.1  2021/03/25 16:07:06  Fuchur
// Update auf ldmud 3.6.3
//

/* These sefuns are to provide a replacement for the efun query_shadowing()
 * and the old semantics of the efun shadow().
 * Feel free to add it to your mudlibs, if you have much code relying on that.
 */

#if ! __EFUN_DEFINED__(query_shadowing)

#include <object_info.h>

object query_shadowing(object ob)
{
    return efun::object_info(ob, OI_SHADOW_PREV);
}

private object efun_shadow(object ob, int flag)
{
    if(flag)
    {
        efun::set_this_object(efun::previous_object());

        if (efun::shadow(ob))
            return efun::object_info(this_object(), OI_SHADOW_PREV);
        else
            return 0;
    }
    else
        return efun::object_info(ob, OI_SHADOW_NEXT);
}

#else

#define efun_shadow efun::shadow

#endif
