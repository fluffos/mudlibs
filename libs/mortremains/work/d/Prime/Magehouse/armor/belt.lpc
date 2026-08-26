#include <mudlib.h>

inherit ARMOR ;

void create() {
    // You forgot this again.
    seteuid(getuid());

    set ("id", ({ "belt", "leather belt" }) );
    set ("name", "belt");
    set ("short", "Leather Belt") ;
    set ("long", @EndText
A fine leather belt.
EndText       
    );            
    set_armor_type("belt");
    set_bonus(2);
    set ("value", 100);
}
