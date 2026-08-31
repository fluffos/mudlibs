// This is what the code for a room looks like.  point set_server() to where your server file is (will want to use a header pointer here) make sure set_server() is before the ::create();  after the ::create(), you can override other settings like you were making a normal room.

#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/nightshade/vexamples/server");
  ::create();
  set_exits( ([ "out" : "/wizards/nightshade/workroom" ]) );
}
