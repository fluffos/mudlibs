/*
**  Credits:
13 June 99 Shya Created
*/
#include <mudlib.h>

inherit WEAPON;

void create() {
    seteuid(getuid());
    set ("author", "shya");
    set_weapon_type("pick/axe");
    set("id", ({ "icepick", "axe" }) );
    set("short", "an icepick");
    set("long", wrap("This icepick is sharp and chilling to the touch, "+
	"and sharp enough to cut ice and people aplenty."));
    set("name", "pick");
    set_bonus(5);
    set("nosecond", 0);
    set("light", 1);
    set_verbs( ({ "slash", "stab", "cut" }) );
}
