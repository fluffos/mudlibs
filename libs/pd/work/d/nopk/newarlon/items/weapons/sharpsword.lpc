#include <std.h>
inherit WEAPON;

int weapon_hit();
void create() {::create();
     set_name("a sharp looking sword");
     set_short("a sharp looking sword");
     set_long("This steel bladed, black hilted sword looks very sharp.  It is fairly light, and seems to be mass produced in the cheapest way possible.");
     set_id( ({"sword", "sharp sword", "sharpsword"}) );
     set_hands(1);
     set_wc(2);
     set_weight(5);
     set_curr_value("gold", 30+random(35));
     set_type("blade");
}
int query_auto_load() { return 1; }

