// Cyanide, 23 Feb 2000

#include <mudlib.h>

inherit ARMOR ;

void create() {
    seteuid(getuid());

    set("author", "cyanide");
    set("id", ({ "suit", "navy blue suit", "expensive suit" }) );
    set("short", "an expensive navy blue suit" );
    set("long", @EndText
Upon close inspection, this rather stylish yet professional suit
appears to be woven not from wool or cotton, but some kind of 
ultra-modern impact resist material, giving the suit superior
protective qualities.
EndText
    );
    // All armor objects need to set a "type", ie suit, shield, helmet, boots,
    // whatever. The player can wear only one of each type of armor.
    set_armor_type("robes");
    set("armor", 5);
    set_bonus(2, 2);
    set("value", 1000);
}
