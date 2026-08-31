#include <storm.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("A small, dirt pathway leading up to a mountain");
   set_properties((["light" : 2, "night light" : 1]));
   set_long("Mount Storm towers hundreds of feet tall, high above "
            "the clouds. The mountain looms to the northeast of here. "
            "A strange shadow penetrates the clouds, and splashes down "
            "upon the path.");
   set_listen("default", "A hawk's cry can be heard, piercing the silence.");
   set_exits(([ "south" : ROOMS "path2",
                "northeast" : ROOMS "path4" ]));
   set_items(([ "mountain" : "Mount Storm reaches up, past the clouds.",
                "path" : "A small, winding, dirt path.",
                "clouds" : "A bird-shaped shadow falls past the clouds.",
                "shadow" : "It looks like a very large bird's shadow.",
                "trees" : "They are scattered along near the path."
            ]));
}

void reset() {
 ::reset();
   if (!present("sign"))
      new(OBJ"sign1")->move(this_object());
}
