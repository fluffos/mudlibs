#include <std.h>
#include <zexor.h>
inherit ROOM;

void create() {
   ::create();
   set_short("Forest");
   set_day_long("Near the edge of the forest. The for"
       "est starts thinning out as it leads towards Arlon"
       " plains. The sun makes the plains off to the sout"
       "h look golden.");
   set_night_long("You are near the edge of the forest. T"
       "he forest starts thinning out as it leads towards"
       " arlon plains. The moon makes the plains to the s"
       "outh look almost mystic.");
   set_items((["plains" : "The plains looks very calm and"
       " relaxing.",
               "forest" : "The forest is at an end."]));
   set_exits((["south" : "/d/arlon/room/den1" ]));
}

void init() {
   ::init();
   write("You travel for a while and arrive shortly north of arlon");
}
