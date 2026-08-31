#include <std.h>
#include <diran.h>

inherit ROOM;
void create() {
    ::create();
    set_properties( (["light" : 2, "night light" : 1, ]) );
    set_short( "the Mountain Dwarf city" );
    set_long("The parapets atop the giant gate surrounding Diran are fairly plain.  There are large stone fortifications to hide behind, and holes in the walls to shoot arrows through if Duergar attempt to invade the city.  The snow to the south seems to be mixed with white sand, although it is hard to tell for sure.");
set_exits(([
"west" : ROOMS"mountaindwarf/37",
"east" : ROOMS"mountaindwarf/39",

]));
    set_items( ([

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