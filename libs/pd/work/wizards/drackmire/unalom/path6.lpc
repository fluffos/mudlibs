#include <std.h>
#include "unalom.h"

inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set_property("light", 0);
    set_short("a forest");
    set_long("The forest path continues through the dense woods here. "
    "To the south, a small clearing can be seen through the trees, while "
    "to the north, the forest only gets darker and denser.  The thick "
    "brush makes it impossible to move off the path."  
      );
    set_listen("default", "All that can be heard is the wind through the trees.");
    set_smell("default", "The air smells of damp wood.");
    set_exits( ([ "northwest" : UNAROOM"path7",
                  "south" : UNAROOM"path5"]) );
    set_items(
        ([ ({ "tree", "trees" }) : "The trees here grow thick and tall, obscuring vision" ] 
) );

}

void reset(){
  ::reset();
  if(!present("squirrel"))
    new(UNAMON"fsquirrel")->move(this_object());
    }
