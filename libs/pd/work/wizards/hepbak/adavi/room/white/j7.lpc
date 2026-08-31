#include <std.h>
#include <whiteserver.h>
inherit VIRTUALROOM;
void create() {
  object otherroom;
  set_server(SERVER);
  ::create();
    set_exits( ([
"southeast" : WHITE "j5",
    ]) );
  set_no_clean(1);
    otherroom = load_object(WHITE "k3");
  if(random(2) == 0)
  else
    otherroom = load_object(WHITE "k18");
  add_exit(base_name(otherroom), "southwest");
  otherroom->set_no_clean(1);
  otherroom->add_exit(base_name(this_object()), "northeast");
}
