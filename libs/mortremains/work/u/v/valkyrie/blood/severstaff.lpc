#include <mudlib.h>

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author", "blood");
    set("short", "Staff of Severing");
    set("long", @Endtext
This staff has a random chance of severing a limb..never the head.
Endtext
    );
    set("id", ({ "staff", "staff of severing" }) );
    set_weapon_type("quarterstaff");
    set("name", "staff");
    set_verbs( ({ "attack" , "swing at" , "thrust at" }) );
    set("nosecond",1);
    set("value", 2000);
}
