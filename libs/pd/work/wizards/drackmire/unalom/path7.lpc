#include <std.h>
#include "unalom.h"

inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set_property("light", 0);
    set_short("a dense forest");
    set_long("The path continues north and south here through the dense forest. "
    "Trees here grow gnarled and twisted with a certain evil in their "
    "appearance, almost completely blocking out the sun with their "
    "branches.  The brush here is thick and makes moving off the path "
    "difficult, but possible in this part of the woods.  "
      );
    set_listen("default", "All that can be heard is the wind through the trees.");
    set_smell("default", "The air smells of damp wood.");
    set_exits( ([ "north" : UNAROOM"path8",
                  "southeast" : UNAROOM"path6",
                  "east": UNAROOM "eforest1",
                  "west" : UNAROOM "wforest1"]) );
    set_items(
        ([ ({ "tree", "trees" }) : "The trees here grow thick and tall, obscuring the sun." ] 
) );

}

void reset(){
  ::reset();
  if(!present("snake"))
    new(UNAMON"snake")->move(this_object());
    }
