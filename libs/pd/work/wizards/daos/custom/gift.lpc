#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_properties( (["no steal" : 1]) );
    set_name("amulet");
    set("id", ({"amulet", "gift", "gift of the solar"}) );
    set_short("Gift of the Solar");
    set_long("The shining amulet is made of a bright %^BOLD%^YELLOW%^golden%^RESET%^ "
      "metal, showing a pair of scales backed with the %^BOLD%^RED%^flaming%^RESET%^ "
      "sun.  On one side of the scales, there is a %^BOLD%^silver sword,%^RESET%^ "
      "thrusting downwards through the scale, signifying violence.  On the other, "
      "there is a pure %^BOLD%^white dove%^RESET%^ about to take wing, signifying "
      "peace.  This is a rare gift given only to those who Illuminati believe have "
      "a chance of repentance.");
    set_type("amulet");
    set_limbs( ({"torso"}) );
}

int query_auto_load() {
    if (this_player()->query_name() == "paranoia")
	return 1;
}
