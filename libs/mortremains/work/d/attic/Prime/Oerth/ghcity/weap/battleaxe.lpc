#include <mudlib.h>
inherit WEAPON;

void create(){
seteuid(getuid());
set("name", "Battleaxe");
set_weapon_type("axe/battle");
set("id", ({"battleaxe", "weapon", "axe"}));
set("short", "Battleaxe");
set("long", @Endtext
This finely crafted battleaxe is used by members
of The Nightwatch. It looks very sharp.
Endtext
);
set_bonus(3);
set_verbs2(({"pierces", "cuts", "stabs", "jabs", "mauls", "slashes"}));
set("value", 3000);
}
