#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("shirt");
    set("id", ({"shirt", "whit shirt"}) );
    set_short("%^BOLD%^BLACK%^I%^RESET%^ %^BOLD%^RED%^<3%^RESET%^ %^BOLD"
      "%^BLACK%^Whit Shirt%^RESET%^");
    set_long("%^BOLD%^BLACK%^An extra large T-shirt that on the front says%^RESET%^ "
      "%^BOLD%^'%^RESET%^I love Whit!%^BOLD%^'%^RESET%^  %^BOLD%^BLACK%^On the "
      "back there is a anime style picture of Whit.  This is Endy's favorite "
      "shirt that she wears every day slaughtering monsters.");
    set_type("shirt");
    set_limbs( ({"torso"}) );
}

int query_auto_load() {
    if(this_player()->query_name() == "endy")
	return 1;
}
