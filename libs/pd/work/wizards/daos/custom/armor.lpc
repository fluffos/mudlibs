#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("armor");
    set("id", ({"armor", "armor of the lidless"}) );
    set_short("%^RED%^Arm%^RESET%^%^BOLD%^%^RED%^or%^RESET%^ %^BOLD%^%^RED%^o%^RESET%^"
      "%^BOLD%^%^YELLOW%^f%^RESET%^ %^ORANGE%^t%^RESET%^%^h%^%^ORANGE%^e%^RESET%^ "
      "%^BOLD%^%^YELLOW%^L%^RESET%^%^BOLD%^%^RED%^idl%^RESET%^%^RED%^ess%^RESET%^");
    set_long("The armor is made from the remains of fallen heroes.  Skulls "
      "cover her shoulders.");
    set_type("body armour");
    set_limbs( ({"torso", "right arm", "left arm"}) );
}

int query_auto_load() {
    if(this_player()->query_name() == "melphista")
	return 1;
}
