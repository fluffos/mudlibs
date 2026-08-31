#include <std.h>
#include <sabserver.h>
inherit DESERT;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"west" : SAB "sab4",
"north" : SAB "sab10",
    ]) );
}
void reset() {
 ::reset();
   if (!present("camel")) {
      new(MOB"camel")->move(this_object());
 
    }
}
