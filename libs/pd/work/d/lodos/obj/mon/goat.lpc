#include <std.h>
#include <lodos.h>
inherit MONSTER;

void create() {
    ::create();
    set_name("goat");
    set_id( ({ "monster" , "goat" }) );
    set_short("Goat");
    set_level(15);
    set_long("There is nothing special about the goat except its especially long beard.");
    set_race("goat");
    set_body_type("goat");
    if(random(2) == 0)
	set_gender("male");
    else
	set_gender("female");
    set("aggressive", 5);
    this_object()->add_money("gold", random(20));
}
