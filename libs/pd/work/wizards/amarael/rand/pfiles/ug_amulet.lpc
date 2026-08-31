#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_properties( (["no steal" : 1]) );
    set_name("amulet");
    set_id( ({"amulet", "gift", "gift of the solar"}) );
    set_short("%^YELLOW%^Gift %^WHITE%^of the %^YELLOW%^Solar%^RESET%^ ");
    set_long("The shining amulet is made of a bright %^YELLOW%^golden%^RESET%^ "
      "metal, showing a pair of scales backed with the %^BOLD%^RED%^flaming%^RESET%^ "
      "sun.  On one side of the scales, there is a %^BOLD%^WHITE%^silver sword%^RESET%^, "
      "thrusting downwards through the scale, signifying violence.  On the other, "
      "there is a pure %^BOLD%^WHITE%^white dove%^RESET%^ about to take wing, signifying "
      "peace.  This is a rare gift given only to those who the %^ORANGE%^Illuminati%^RESET%^ believe have "
      "a chance of repentance.");
    set_type("amulet");
    set_limbs( ({"torso", "head"}) );
}

int query_auto_load() {
    if(this_player()->query_guild() == "illuminati")
        return 1;
}

int drop() {
    return 1;
}
