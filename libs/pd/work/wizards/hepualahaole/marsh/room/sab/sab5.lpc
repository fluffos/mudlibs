#include <std.h>
#include <sabserver.h>
inherit DESERT;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"west" : SAB "sab4",
"north" : SAB "sab10",
"northeast" : GRASS "g24",
"east" : GRASS "g16",
"south" : GRASS "g10",
"southwest" : GRASS "g9",
    ]) );
}
void reset() {
 ::reset();
   if (!present("camel")) {
      new(MOB"camel")->move(this_object());
 
    }
}
