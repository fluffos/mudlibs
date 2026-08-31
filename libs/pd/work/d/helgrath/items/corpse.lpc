#include <std.h>
#include <tirun.h>
inherit BAG;

void create() {
    ::create();
    set_name("a frozen corpse");
    set_id( ({ "corpse", "frozen corpse" }) );
    set_short("a frozen corpse");
    set_long("This is the dead body of a Helgrath Guardian.\n");
    set_max_internal_encumbrance(500);
    set_value(0);
    set_prevent_get("The corpse is frozen to the ground.");
    new(WEP"dagger")->move(this_object());
}
