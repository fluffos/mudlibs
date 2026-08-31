#include <std.h>
#include <diran.h>

inherit ROOM;
void create() {
    ::create();
    set_properties( (["light" : 2, "night light" : 1, ]) );
    set_short( "the Mountain Dwarf city" );
    set_long("A road of carefully set stones leads out of the tundra. It is kept fairly clean of snow.  It seems to be heading toward a huge gate.");
set_exits(([
"south" : ROOMS"tundra/73",
"west" : ROOMS"mountaindwarf/2",

]));
    set_items( ([
({"gate","wall"}):"The gate has been built very tall, as if to keep out unwelcome intruders.",
"road":"The road is made from various red bricks.",
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