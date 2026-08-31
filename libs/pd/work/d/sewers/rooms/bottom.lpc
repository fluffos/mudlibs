//Tirun Sewers
//By Nightshade

#include <std.h>
#include <sewer.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Entrance to hades");
    set_properties(([ "indoors" : 1, "no teleport" : 1 ]));
    set_listen("default", "%^RESET%^%^RED%^Flames crackle from the pit");
    set_smell("default", "Burning sulfur thickly fills the air.");
    set_long("%^RESET%^%^RED%^A gust of heat rushes by.\n%^RESET%^"
             "The entrace to this level of the sewers has changed dramatically.  "
             "The wet sliminess of the level above has changed into dry, rugged rocks.  "
             "To the north a huge pit spits fire up, releasing demons from below.");
    set_exits( (["north" : ROOMS+"bottom1"
             ,"up" : ROOMS+"2lv35"
              ]) );
    set_items( ([ "rocks" : "The walls and ground are rough, unworked rocks."
                 ,"pit" : "The pit is a too far north to peer into."
                 ,"fire" : "Little jets of fire erupt from the pit to the north."
                 ,"demons" : "Demons are jumping out of the flaming pit fully armed!"
                 ]) );
}
