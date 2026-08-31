#include <storm.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("A small, dirt pathway leading up to a mountain");
   set_properties((["light" : 2, "night light" : 1]));
   set_long("The path makes a slight turn here, leading further into "
            "depths of Mount Storm. Dirt blows up into the air, and "
            "into the sky. Several trees line the path.");
//   set_listen("default", "Some bird's cry can be heard in the distance.");
   set_exits(([ "southwest" : ROOMS "path4",
                "east" : ROOMS "path6" ]));
   set_items(([ "mountain" : "Mount Storm reaches up, past the clouds.",
                "trees" : "Most of them are pine trees.",
                "dirt" : "It blows up into your face."
            ]));
}

void reset() {
 ::reset();
   if (!present("lizardman"))
      new(MOB"lizardman")->move(this_object());
}
