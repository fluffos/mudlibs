//Elite Ethereal Raknid Armour by Barrin

#include <std.h>
#include "ether.h"
inherit ARMOUR;
void create() {
	::create();
	set_name("carapace");
	set("id",({"ruby","shell","carapace"}));
	set("short","%^RED%^R%^BOLD%^u%^RESET%^b%^RED%^y%^BOLD%^"
" E%^RESET%^n%^RED%^c%^BOLD%^r%^RESET%^u%^RED%^s%^BOLD%^t"
"%^RESET%^e%^RED%^d%^BOLD%^ C%^RESET%^a%^RED%^r%^BOLD%^a%^RESET%^p%^RED%^a"
"%^BOLD%^c%^RESET%^e");
	set("long", "This %^YELLOW%^le%^RESET%^ge%^YELLOW%^nd%^RESET%^ar%^YELLOW%^y"
"%^RESET%^ armour was excavated by %^RED%^dwarven archeologists"
"%^RESET%^ in the caverns north of %^CYAN%^Roston%^RESET%^. "
"Rumours say a great %^CYAN%^wizard%^RESET%^ and a %^BLUE%^"
"necromancer%^RESET%^ used their %^YELLOW%^p%^RED%^o%^YELLOW%^w%^RED%^e%^YELLOW%^r"
"%^RED%^s%^RESET%^ to encase the coccoon of a %^BLUE%^n%^RESET%^i%^BLUE%^g"
"%^RESET%^h%^BLUE%^t%^RESET%^s%^BLUE%^t%^RESET%^a%^BLUE%^l%^RESET%^k"
"%^BLUE%^e%^RESET%^r%^RESET%^ with the enchanted %^RED%^ruby"
"%^RESET%^ of Lodos. Fact or fiction, this %^GREEN%^masterpiece"
"%^RESET%^ of %^CYAN%^craftsmanship%^RESET%^ certainly should "
"only be worn by the greatest of raknids. ");
	set_type("body armour");
	set_ac(9);
	set_limbs(({"torso","abdomen"}));
	set_weight(100);
set_curr_value("gold",120);
	set_wear("You shut your %^CYAN%^eyes%^RESET%^ as the "
"carapace %^RED%^clenches%^RESET%^ you tight and sticks to your body.");
	set_element("fire",10);
	set_element("ice",5);
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
     write("Stop wasting time, you're not worthy!");
     return 1;
}
