//Elite Ethereal Centaur Armour by Barrin


#include <std.h>
#include "ether.h"
inherit ARMOUR;
int addedsp;
void create() {
	::create();
	set_name("centaurus armatura");
	set("id",({"centaurus","armatura","armour","centaurus armatura"}));
	set("short","%^BLACK%^%^BOLD%^Cen%^RESET%^%^RED%^tau%^BOLD%^ru"
"%^RESET%^s%^BOLD%^%^RED%^ Ar%^RESET%^%^RED%^mat%^BOLD%^%^BLACK%^ura"
"%^RESET%^");
	set("long", "This heavy piece of armour was created by the %^CYAN%^best%^RESET%^"
                    " blacksmiths across the land. Looking closely at it, it becomes"
                    " apparant that the material isn't really %^BOLD%^%^BLACK%^black%^RESET%^!"
                    " The armour is merely surrounded by a %^BOLD%^%^BLACK%^dark aura%^RESET%^"
                    " which absorbs all the %^YELLOW%^light%^RESET%^.");
	set_type("body armour");
	set_ac(9);
	set_limbs(({"horse torso"}));
	set_weight(30);
set_curr_value("gold",300);
	set_heart_beat(1);
	}

int query_auto_load() { 
	if (this_player()->query_level() > 49) return 1; 
	return 0;
}


void init() {
	::init();
	add_action("my_wear", "wear");
	}

int my_wear(string str) {
     if (!str || present(str, this_player()) != this_object()) return 0;
    if (this_player()->query_level()>49) return 0;
     write("You find the armour too big for you.");
     return 1;
}


