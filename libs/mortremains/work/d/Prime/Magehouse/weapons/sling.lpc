#include <mudlib.h>

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author", "blood");
    set("short", "Sling of Sorrow");
    set("long", @Endtext
This sling is made from dragon hide and the projectiles are made from the
crushed bones of fallen angels.
Endtext
    );
    set("id", ({ "sling", "sling of sorrow" }) );
    set_weapon_type("club");
    set("name", "sling");
    set_verbs( ({ "attack" }) );
    set_verbs2( ({ "launches several stones at" }) );
    set("nosecond",0);
    set_bonus(1);
    set("value", 1000);

}
