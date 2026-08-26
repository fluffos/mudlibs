// This is the standard room at the Macrosoft Corp.
// It contains a few extra functions that will come
// in handy for the really cool shit.

#include <teleport.h>
#include "../macrosoft.h"
#include "/u/c/cyanide/debug.h"

inherit ROOM;

object daemon;

void create() {
    ::create();
    seteuid(getuid());
    set("author", "cyanide");
    set("light", "@@query_light");
    set("no_teleport", NO_IN_OR_OUT);

    daemon = find_object_or_load(MS_D);
}

int query_light() {
    return
    find_object_or_load(MS_D)->query_power();
}

/* EOF */
