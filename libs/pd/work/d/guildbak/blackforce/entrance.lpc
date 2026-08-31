// Coded by Whit

#include <std.h>
inherit ROOM;

int down(string str);

void init() {
    ::init();
    add_action("down", "down");
}

void create() {
    ::create();
    set_short("Black Force Guild Entrance");
    set_properties( (["light" : 3, "night light" : 2]) );
    set_smell("default", "The smell of Death lingers through here.");
    set_long("This is the begining of the hidden depths of the "
      "Scorpios.  The only source of light comes from a "
      "small, black sphere floating overhead.   A stairwell leads down "

      "into the heart of the guild.");
    set_exits( (["down" : "/d/guilds/blackforce/hall"
        ,"out" : "/d/tirun/wganthus2"
      ]) );
}


int down(string str) {
    if(this_player()->query_guild() != "scorpio") {
        write("You are not part of the Guild.");
        return 1;
    }
    this_player()->move_player("/d/guilds/blackforce/hall");
    return 1;
}
