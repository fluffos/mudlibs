#include <mudlib.h>

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author", "blood");
    set("short", "Chocolate Choppers");
    set("long", @Endtext
These underestimated weapons are in the shape of somewhat large chocolate
chip cookies. However, when thrown, they can be quite sharp and deadly.
Endtext
    );
    set("id", ({ "choppers", "chocolate" , "chocolate choppers" }) );
    set_weapon_type("spear");
    set("name", "choppers");
    set_verbs( ({ "attack" , "throw at" }) );
    set("nosecond",0);
    set_bonus(1);
    set("value", 10);

}   
