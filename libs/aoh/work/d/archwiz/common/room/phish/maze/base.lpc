inherit "/std/room";
#include "path.h"
#include <moving.h>

init(){
  object map;
  ::init();
  if (!this_player()) return 0;
  map = present("mmap",this_player());
  if(!map){map = clone_object(MAZE("map"));
  map->move(this_player());}
  if(map->CheckVictory() == 0){call_out("CheckStuck",1);}
 }

NoGo(){
  write("You can't go that way!  You've already taken that path!\n");
  return 1;
 }

GoOut(){
  object map;
  if (!this_player()) return 0;
  map = present("mmap",this_player());
  if (!map) return 0;
  map -> maze_reset();
  write("You think about what a difficult maze this is and leave...\n");
  this_player()->move(PHISH("maze_entrance"),M_GO,"out");
  return 1;
 }

CheckStuck(){return 0;}

create(){
  ::create();
  SetIntShort("You are in a maze in Phish's Castle.");
  AddExit("OUT",#'GoOut);
}

