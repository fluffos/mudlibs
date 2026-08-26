// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;
inherit DOORS ;

object chest ;

void create() {
  seteuid(getuid());
  set("short", "The King's Bedroom.");
  set("long", @ENDLONG
You stand in the bedroom of the King of Tormeid.
A very large tapestry covers the east wall.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "north" : ROOMS(rliving4),
  ]) );
  create_door("north", "south", "An ornate gold door.", "locked",
    "king_key", 24 ) ;
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
   MON(liw) : random(2) ,
  ]) );
  ::create() ;
  reset() ;
}

void reset() {
  if (!chest) {
  chest=clone_object(OBJ(chest) ) ;
  chest->move(TO) ;
  }
  if (chest) {
  if (!random(5)) 
   clone_object(WEP(firespear))->move(chest) ;
  else if (!random(5)) 
   clone_object(OBJ(painting))->move(chest) ;
  else if (!random(5))
   clone_object(ARM(helm_of_intellect))->move(chest);
  else
  clone_object(ARM(regen_ring))->move(chest) ;
   }
  ::reset() ;
}

void init() {
  add_action("search", "search") ;
}

int search(string str) {
  if (!str || str != "tapestry") return 0 ;
  write("You find a secret passageway hidden behind the tapestry.\n");
  if (!TP->query("invisible")) 
     say(TPN+" disappears behind the tapestry on the east wall.\n");
  TP->move_player(ROOMS(secret2), "SNEAK") ;
  if (!TP->query("invisible")) 
    say(TPN+" enters through the secret door to the west.\n");
  return 1;
}
