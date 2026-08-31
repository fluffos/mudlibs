#include <std.h>
#include <diran.h>

inherit ROOM;
void create() {
    ::create();
    set_properties( (["light" : 2, "night light" : 1, ]) );
    set_short( "the Mountain Dwarf city" );
    set_long("A huge gate surrounds the Mountain Dwarf city of Diran.  It can be seen towering in all directions.  The city lays directly to the west, and a ladder leads up to the top of the gate.");
set_exits(([
"east" : ROOMS"mountaindwarf/12",
"west" : ROOMS"mountaindwarf/76",
"north" : ROOMS"mountaindwarf/49",
"south" : ROOMS"mountaindwarf/75",
"up" : ROOMS"mountaindwarf/14",

]));
    set_items( ([
({"gate","wall"}):"The gate has been built very tall, as if to keep out unwelcome intruders.",
"ladder":"The ladder seems to head to the parapets above.",
]) );
    set_smell("default",  "The dry arctic wind carries little scent, although smoke can be vaguely smelled.");
    set_listen("default", "The sound of working humanoids can be heard.");

if(random(100) < DIRAN_ROOM_CHANCE){
        if(!present("mdscout"))
          new(MOB "mdscout")->move(this_object());
        if(!present("mdguard"))
          new(MOB "mdguard")->move(this_object());
          new(MOB "mdguard")->move(this_object());
}
}