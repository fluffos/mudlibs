#include <std.h>
#include <diran.h>

inherit ROOM;
void create() {
    ::create();
    set_properties( (["light" : 2, "night light" : 1, ]) );
    set_short( "the Mountain Dwarf city" );
    set_long("The parapets atop the giant gate surrounding Diran are fairly plain.  There are large stone fortifications to hide behind, and holes in the walls to shoot arrows through if Duergar attempt to invade the city.  There is broken glass scattered on this stretch of parapet.");
set_exits(([
"east" : ROOMS"mountaindwarf/21",
"west" : ROOMS"mountaindwarf/23",

]));
    set_items( ([
({"gate"}):"The gate has been built very tall, as if to keep out unwelcome intruders.",
"parapet":"The perfect spot for shooting intruders with a bow and arrow.",
"fortifications":"The wall is checkered with fortifications that you can hide behind.",
"holes":"There are holes in the wall to shoot from.",
]) );
    set_smell("default",  "The dry arctic wind carries little scent, although smoke can be vaguely smelled.");
    set_listen("default", "The sound of working humanoids can be heard.");

if(random(100) < DIRAN_ROOM_CHANCE){
        if(!present("mdarcher"))
          new(MOB "mdarcher")->move(this_object());
          new(MOB "mdarcher")->move(this_object());
          new(MOB "mdarcher")->move(this_object());
}
}