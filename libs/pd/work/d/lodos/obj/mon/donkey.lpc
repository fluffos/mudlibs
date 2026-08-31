#include <std.h>
#include <lodos.h>
inherit MOUNT;

void create() {
    ::create();
    set_name("donkey");
    set_id( ({ "monster" , "donkey" }) );
    set_short("%^RESET%^%^WHITE%^Donkey%^RESET%^");
    set_level(15);
    set_long("The donkey walks around in circles wanting to get out of the meadow.");
    set_race("donkey");
    set_body_type("donkey");
    if(random(2) == 0)
	set_gender("male");
    else
	set_gender("female");
    set("aggressive", 5);
    this_object()->add_money("gold", random(20));
}
