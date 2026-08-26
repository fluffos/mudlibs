/*    /lib/daemon.c
 *    from Foundation II
 *    standard inheritable for daemon objects
 *    created by Descartes of Borg 940211
 */

#include <lib.h>
#include <privs.h>

inherit LIB_CLEAN;

int eventDestruct() {
    string str;
   
    if( !((int)master()->valid_apply(({ PRIV_ASSIST }))) ) return 0;
    return clean::eventDestruct();
}

