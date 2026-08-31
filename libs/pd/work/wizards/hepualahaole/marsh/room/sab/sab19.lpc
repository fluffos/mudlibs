#include <std.h>
#include <sabserver.h>
inherit DESERT;


void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"northeast" : SAB "sab26",
"south" : SAB "sab14",
    ]) );
}
void reset() {
 ::reset();
  if (!present("camel"))
     new(MOB"camel")->move(this_object());
 
    }
}
