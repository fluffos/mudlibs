#include <std.h>
#include <whiteserver.h>
inherit VIRTUALROOM;
void create() {
  object otherroom;
  set_server(SERVER);
  ::create();
    set_exits( ([
"southeast" : WHITE "i14",
    ]) );
  set_no_clean(1);
  if(random(2) == 0)
    otherroom = load_object(WHITE "j15");
  else
    otherroom = load_object(WHITE "j9");
  add_exit(base_name(otherroom), "southwest");
  otherroom->set_no_clean(1);
  otherroom->add_exit(base_name(this_object()), "northeast");
}
