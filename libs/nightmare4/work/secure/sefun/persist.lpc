/*    /secure/sefun/persist.c
 *    from the Nightmare IV LPC Library
 *    handles efuns for persistance support
 *    created by Beek@Nightmare 950529
 */

#include <daemons.h>

object unique(string fn, int rare) {
    return (object)UNIQUE_D->GetUniqueCopy(fn, rare);
}

int query_reset_number() { return (int)master()->GetResetNumber(); }
