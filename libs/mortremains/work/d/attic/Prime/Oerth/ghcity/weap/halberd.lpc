#include <mudlib.h>
inherit WEAPON;

void create(){
seteuid(getuid());
set("name", "Halberd");
set_weapon_type("halberd");
set("id", ({"halberd", "weapon", "polearm" }));
set("short", "Halberd");
set("long", @Endtext
This nicely designed, elongated axe is used by members
of The Nightwatch. It looks very sharp.
Endtext
);
set_bonus(3);
set("nosecond", 0);            
set_verbs(({"pierce", "cut", "stab", "jab", "maul", "slash"}));
set_verbs2(({"pierces", "cuts", "stabs", "jabs", "mauls", "slashes"}));
set("value", 3000);
}
