#include <std.h>
#include <diran.h>

inherit ROOM;
void create() {
    ::create();
    set_properties( (["light" : 2, "night light" : 1, ]) );
    set_short( "the Mountain Dwarf city" );
    set_long("The huge gate surrounding Diran is fairly plain.  It is a giant wall made out of coarse stones, kept together with some sort of muddy cement.  There are holes cut out in the wall for archers to shoot from incase of a Duergar attack.  A loud commotion can be heard coming from the church to the east.");
set_exits(([
"north" : ROOMS"mountaindwarf/61",
"south" : ROOMS"mountaindwarf/63",

]));
    set_items( ([
({"gate"}):"The gate has been built very tall, as if to keep out unwelcome intruders.",
"stones":"The stones are grey and fairly crumbly.",
"cement":"The cement keeping the stones together seems to be brownish, and is probably mud-based.",
"holes":"There are holes in the wall to shoot from.",
"church":"It is to the east, but the way seems impassible.",
]) );
    set_smell("default",  "The dry arctic wind carries little scent, although smoke can be vaguely smelled.");
    set_listen("default", "The sound of working humanoids can be heard.");

if(random(100) < DIRAN_ROOM_CHANCE){
        if(!present("mdarcher"))
          new(MOB "mdarcher")->move(this_object());
        if(!present("mdguard"))
          new(MOB "mdguard")->move(this_object());
          new(MOB "mdguard")->move(this_object());
}
}