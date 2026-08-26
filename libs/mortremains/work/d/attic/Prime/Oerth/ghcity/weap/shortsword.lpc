#include <mudlib.h>
inherit WEAPON;

void create(){
seteuid(getuid());
set("name", "Shortsword");
set_weapon_type("sword/short");
set("id", ({"sword", "weapon", "shortsword"}));
set("short", "Shortsword");
set("long", @Endtext
This is a nicely crafted shortsword. It's well balanced
and you noticed tiny runes tracing up the blade.
Endtext
);
set_bonus(4);
set_verbs(({"pierce", "cut", "stab", "jab", "maul", "slash"}));
set_verbs2(({"pierces", "cuts", "stabs", "jabs", "mauls", "slashes"}));
set("value", 1800);
}
