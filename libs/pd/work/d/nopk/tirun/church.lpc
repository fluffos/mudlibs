//Made using Room generator by Nightshade
//stormy
#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
    ::create();
    set_short("Tirun Church");
    set_properties( (["light" : 2, "night light" : 2, "indoors" : 1]) );
    set_long("Welcome to the Church of Tirun.\n"
             "The church was built long ago.  Pews line the main floor "
             "all the way to the alter.  Lanterns hang on the walls providing "
             "the light.  A stairway on the east wall leads up and down.  The "
             "entrance is to the north.");
    set_exits( (["down" : ROOMS+"fighter/paladin/paladin_join",
                        "up" : ROOMS+"clergy/cleric/cleric_old",
                        "out" : ROOMS+"seganthus1"
              ]) );
    set_items( ([ "pew" : "A bench seat used to sit and listen to the priests."
                 ,"lanterns" : "Brass lanterns, polished till they gleam."
                 ,"stairway" : "Elegant oak stairs going up and down"
                 ,"alter" : "A plished wooden alter."
                 ]) );
}
