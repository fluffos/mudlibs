#include <macros.h>
#include "priest_monster.h"

int counter;
string *path, *to_path, *from_path, start_location, dest_location;
string real_short, attend_short;
status going_to_vespers;


void
create_monster() {
    set_guild(GN_PRIEST);
    VESPER_D->add_me(this_object());
}

status
env_is(string file) {
    string tmp;

    tmp = SOURCE_OB(ENV);
    if(tmp[0..0] != "/") tmp = "/" + tmp;
    return file == tmp;
}

void
go_to_vespers(string canon_hour) {
    if(!env_is(start_location))
	return; // Let's not go anywhere if not in right place

    ENV->tell_here(sprintf("%s prepares to leave to %s.",
	query_name(), canon_hour));
    set_short(query_name() + " is going to " + canon_hour);
    path = to_path;
    going_to_vespers = 1;
    call_out("on_the_way", 3);
}


void
back_to_work() {
    if(!env_is(dest_location))
	return; // Let's not go anywhere if not in right place

    path = from_path;
    going_to_vespers = 0;
    set_short(query_name() + " is on his way back to his chamber");
    call_out("on_the_way", 3);
}


on_the_way(){
    command(path[counter++], this_object());
    if(counter >= (sizeof(path))) {
	set_short((going_to_vespers&&attend_short) ? attend_short:real_short);
	counter = 0;
    }
    else
	call_out("on_the_way", 20+random(20));
}
