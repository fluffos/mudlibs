#include <std.h>
#include <venenum.h>
inherit BAG;

void create() {
    ::create();
    set_name("");
    set_id( ({ "pirouette_obj"}) );
    set_short("");
    set_long("Eep.");
    set_mass(0);
    set_value(0);
}

int start_stuff()

{
    this_player()->add_skill_bonus("defense", -(this_player()->query_skill("defense")/2), 10);
    call_out("stop_stuff",10);
    this_player()->fix_vital_bonus();
    return 1;
}

int stop_stuff()

{
    this_player()->fix_vital_bonus();
    return 1;
}
