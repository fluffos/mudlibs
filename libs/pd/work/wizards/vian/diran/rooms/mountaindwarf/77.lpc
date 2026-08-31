#include <std.h>
#include <diran.h>

inherit ROOM;
void create() {
    ::create();
    set_properties( (["light" : 2, "night light" : 1, ]) );
    set_short( "the Mountain Dwarf city" );
    set_long("A road of carefully set stones continues through the Mountain Dwarf city of Diran.  Citizens crowd the streets, it seems as if they may do most of their living outdoors.  The city continues to the west, while the tundra remains back to the east.  Weeds grow through cracks in the stones.");
set_exits(([
"east" : ROOMS"mountaindwarf/76",
"west" : ROOMS"mountaindwarf/78",

]));
    set_items( ([
({"road"}):"The road is composed of carefully set stones, mistakes very uncommon.",
"stones":"The stones are different shades of red and brown.",
]) );
    set_smell("default",  "The dry arctic wind carries little scent, although smoke can be vaguely smelled.");
    set_listen("default", "The sound of working humanoids can be heard.");

if(random(100) < DIRAN_ROOM_CHANCE){
     if( random(100) < DIRAN_MOB_CHANCE){
        if(!present("mdwoman"))
          new(MOB "mdwoman")->move(this_object());
}
     if( random(100) < DIRAN_MOB_CHANCE){
        if(!present("mdwarrior"))
          new(MOB "mdwarrior")->move(this_object());
}
     if( random(100) < DIRAN_MOB_CHANCE){
        if(!present("mdman"))
          new(MOB "mdman")->move(this_object());
}
     if( random(100) < DIRAN_MOB_CHANCE){
        if(!present("mdchild"))
          new(MOB "mdchild")->move(this_object());
}
     if( random(100) < DIRAN_MOB_CHANCE){
        if(!present("mdmagi"))
          new(MOB "mdmagi")->move(this_object());
}
     if( random(100) < DIRAN_MOB_CHANCE){
        if(!present("mdelderm"))
          new(MOB "mdelderm")->move(this_object());
}
     if( random(100) < DIRAN_MOB_CHANCE){
        if(!present("mdelderf"))
          new(MOB "mdelderf")->move(this_object());
}
}
}
