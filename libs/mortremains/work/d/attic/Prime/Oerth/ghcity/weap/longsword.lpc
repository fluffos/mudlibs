#include <mudlib.h>
inherit WEAPON;

void create(){
seteuid(getuid());
set("name","Longsword");
set_weapon_type("sword/long");
set("id", ({"sword", "weapon", "longsword"}));
set("short", "Longsword");
set("long", @Endtext
This is a finely crafted longsword used by members
of the Greyhawk City watch. The hilt is encrusted
with sapphires.
Endtext
);
set_bonus(2,2,5);
set("nosecond", 0);
set_verbs2(({"pierces", "cuts", "stabs", "jabs", "mauls", "slashes"}));
set("value", 1800);
}
