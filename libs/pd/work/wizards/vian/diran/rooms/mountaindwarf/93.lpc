#include <std.h>
#include <diran.h>

inherit ROOM;
void create() {
    ::create();
    set_properties( (["light" : 2, "night light" : 1, ]) );
    set_short( "the Mountain Dwarf city" );
    set_long("The road ends abruptly here at a large firepit, billowing smoke into the air.  There are many logs surrounding the firepit, and blankets strewn around the ground.  This appears to be a sleeping area for the Diran Mountain Dwarves.  The only exit is the same as the entrance.  There is a large pile of wood and kindling sit aside the fire.");
set_exits(([
"east" : ROOMS"mountaindwarf/92",

]));
    set_items( ([
({"road"}):"The road is composed of carefully set stones, mistakes very uncommon.",
"firepit":"The firepit is quite large, and roaring at least 4 feet in the air.",
"logs":"Large logs surround the firepit to lay or sit on.",
"blankets":"Blankets of assorted colors and sizes are strewn around, ready to be slept in.",
"smoke":"The smoke is quite thick from the gigantic fire.",
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
