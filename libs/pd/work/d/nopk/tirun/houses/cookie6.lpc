#include <std.h>
#include <tirun.h>

inherit VAULT;

void create() {
  ::create();
  set_properties(([ "light" : 2,
                  "indoors" : 1
                 ]));
  set_short("West Guest Room");
  set_long("This room is a TOTAL WRECK! Pieces of food sit un-eaten on the desk, the bed is "
           "mussed, potion bottles lie all about the room, some full, some empty. Books "
           "after more spell books lay all over the place as if a tornado had blown through "
           "here TWICE.");
  set_smell("default","The smell of Imp hangs heavily in the room.");
  set_exits((["east" : ROOMS"houses/cookie5"]));
  set_door("west door", ROOMS"houses/cookie5", "east", "cookie_key");
}
