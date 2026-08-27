inherit "std/room";
#include "path.h"

void setup() {
  set_light(100);
  set_short("Arena Entrance");
  set_long("This is the entrance to the dog fighting arena.  Here you can " + 
           "look at dogs fighting eachother and place a bet on them. You can " +
           "also buy yourself a dog, as a pet or helper. To "+
           "the north is the hall. "+
           "You can leave the arena through the door "+
           "to the south.  You can hear dogs bark. "+
           "This is where fortunes are made and "+
           "fortunes have been lost, betting on dog fights in the "+
           "arena.\n");

  add_exit("south", DAGG +"noplace", "door");
  add_exit("north", ROOM +"arenahall", "corridor");
 }
