#include <mudlib.h>

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author", "blood");
    set("short", "Gnomish Axe");
    set("long", @Endtext
This pick is used by the gnomes to extract ore from the mines.
Endtext
    );
    set("id", ({ "axe", "gnomish axe" }) );
    set("damage_type", "slashing");
    set_weapon_type("axe/battle");
    set("name", "axe");
    set_verbs( ({ "attack" , "swing at" , "slice" }) );
    set("nosecond",1);
    set("value", 2000);
}
