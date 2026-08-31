#include <std.h>
#include <amun.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("black pants");
    set_id( ({ "pants", "black pants" }) );
    set_short("%^BOLD%^%^BLACK%^black pants%^RESET%^");
    set_long(
      "%^BOLD%^%^BLACK%^These pants were specially made for the priests "
      "in the sky temple. They are light in weight, "
      "yet tough as scales.%^RESET%^"
    );
    set_type("pants");
    set_ac(2);
    set_limbs( ({ "right leg", "left leg"}) );
    set_weight(15);
    set_curr_value("gold", 100);  
}
int query_auto_load() {
    return this_player()->query_level() >= 30;
}
