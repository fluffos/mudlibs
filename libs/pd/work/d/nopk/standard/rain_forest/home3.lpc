#include <std.h>
#include <rain.h>

inherit ROOM;
void create() {
   ::create();
   set_short("Third house on the block");
   set_long("You are at a small elven house. This house "
            "is right at the corner of this block. You a"
            "re directly west of the town square. there "
            "are a few more houses on the block.");
   set_exits(([
               "south" : ROOMS"home6",
               "east" : ROOMS"home1",
               "west" : ROOMS"square",
               "enter" : ROOMS"house3"]));
}

void reset() {
   ::reset();
   if(!present("gardener"))
   new(MOB"gardener")->move(this_object());
}
