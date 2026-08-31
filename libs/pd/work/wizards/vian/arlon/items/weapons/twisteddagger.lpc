#include <std.h>
inherit WEAPON;

int weapon_hit();
void create() {::create();
     set_name("a twisted dagger");
     set_short("a twisted dagger");
     set_long("This steel dagger's blade is very thin, and twisted all the way through.  The edges are serrated along the curve of the blade, making for a weapon that will hurt much more coming out than it did going in.");
     set_id( ({"dagger", "twisted dagger", "twisteddagger"}) );
     set_wc(2);
     set_weight(5);
     set_curr_value("gold", 30+random(35));
     set_type("knife");
}
int query_auto_load() { return 1; }

