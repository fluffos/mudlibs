#include <moving.h>
#include "path.h"
inherit MAZE("base");


do_b(){
  object map;
  if (!this_player()) return 0;
  if (!map= present("mmap",this_player())) return 0;
  map= present("mmap",this_player());
  if(map->QueryA()){NoGo();return 1;}
  else{
    map->SetA();
    if (!this_player()) return 0;
    this_player()->move(MAZE("b"),M_GO,"southwest");
  return 1;
  }
 }

do_c(){
  object map;
  if (!this_player()) return 0;
  if (!map= present("mmap",this_player())) return 0;
  map= present("mmap",this_player());
  if(map->QueryB()){NoGo();return 1;}
  else{
    map->SetB();
    this_player()->move(MAZE("c"),M_GO,"southeast");
  return 1;
  }
 }

CheckStuck(){
object map;
  if (!this_player()) return 0;
  if (!map= present("mmap",this_player())) return 0;
  map= present("mmap",this_player());
  if(map->QueryA() && map->QueryB()){map->Stuck();}
  return 1;
 }

create(){
  ::create();
SetIntLong("This is room A.\n");
AddExit("southwest",#'do_b);
AddExit("southeast",#'do_c);
}

