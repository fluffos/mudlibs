#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("robe");
   set_short("%^RESET%^%^BLUE%^a bri%^BOLD%^lliant%^YELLOW%^ robe "
     "o%^BLUE%^f many s%^RESET%^%^BLUE%^tars%^RESET%^");
   set_long("The midnight blue robe has many brilliant dots of light "
     "in it. Each pinpoint of light holds the fury of a star.");
   set_limbs(({ "torso", "left leg", "right leg", "left arm",
                "right arm" }));
   set_id(({ "robe", "robe of stars", "starred robe", "stars" }));
   set_weight(11);
   set_ac(1);
   set_type("robes");
    set_curr_value("gold", 25);
}

int query_auto_load() {
   if (this_player()->query_level() >= 23) return 1;
}
