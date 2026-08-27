inherit "std/room";
#include "path.h"

void setup() {
  set_light(100);
  set_short("Arena Hallway");
  set_long("This is a hallway within the dog fighting arena.  To "+
           "the west you can see the arena where people gather to "+
           "watch animals engage in battle.  To the southwest you "+
           "see an area in which you can buy an animal to enter "+
           "into the arena fights.  To the northwest the hallway "+
           "continues.  There is a painting on the wall here.\n");

  add_item("painting", "This painting is of a scarred attack dog "+
                       "standing majestically atop the corpses of its "+
                       "two foes.  This dog beat both of them in a "+
                       "three dog free-for-all to gain the trophy for "+
                       "winning the attack dog tournaments last year.\n");

  add_exit("west", ROOM +"arena", "corridor");
  add_exit("southwest", ROOM +"sellroom", "corridor");
  add_exit("northwest", ROOM +"arenahall", "corridor");

 }
