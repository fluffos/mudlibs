#include <std.h>
#include <diran.h>

inherit ROOM;
void create() {
    ::create();
    set_properties( (["light" : 2, "night light" : 1, ]) );
    set_short( "the Mountain Dwarf city" );
    set_long("A road of carefully set stones leads out of the tundra, and is kept fairly clean of snow.  It seems to be heading toward a huge gate.  There is a small circular path surrounding a huge stone.  There is a drawing etched into the stone.");
set_exits(([
"west" : ROOMS"mountaindwarf/12",
"north" : ROOMS"mountaindwarf/8",
"south" : ROOMS"mountaindwarf/10",

]));
    set_items( ([
({"gate","wall"}):"The gate has been built very tall, as if to keep out unwelcome intruders.",
"road":"The road is made from various red bricks.",
"stone":"There is a large stone seemingly in the middle of this path, too large for anyone to move it.",
"drawing":"It appears to be a bushel of bananas."
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