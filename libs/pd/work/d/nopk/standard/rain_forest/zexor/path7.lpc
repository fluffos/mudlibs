#include <std.h>
#include <zexor.h>
inherit ROOM;

void create() {
   ::create();
   set_short("A silent forest");
   set_day_long("Trees surround this area with day-light filter"
       "ing through their leaves. There are birds chirping and the"
       "re is peace covering the forest.");
   set_listen("default", "There are peaceful sounds all around you");
   set_night_long("You are surrounded by trees with moon-light fil"
       "tering through their leaves. Their are grass-hoppers chirp"
       "ing, there is a silent peace covering the forest.");
   set_items((["trees" : "They are calm trees just swaying in the "
      "wind.",
               "leaves": "They are nice brown leaves."]));
   set_exits((["north" : ROOMS"path1",
               "south" : ROOMS"path8"]));
}

void reset() {
   ::reset();
   if(!present("elemental"))
     new(MOB"fake")->move(this_object());
}
