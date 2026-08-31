#include <std.h>
inherit WEAPON;

void create() {
  ::create();
    set_name("seaweed flail");
    set_id(({ "flail", "seaweed flail" }));
    set_short("%^BOLD%^%^GREEN%^A Seaweed Flail%^RESET%^");
    set_long("When seaweed is cultured and grown to be too tough for weaving, it is used to make a flail, such as this one.");
    set_type("flail");
    set_wc(5);
    set_weight(15);
    set_curr_value("gold", 10+random(30));
}

int query_auto_load(){
    if (this_player()->query_level() >= 10) return 1;
    return 0;
}
