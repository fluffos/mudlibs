#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("");
    set_short("");
    set_long("Just a creepy feeling.");
    set_id(({ "creepy_feeling" }));
    set_weight(0);
    set_curr_value(0);
}

int start_fmv()

{
    call_out("stop_fmv",10);
    return 1;
}

int stop_fmv()
{
    message("feeling","You feel like someone is watching you.",this_player());
    this_object()->remove();
    return 1;
}
