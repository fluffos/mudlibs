//  Whit

#include <std.h>
#undef STARTED

inherit OBJECT;

void create() {
    ::create();
    set_name("event");
    set_short("event_item");
    set_long("Event_item");
}

void init() {
    ::init();
    add_action("glow", "glow");
}

int glow() {
    write("Your eyes begin to glow.\n");
    message("environment", this_player()->query_cap_name()+"'s eyes start "
      "to glow.\n", 
      environment(this_player()), ({this_player()}) );
    if(this_player()->query_description())
	this_player()->set_description(this_player()->query_description()+
	  "\n"+capitalize(possessive(this_player()))+" eyes "
	  "glow red with overwhelming evil.");
    else this_player()->set_description("'s eyes glow with "
	  "overwhelming evil.");
    return 1;
}

int query_event_started() {
#ifdef STARTED
    return 1;
#else
    return 0;
#endif
}

