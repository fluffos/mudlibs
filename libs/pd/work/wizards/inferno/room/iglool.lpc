//By Leviathas
// , file=.c    

#include <std.h>
inherit ROOM;

void create() {
::create();
    set_short("In an Icy Palace.");
    set_long("%^BOLD%^%^CYAN%^This room of the Igloo is amazing. "
                "The %^WHITE%^ice%^CYAN%^ is "
                "carved into beautiful patterns on "
                "the walls. It appears that there " 
                "is a fresh block of ice placed at the "
                "wall.");
    
    set_items(([
        "patterns" : "%^BOLD%^%^CYAN%^They shimmer as you look at them. ",
        "wall" : "%^RESET%^%^BLUE%^The wall is made out of some fresh  "
                   "ice... looks like an illusion...",
        
    ]));
    set_properties(([
        "light" : 1,
        "night light" : 1,
    ]));
    set_exits(([
        "west" : "/wizards/inferno/room/iglooroom",
         ]));
    set_invis_exits(({ "east" }));
}
