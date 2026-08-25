/*    /std/daemon.c
 *    from Nightmare IV
 *    standard inheritable for daemon objects
 *    created by Descartes of Borg 940211
 */

#include <std.h>
#include <security.h>

inherit CLEAN_UP;

int remove() {
    string str;
   
    if(!((int)master()->valid_apply( ({ "assist" }) ))) return 0;
    return clean_up::remove();
}

int query_prevent_shadow() { return 1; }
