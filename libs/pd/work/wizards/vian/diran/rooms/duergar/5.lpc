#include <std.h>
#include <diran.h>

inherit ROOM;
void create() {
    ::create();
    set_properties( ([ "indoors" : 1, "light" : 2, "night light" : 1, ]) );
    set_short( "the Duergar city" );
    set_long("The gate surrounding the Duergar City is a heavily fortified wall of black stones.  It continues up much higher than would be climbable.  Light is barely visible up on top of the gate.  There is a very narrow pathway around the gate.  There is rubble on the ground from where stones have been replaced.");
set_exits(([ "west" : ROOMS"duergar/6",
"north" : ROOMS"duergar/4",
]));
    set_items( ([
({"gate","wall"}):"The gate has been built very tall, as if to keep out unwelcome intruders.",
"light":"Light is very barely visible at the top of the gate.",
"stones":"The black stones seem to be made of pure onyx.",
]) );
    set_smell("default",  "The smell of smoke is a bit overpowering.");
    set_listen("default", "There is quite a lot of noise echoing from the inside of the cave.");
if(random(100) < DIRAN_ROOM_CHANCE){
        if(!present("dranger"))
          new(MOB "dranger")->move(this_object());
          new(MOB "dranger")->move(this_object());
        if(!present("dguard"))
          new(MOB "dguard")->move(this_object());

}
}