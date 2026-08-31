#include <std.h>
#include <sabserver.h>
inherit DESERT;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"west" : SAB "sab28",
"east" : SAB "sab30",
"north" : SAB "sab37",
    ]) );
}
void reset() {
 ::reset();
   if (!present("camel")) {
      new(MOB"camel")->move(this_object());
    }
}
