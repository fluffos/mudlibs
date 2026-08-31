#include <std.h>
inherit ARMOUR;

void create() {
    :: create();

    set_name("dragon breastplate");
    set_short("%^CYAN%^M%^BOLD%^%^BLACK%^ystica%^CYAN%^l Br%^BOLD%^%^BLACK%^eastpla%^CYAN%^te%^RESET%^");
    set_long("%^BOLD%^Much care went into making this breastplate. It seems that the one who" 
               "%^BOLD%^ crafted this plate used a mix of platinum and dragon scales. On the front is a"
             "%^BOLD%^ a picture of a massive dragon with a %^RED%^glowing heart%^RESET%^%^BOLD%^"
           " on it's chest.");
    set_id(({"plate", "breastplate"}));
    set_ac(7);
    set_mass(60);
    set_curr_value("gold",60+random(40));
    set_type("chainmail");
    set_limbs(({"abdomen"}));
    set_heart_beat(1);
}

int query_auto_load() { 
    if(this_player()->query_level() < 37) return 0;
    return 1;
}

void heart_beat() {
    object tp;
    tp = this_object()->query_worn();
    if(!tp) return;
    if(random(100) > 85 && tp->query_current_attacker()) {
	if(environment(tp)->query_property("no attack")) return;
          message("info", "%^BLUE%^The %^RED%^heart%^BLUE%^ on%^YELLOW%^ "+tp->query_cap_name()+"'s %^BLUE%^breastplate starts to glow%^RED%^ red!", environment(tp), tp);
          message("info", "%^BLUE%^The %^RED%^heart%^BLUE%^ on your breastplate glows %^RED%^red!", tp);
          tp->heal(random(100)*2+20);
    }
}
