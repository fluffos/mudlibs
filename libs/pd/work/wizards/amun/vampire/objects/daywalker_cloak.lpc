#include <std.h>
#include <vampq.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Daywalker Cloak");
    set_short("%^ORANGE%^Da%^BOLD%^%^BLACK%^yw%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^lker Cloak%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Pitch black in colour, this cloak covers the entire body of the wearer. The fabric feels different, soft, strong and warm to the touch.\n\n%^BOLD%^%^RED%^A powerful %^CYAN%^energy%^RED%^ emits from this.%^RESET%^");
    set_id(({"cloak", "daywalker cloak", "daywalker"}));
    set_ac(10);
    set_mass(5);
    set_value(0);
    set_wear("The %^BOLD%^%^BLACK%^cloak%^RESET%^ drapes over your entire body.");
    set_remove("The %^BOLD%^%^BLACK%^cloak%^RESET%^ flows off your body as it's removed.");
    set_type("cloak");
    set_limbs(({"head", "torso", "right arm", "right hand", "left arm", "left hand", "right leg", "right foot", "left leg", "left foot"}));
}

int query_auto_load() {
    if(this_player()->query_level() >= 40 && this_player()->query_race() == "human") return 1;
}

int can_wear() {
    if((string)this_player()->query_race() == "human") {
	return 1;
    }
    if((string)this_player()->query_race() != "human") { 
	this_player()->force_me("drop daywalker cloak");
	return 0;
    }
}
