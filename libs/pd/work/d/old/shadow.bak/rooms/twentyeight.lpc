//Made using Room generator by Nightshade
//Way up to roston from Forest path

#include <std.h>
#include <shadow.h>
inherit ROOM;

void init() {
    ::init();
    add_action("do_climb","climb");
}

void create() {
    ::create();
    set_short("Forest Path");
    set_properties( (["light" : 2, "night light" : 1]) );
    set_property("forest", 1);
    set_listen("default", "The ocassional twig snapping can be heard.");
    set_smell("default", "The scent of pine fills the air.");
    set_long("The paths all look the same.  It would be very easy to get lost here.  They weave in and out of the pine trees.  A large cliff blocks any attempt to travel north.  There are many small holes in this part of the cliff.");
    set_exits( (["southeast" : ROOMS+"twentyseven"
              ]) );
    set_items( ([ "path" : "The path is rough and dry, covered with various roots."
                 ,"cliff" : "The cliff is very steep and is covered with holes."
                 ,"holes" : "It seems like the holes have been used to climb up quite often."
                 ,"trees" : "The trees are a %^GREEN%^deep green%^RESET%^."
                 ]) );
}

int do_climb(string str) {
    if(this_player()->query_stats("strength") < 10+random(10)) {
        write("You climb half way and fall back down on your bum!");
        say(this_player()->query_cap_name()+" tries to climb, but falls down on their bum!");
        this_player()->add_hp(-1 * (random(20)+20));
        return 1;
    }

    write("You climb up the cliff.");
    say(this_player()->query_cap_name()+" climbs up the cliff.");
    this_player()->move("/d/roston/rooms/r_crack10");
    this_player()->describe_current_room(1);
    return 1;
}
