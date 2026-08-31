#include <std.h>
inherit ROOM;

void create(){
 ::create();
  set_properties((["light":1,"night light":1]));
  set_short("wiz place");
  set_long("test");
  set_exits(([ "west":"/wizards/wiz/workroom"]));
}
void init(){
 ::init();
 if(!present("dragon"))new("/wizards/wiz/mob/dragon")->move(this_object());
}
