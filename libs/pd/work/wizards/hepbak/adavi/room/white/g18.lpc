#include <std.h>
#include <whiteserver.h>
inherit VIRTUALROOM;
void create() {
  object otherroom;
  set_server(SERVER);
  ::create();
    set_exits( ([
"south" : WHITE "g15",
    ]) );
  set_no_clean(1);
  if(random(2) == 0)
    otherroom = load_object(WHITE "h11");
  else
    otherroom = load_object(WHITE "h");
  add_exit(base_name(otherroom), "north");
  otherroom->set_no_clean(1);
  otherroom->add_exit(base_name(this_object()), "south");
}
