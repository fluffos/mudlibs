#include <std.h>
#include <diran.h>

inherit ROOM;
void create() {
    ::create();
    set_properties( ([ "indoors" : 1, "light" : 2, "night light" : 1, ]) );
    set_short( "the Duergar city" );
    set_long("The Warrior training hall of Duergar is a large and messy room, filled with weapons and armour racks, training dummies, and various books on combat methods.  There is a large open space as well, for practicing swordwork.  Many warriors study here in the day.");
set_exits(([
"out" : ROOMS"duergar/69",

]));
    set_items( ([

]) );
    set_smell("default",  "The smell of smoke is a bit overpowering.");
    set_listen("default", "There is quite a lot of noise echoing from the inside of the cave.");
if(random(100) < DIRAN_ROOM_CHANCE){
        if(!present("dwarrior"))
          new(MOB "dwarrior")->move(this_object());
          new(MOB "dwarrior")->move(this_object());
          new(MOB "dwarrior")->move(this_object());
          new(MOB "dwarrior")->move(this_object());
}
}