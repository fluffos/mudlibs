#include <mudlib.h>
#include <config.h>
#include "/u/d/dalceon/mydefines.h"
#include "/u/c/cyanide/debug.h"

inherit ROOM;

void init() {
    object orb;
    orb = find_object("/u/d/dalceon/realms/tokyo/items/sorb");

    if (orb)
	DEBUG("Found orb\n");
    else
	DEBUG("No orb.\n");

    tell_object(this_player(), file_name(this_object())+"\n");
    if(!orb) return;
    else
	call_other(orb, "orb_tell", this_object()->query("short"),orb);
}
