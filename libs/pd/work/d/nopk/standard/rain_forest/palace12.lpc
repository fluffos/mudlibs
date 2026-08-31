//Made using Room generator by Nightshade
//Temporary throne room

#include <std.h>
#include <rain.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Throne Room");
    set_properties( (["light" : 3, "night light" : 2, "indoors" : 1]) );
    set_smell("default", "The scent of incense fills the room.");
    set_long("This is the throne room of King Treerise, the king of this elven village.  The room is simple, yet well furnished.  A few guards line the walls as the King attends to other matters in his private chambers.");
    set_exits( (["north" : ROOMS+"palace11"
              ]) );
    set_items( ([ "throne" : "The throne is currently empty, as the king is out attending to other matters."
                 ,"walls" : "The walls have a few pictures on them."
                 ,"pictures" : "There are various pictures of the gods worshipped by the elves.  There is one of Seeker, Stormbringer, Inferno and Nightshade."
                 ]) );
}

void reset() {
    ::reset();
    if(!present("guard",this_object()))
        new(MOB+"guard3")->move(this_object());
    if(!present("guard 2",this_object()))
        new(MOB+"guard3")->move(this_object());
    if(!present("guard 3",this_object()))
        new(MOB+"guard3")->move(this_object());
    if(!present("guard 4",this_object()))
        new(MOB+"guard3")->move(this_object());
}
