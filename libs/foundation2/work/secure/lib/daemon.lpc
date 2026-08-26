/*    /lib/daemon.c
 *    from Foundation II
 *    standard inheritable for daemon objects
 *    created by Descartes of Borg 940211
 */

#include <lib.h>
#include <security.h>

inherit LIB_CLEAN;

int eventDestruct() {
    string str;
   
    if(!((int)master()->valid_apply( ({ "assist" }) ))) return 0;
    return clean::eventDestruct();
}

int query_prevent_shadow() { return 1; }
