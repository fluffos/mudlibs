#include <mudlib.h>

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author", "blood");
    set("short", "Fire Burned Dagger");
    set("long", @Endtext
This short dagger obviously was meant for close combat. Long tendrils of
flame flick out from the blade as you give it a good test swing.
hmm, maybe its not a good idea to be so close.
Endtext
    );
    set("id", ({ "dagger", "fire dagger", "fire burned dagger" }) );
    set_weapon_type("knife");
    set("damage_type", "fire" );
    set("name", "dagger");
    set_verbs( ({ "attack" , "slice at" , "thrust at" }) );
    set("nosecond",0);
    set_bonus(2);
    set("value", 500);
    
}   
