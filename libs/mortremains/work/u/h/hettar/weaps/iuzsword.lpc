#include <mudlib.h>
inherit WEAPON;

void create(){
seteuid(getuid());
set("name","Longsword");
set_weapon_type("sword/long");
set("id", ({"sword", "weapon", "longsword"}));
set("short", "A blackened Longsword");
set("long", @Endtext
This is a finely crafted longsword used by members
of Iuz's Greater Bone Heart.
Endtext
);
set_bonus(100);
set("damage", ({50,100}));
set("nosecond", 0);
set_verbs(({"pierce", "cut", "stab", "jab", "maul", "slash"}));
set_verbs2(({"pierces", "cuts", "stabs", "jabs", "mauls", "slashes"}));
set("value", 1800);
}

int query_auto_load() { return 1; }
