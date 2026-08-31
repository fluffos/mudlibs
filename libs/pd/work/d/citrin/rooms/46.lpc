#include <std.h>
#include <citrin.h>
#define OPEN

inherit ROOM;

void create() {
    ::create();
    set_name("catwalk");
    set_short("catwalk");
    set_long("The air is moist.  The catwalk has collapsed here "
      "preventing anyone from traveling further across the "
      "overflow.");
    set_exits((["west":ROOMS"47"]));
}

void init() {
    ::init();
    add_action("east", "east");
}

int east() {
#ifdef OPEN
    write("You try to walk east but fall into the water.\n");
    say(this_player()->query_cap_name()+" falls into the water like "
      "an idiot.");
    this_player()->move("/d/citrin/rooms/lake/1,1");
    this_player()->force_me("look");
    return 1;
#else
    return 0;
#endif
    return 0;
}

