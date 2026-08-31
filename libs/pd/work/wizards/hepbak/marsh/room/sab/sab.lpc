#include <std.h>
#include <sabserver.h>
inherit DESERT;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : SAB "sab2",
"south" : "/wizards/hepualahaole/marsh/room/marsh27",
    ]) );
}
void reset() {
 ::reset();
    if (!present("sign"))
     new( ITEMS "sign2" )->move(this_object());
    }
