#include <std.h>
#include <whiteserver.h>
inherit VIRTUALROOM;
void create() {
  object otherroom;
  set_server(SERVER);
  ::create();
    set_exits( ([
"east" : WHITE "h18",
    ]) );
  set_no_clean(1);
  if(random(2) == 0)
    otherroom = load_object(WHITE "i18");
  else
    otherroom = load_object(WHITE "i6");
  add_exit(base_name(otherroom), "west");
  otherroom->set_no_clean(1);
  otherroom->add_exit(base_name(this_object()), "east");
}
