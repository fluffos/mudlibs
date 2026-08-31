#include <std.h>
#include <forserver.h>
inherit VIRTUALROOM;
void create() { 
  
  object otherroom;
  set_server(SERVER);
  ::create();
    set_exits( ([
"south" : FOR "a51",
"northeast" : BLACK "black",
"southwest" : RED "a15",
"southeast" : BLUE "a23",
    ]) );
  set_no_clean(1);
  if(random(2) == 0)
    otherroom = load_object(WHITE "a");
  else
    otherroom = load_object(WHITE "a10");
  add_exit(base_name(otherroom), "northwest");
  otherroom->set_no_clean(1);
  otherroom->add_exit(base_name(this_object()), "southeast");
}
