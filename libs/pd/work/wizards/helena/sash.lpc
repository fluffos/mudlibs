
#include <std.h>

inherit ARMOUR;

int wear_message() {
  message("message", "%^BOLD%^%^YELLOW%^Soothing chanting is heard as "+this_player()->query_cap_name()+" wears the Golden Sash.", environment(this_player()));
  return 1;
}


void create() {
  ::create();
    set_name("golden sash");
    set_short("%^BOLD%^%^YELLOW%^Golden Sash of Hope%^RESET%^");
    set_long("%^BOLD%^%^YELLOW%^Hand woven by the monks of the Ancient Worlds, blessed by the High Priest of Alsta, this Sash is truly a wonder to behold.%^RESET%^");
    set_id(({ "sash" }));
    set_mass(1000);
    set_curr_value("copper", 1);
    set_type("sash");
    set_limbs(({ "torso" }));
    set_wear( (: wear_message :) );
    set_remove("%^BOLD%^%^YELLOW%^The soothing sound of the chanting disappears.");
}

int query_auto_load() {
    if(this_player()->query_level() >=900) return 1;
    if(this_player()->query_cap_name()=="helena") return 1;
    return 0;
}
