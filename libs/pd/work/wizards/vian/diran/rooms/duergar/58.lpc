#include <std.h>
#include <diran.h>

inherit ROOM;
void create() {
    ::create();
    set_properties( (["light" : 2, "night light" : 1, "no attack":1,"indoors":1,  "thiefendroom" : 1, ]) );
    set_short( "the Duergar city" );
    set_long("The housing compounds of the Duergar city are quite ratty and tattered.  There are dirty cots scattered throughout the large room, taking up most of the floorspace.  A large wooden table sits in a corner.  These houses are shared by all of the citizens of Duergar.  They are all arranged the same, as to be fair and equal to each citizen.");
set_exits(([
"out" : ROOMS"duergar/59",

]));
    set_items( ([
"cots":"The cots are more of bundled straw, they do not look very comfortable.",
"table":"The table is rickety and scratched up, but it still stands fine.",
]) );
    set_smell("default",  "The smell of smoke is a bit overpowering.");
    set_listen("default", "There is quite a lot of noise echoing from the inside of the cave.");
    
        if(!present("masterscout"))
          new(MOB "masterscout")->move(this_object());

}

