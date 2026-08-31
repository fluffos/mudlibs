//  Whit

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_name("temp room");
    set_short("inside a void");
    set_long("You are uncouncious.");
    skip_obvious();
}

void init() {
    ::init();
    add_action("over", "", 1);
}

int over() {
    if(wizardp(this_player())) return 0;
    write("You are uncouncious.\n");
    return 1;
}


