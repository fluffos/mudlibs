#include <std.h>
#include <arlon2.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 2, "town" : 1, "night light" : 2]) );
set_smell("default", "The smell of healing ointment and mana stones is very potent.");
set_listen("default", "The sound of bubbling cauldrons can be heard.");
set_short("Arlon healery");
set_long("The healery is a small shop, with many herbs and oils on tables with cauldrons, bubbling to create healing oil and magic stones.  There is a large counter, which the stonemaker and oilbrewer stand behind.  There is a sign that can be read with instructions and prices.");
    set_exits( ([
       "out" : ROOMS "21",
    ]) );
set_items(([
({"herbs", "oils"}) : "Herbs and oils seem to be the main ingredients in the things sold here.",
({"counter", "large counter"}) : "There is a large counter make of a thick dark wood.",
]));
}
void reset() {
    ::reset();
    if(!present("zatrick")){
        new(MOB"zatrick")->move(this_object());
}
    if(!present("pelgadiss")){
        new(MOB"pelgadiss")->move(this_object());
}
}

