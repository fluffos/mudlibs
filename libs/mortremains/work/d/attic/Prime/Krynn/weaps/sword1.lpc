#include <mudlib.h>
inherit WEAPON;

void create(){
seteuid(getuid());
set("name","Longsword");
set_weapon_type("sword/long");
set("id", ({"sword", "weapon", "longsword"}));
set("short", "Longsword");
set("long", @Endtext
The long blade looks like it could cut through solid stone. 
The hilt, though ornate, is not cumbersome and very easy
to handle.
Endtext
);
set_bonus(5,5,5);
set("damage", ({100,500}));
set("nosecond", 0);
set_verbs(({"stab", "slash", "hack", "tear", "cut"}));
set_verbs2(({"stabs", "slashes", "hacks", "tears", "cuts"}));
}
