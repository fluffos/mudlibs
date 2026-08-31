#include <std.h>
inherit WEAPON;

void create() {
  ::create();
    set_name("coral club");
    set_id(({ "club", "coral club" }));
    set_short("%^MAGENTA%^A Coral Club%^RESET%^");
    set_long("A typical club made out of %^MAGENTA%^Coral%^RESET%^ too hard to fashion nicely.");
    set_type("blunt");
    set_wc(5);
    set_weight(20);
    set_curr_value("gold", 10+random(30));
}

int query_auto_load(){
    if (this_player()->query_level() >= 10) return 1;
    return 0;
}
