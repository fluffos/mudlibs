//Mistoffelees

#include <std.h>
inherit ARMOUR;

void create(){
    ::create();
    set_name("helmet");
    set_id( ({"helmet", "regulators helmet"}) );
    set_short("regulators helmet");
    set_weight(1);
    set_long("A mithril helmet with an opaque face shield, justice needs no
face.");
    set_ac(25);
    set_limbs( ({"head"}) );
    set_type("helmet");
    set_value(0);
}


void init() {
    ::init();
set_heart_beat(1);
}
void heart_beat() {
if(this_object()->query_worn()) {
if(environment(this_object())->query_paralyzed()) {
environment(this_object())->remove_paralyzed();
}
}
}
