#include <std.h>

inherit WEAPON;

void create() {
    ::create();
    set_id(({"divine", "sword", "holy sword"}));
    set_name("holy sword");
    set_short("%^YELLOW%^H%^WHITE%^oly %^YELLOW%^S%^WHITE%^word%^RESET%^");
    set_long("%^BOLD%^WHITE%^This holy sword draws it's power from the divine "
      "energy within it's wielder.%^RESET%^");
    set_mass(20);
    set_curr_value("gold", 200);
    set_wc(9);           
    set_type("blade");
    set_hands(1);
    set_hit( (: this_object(),"weapon_hit" :) );  
}

int weapon_hit() {
    int result;
    object tp;
    tp = this_player();
    if(random(10) == 0) {
        result=(10 + random(25));
	result += random(tp->query_level());
	tp->heal(result);
	return result;
    }
}

int query_auto_load(){ 
    if(this_player()->query_guild()=="illuminati") return 1; 
}
