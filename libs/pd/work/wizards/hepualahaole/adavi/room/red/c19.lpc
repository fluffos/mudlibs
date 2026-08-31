#include <std.h>
#include <redserver.h>
inherit VIRTUALROOM;
void create() {

  object otherroom;

  set_server(SERVER);
  ::create();
    set_exits( ([
"south" : RED "c13",
    ]) );

  set_no_clean(1);
  if(random(2) == 0)
    otherroom = load_object(RED "c32");
  else
    otherroom = load_object(RED "c44");
  add_exit(base_name(otherroom), "north");
  otherroom->set_no_clean(1);
  otherroom->add_exit(base_name(this_object()), "south");
}
