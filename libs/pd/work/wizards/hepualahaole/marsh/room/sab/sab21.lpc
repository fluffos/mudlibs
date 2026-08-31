#include <std.h>
#include <sabserver.h>
inherit DESERT;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"northwest" : SAB "sab28",
"southeast" : SAB "sab16",
    ]) );
}
void reset() {
 ::reset();
   if (!present("camel")) {
      new(MOB"camel")->move(this_object());
 
    }
}
