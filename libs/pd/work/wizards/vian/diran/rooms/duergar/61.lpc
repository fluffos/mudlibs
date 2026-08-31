#include <std.h>
#include <diran.h>

inherit ROOM;
void create() {
    ::create();
    set_properties( ([ "indoors" : 1, "light" : 2, "night light" : 1, ]) );
    set_short( "the Duergar city" );
    set_long("The road leading through the Duergar city is dark and uninviting.  Flashes of light from burning torches can be seen in the distance, but the road is usually traveled on memory or with a carried lightsource.  Weeds can be seen sprouting through cracks in the road.");
set_exits(([
"south" : ROOMS"duergar/62",
"west" : ROOMS"duergar/60",

]));
    set_items( ([
"torches":"Light can be seen from torches burning in the distance.",
"road":"The road is made from flat black stones.",
]) );
    set_smell("default",  "The smell of smoke is a bit overpowering.");
    set_listen("default", "There is quite a lot of noise echoing from the inside of the cave.");
if(random(100) < DIRAN_ROOM_CHANCE){
     if( random(100) < DIRAN_MOB_CHANCE){
        if(!present("dpsion"))
          new(MOB "dpsion")->move(this_object());
}
     if( random(100) < DIRAN_MOB_CHANCE){
        if(!present("dshaman"))
          new(MOB "dshaman")->move(this_object());
}
     if( random(100) < DIRAN_MOB_CHANCE){
        if(!present("dwarrior"))
          new(MOB "dwarrior")->move(this_object());
}
     if( random(100) < DIRAN_MOB_CHANCE){
        if(!present("dwizard"))
          new(MOB "dwizard")->move(this_object());
}

}
}