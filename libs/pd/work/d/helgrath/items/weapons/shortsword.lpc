#include <std.h>
inherit "/std/weapon";
create(){
    ::create();
    set_name("sword");
    set_id(({"weapon","sword","shortsword","rusty shortsword"}));
    set_short("rusty shortsword");
    set_long(
      "This weapon looks to have been in the ground for almost as long as the corpse who once wielded it."
    );
    set_curr_value("gold",5+random(25));
    set_weight(22);
    set_wc(6);
    set_type("blade");
    set_wield((: this_object(), "rusty" :));
}
int rusty(){
    tell_room(environment(this_player()), "Some rust falls off the shortsword.");
    return 1;
}
int query_auto_load() { return 1; }
