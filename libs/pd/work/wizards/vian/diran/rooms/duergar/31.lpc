#include <std.h>
#include <diran.h>

inherit ROOM;
void create() {
    ::create();
    set_properties( ([ "indoors" : 1, "light" : 2, "night light" : 1, ]) );
    set_short( "the Duergar city" );
    set_long("The housing compounds of the Duergar city are quite ratty and tattered.  There are dirty cots scattered throughout the large room, taking up most of the floorspace.  A large wooden table sits in a corner.  These houses are shared by all of the citizens of Duergar.  They are all arranged the same, as to be fair and equal to each citizen.  Weapons line the walls, incase of an attack.");
set_exits(([
"out" : ROOMS"duergar/28",

]));
    set_items( ([
"cots":"The cots are more of bundled straw, they do not look very comfortable.",
"table":"The table is rickety and scratched up, but it still stands fine.",
"weapons":"There are swords and axes mounted to the wall, ready to be taken incase of an attack.",
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
        if(!present("dchild"))
          new(MOB "dchild")->move(this_object());
}
     if( random(100) < DIRAN_MOB_CHANCE){
        if(!present("dman"))
          new(MOB "dman")->move(this_object());
}
     if( random(100) < DIRAN_MOB_CHANCE){
        if(!present("dwoman"))
          new(MOB "dwoman")->move(this_object());
}
     if( random(100) < DIRAN_MOB_CHANCE){
        if(!present("dranger"))
          new(MOB "dranger")->move(this_object());
}
     if( random(100) < DIRAN_MOB_CHANCE){
        if(!present("dwizard"))
          new(MOB "dwizard")->move(this_object());
}
     if( random(100) < DIRAN_MOB_CHANCE){
        if(!present("dwarrior"))
          new(MOB "dwarrior")->move(this_object());
}

}
}