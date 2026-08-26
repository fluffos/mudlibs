// Petrarch
// Merentha Lib 1.0
// supply room

#include <std.h>
inherit ROOM;

void reset() {
::reset();
  if(!present("rock")) new("/domains/obj/other/rock")->move(this_object());
  while(!present("sword 3")) 
    new("/domains/obj/weapons/sword")->move(this_object());
  while(!present("vest 3")) 
    new("/domains/obj/armour/vest")->move(this_object());
  while(!present("cloak 3")) 
    new("/domains/obj/armour/cloak")->move(this_object());
}

