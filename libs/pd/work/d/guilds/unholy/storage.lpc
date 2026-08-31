#include <std.h>
#include <guild.h>
inherit ROOM;

void reset() {
    ::reset();
    /* insert objects here they want */
}

void create() {
 ::create();
   set_short("storage room");
   set_long("This is the storage room. Get the hell out of here.");
   set_exits(([ "out" : ROOMS"unholy/shop", ]));
}
