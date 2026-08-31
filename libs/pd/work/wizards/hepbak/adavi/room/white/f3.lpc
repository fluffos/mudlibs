#include <std.h>
#include <whiteserver.h>
inherit VIRTUALROOM;
void create() {
  object otherroom;
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : WHITE "f6",
    ]) );
  set_no_clean(1);
  if(random(2) == 0)
    otherroom = load_object(WHITE "g");
  else
    otherroom = load_object(WHITE "g16");
  add_exit(base_name(otherroom), "east");
  otherroom->set_no_clean(1);
  otherroom->add_exit(base_name(this_object()), "west");
}
