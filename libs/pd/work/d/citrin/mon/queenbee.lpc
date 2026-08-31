//  Created by Whit

#include <std.h>
#include <citrin.h>

inherit MONSTER;

void force(string who) { this_object()->force_me("kill "+who); }

void create() {
    ::create();
    set_name("bee");
    set_short("queen bee");
    set_long("This is the queen bee.  She sits in the hive all day and lays eggs.");
    set_race("bee");
    set_body_type("insect");
    set_level(70);
    set_gender("female");
    set_id(({ "queen bee", "bee" }));
    this_object()->add_money("gold", random(100));
}
