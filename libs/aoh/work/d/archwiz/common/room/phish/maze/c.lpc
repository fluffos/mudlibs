#include <moving.h>
#include "path.h"
inherit MAZE("base");


do_e(){
  object map;
  if (!this_player()) return 0;
  if (!map= present("mmap",this_player())) return 0;
  map= present("mmap",this_player());
  if(map->QueryG()){NoGo();return 1;}
  else{
    map->SetG();
    this_player()->move(MAZE("e"),M_GO,"south");
  return 1;
  }
 }

do_b(){
  object map;
  if (!this_player()) return 0;
  if (!map= present("mmap",this_player())) return 0;
  map= present("mmap",this_player());
  if(map->QueryC()){NoGo();return 1;}
  else{
    map->SetC();
    this_player()->move(MAZE("b"),M_GO,"west");
  return 1;
  }
 }

do_d(){
  object map;
  if (!this_player()) return 0;
  if (!map= present("mmap",this_player())) return 0;
  map= present("mmap",this_player());
  if(map->QueryF()){NoGo();return 1;}
  else{
    map->SetF();
    this_player()->move(MAZE("d"),M_GO,"southwest");
  return 1;
  }
 }

do_a(){
  object map;
  if (!this_player()) return 0;
  if (!map= present("mmap",this_player())) return 0;
  map= present("mmap",this_player());
  if(map->QueryB()){NoGo();return 1;}
  else{
    map->SetB();
    this_player()->move(MAZE("a"),M_GO,"northwest");
  return 1;
  }
 }

CheckStuck(){
object map;
  if (!this_player()) return 0;
  if (!map= present("mmap",this_player())) return 0;
  map= present("mmap",this_player());
  if(map->QueryB() && map->QueryC() && map->QueryG() && map->QueryF()){map->Stuck();}
  return 1;
 }

create(){
  ::create();
SetIntLong("This is room C.\n");
AddExit("south",#'do_e);
AddExit("west",#'do_b);
AddExit("southwest",#'do_d);
AddExit("northwest",#'do_a);
 }

