#include <mudlib.h>
inherit WEAPON;

void create(){
seteuid(getuid());
set("name", "Whip");
set_weapon_type("whip");
set("id", ({"whip", "weapon" }));
set("short", "A black leather whip");
set("long", @Endtext
This long, black leather whip was specially made
for the Nightwatch Captain. If you have it, I'd
not let anyone know about it.
Endtext
);
set_bonus(4);
set_verbs(({"rip", "slash", "knock", "wrap", "sting"}));
set_verbs2(({"rips", "slashes", "knocks", "wraps", "stings"}));
set("value", 7500);
}
