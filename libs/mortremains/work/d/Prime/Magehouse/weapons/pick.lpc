#include <mudlib.h>
      
inherit WEAPON;
    
void create() {
    seteuid(getuid());  
    set("author", "blood");
    set("short", "Mining Pick");
    set("long", @Endtext
This pick is used by the gnomes to extract ore from the mines.
Endtext
    );
    set("id", ({ "pick", "mining pick" }) );
    set("damage_type", "piercing");
    set_weapon_type("dagger");
    set("name", "pick");
    set_verbs( ({ "attack" , "thrust at" , "jab" }) );
    set("nosecond",0);
    set("value", 1600);
}
