//Dragon quest area
//Nightshade

#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Stone Cave");
    set_properties( (["light" : 2, "night light" : 2]) );
    set_property("indoors", 1);
    set_property("no teleport", 1);
    set_listen("default", "Dripping water echos off the walls.");
    set_long("This cavernous room towers to the point where the ceiling cannot be seen.  Stalagmites seem to have sprouted up all over the floor here.  A small stream is trickles through the middle of the cavern.  There is a huge hole in the floor here.  There seems to be no way out but the hole.");
    set_exits( (["hole" : "/d/tirun/monastery"]) );
    set_items( ([ "ceiling" : "The ceiling disappears into darkness.  The occasional stalagtite can be seen poking through the darkness."
                 ,"stalagmites" : "The stalagmites dot the floor, some raising far above your head."
                 ,"hole" : "The hole leads into an unknown darkness."
                 ,"stream" : "The stream shimmers and flows towards a wall.  Curiously, you cannot tell where the water goes."
                 ]) );
}

void init() {
    ::init();
    add_action("search", "search");
    add_action("swim", "swim");
    add_action("peer", "peer");
}

int peer(string str) {
    if(str != "hole")
        return 0;
    write("You peer into the hole, but cannot see where it leads.");
    return 1;
}

int search(string str) {

    if(str != "water" && str != "stream")
        return 0;
    write("You notice that the water goes into an underground tunnel!  You may be able to swim through it.");
    return 1;
}

int swim(string str) {
    if(str != "through")
        return 0;
    write("%^CYAN%^You dive into the icy water, and swim through the small tunnel.");
    this_player()->move_player("/d/quests/dragon/two", "into the water");
    return 1;
}
