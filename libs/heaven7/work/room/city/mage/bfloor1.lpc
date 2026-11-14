#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;

  set_short("the basement of the council of high magic");
  set_long(
     "A long spiral staircase of black iron extends downward  \n"+
     "into the darkness below. A dark silence fills the air   \n"+
     "here.\n");
  set_items(({
     "stairs#staircase",
          "A stairwell of cold black iron, descending downward",
     "walls#wall",
          "The walls are of a cold grey stone, possibly made by magical means",
     "stone",
          "No dwarf chiselled this stone",
  }));
  set_listen("You hear nothing...\n");
  set_smell("The air here is damp and stuffy.\n");
  set_exits(({
     "room/city/mage/gfloor1", "up",
     "room/city/mage/bfloor2", "down",
  }));
  set_weather(0,1,0);    
}
