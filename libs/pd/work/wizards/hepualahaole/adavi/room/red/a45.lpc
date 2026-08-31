#include <std.h>
#include <redserver.h>
inherit VIRTUALROOM;
void create() {

  object otherroom;

  set_server(SERVER);
  ::create();
    set_exits( ([
"northwest" : RED "a47",
    ]) );

  set_no_clean(1);
  if(random(2) == 0)
    otherroom = load_object(RED "c66");
  else
    otherroom = load_object(RED "d21");
  add_exit(base_name(otherroom), "west");
  otherroom->set_no_clean(1);
  otherroom->add_exit(base_name(this_object()), "east");
}
