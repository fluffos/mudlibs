#include <mudlib.h>

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author", "blood");
    set("short", "A Crystal Mace");
    set("long", @Endtext
The weight and durability of this weapon surprises you as it is very 
light, and swings quite easily. The handle is made of oak incased in
steel. The ball at the end is attached by the coiled form of a snake. The
ball is formed of a clear crystal inside of which is filled with platinum
pellets to weight the end and make it more effective.
Endtext
    );
    set("id", ({ "mace", "crystal mace" }) );
    set_weapon_type("mace");
    set("name", "mace");
    set_verbs( ({ "attack", "swing at" , "crush" }) );
set_bonus(1);
    set("nosecond",1);
    set("value", 4000);

}

