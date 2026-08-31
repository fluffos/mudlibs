#include <std.h>
#include <sabserver.h>
inherit DESERT;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : SAB "sab52",
    ]) );
}
void reset() {
 ::reset();
   if (!present("camel")) {
      new(MOB"camel")->move(this_object());
 
    }
}
