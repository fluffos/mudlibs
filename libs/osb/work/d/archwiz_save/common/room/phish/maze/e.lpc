#include "path.h"
#include <moving.h>
inherit MAZE("base");

do_c(){
  object map;
  if (!this_player()) return 0;
  if (!map= present("mmap",this_player())) return 0;
  map= present("mmap",this_player());
  if(map->QueryG()){NoGo();return 1;}
  else{
    map->SetG();
    this_player()->move(MAZE("c"),M_GO,"north");
  return 1;
  }
 }

do_d(){
  object map;
  if (!this_player()) return 0;
  if (!map= present("mmap",this_player())) return 0;
  map= present("mmap",this_player());
  if(map->QueryH()){NoGo();return 1;}
  else{
    map->SetH();
    this_player()->move(MAZE("d"),M_GO,"west");
  return 1;
  }
 }

do_b(){
  object map;
  if (!this_player()) return 0;
  if (!map= present("mmap",this_player())) return 0;
  map= present("mmap",this_player());
  if(map->QueryE()){NoGo();return 1;}
  else{
    map->SetE();
    this_player()->move(MAZE("b"),M_GO,"northwest");
  return 1;
  }
 }

CheckStuck(){
object map;
  if (!this_player()) return 0;
  if (!map= present("mmap",this_player())) return 0;
  map= present("mmap",this_player());
  if(map->QueryE() && map->QueryH() && map->QueryG()){map->Stuck();}
  return 1;
 }

create(){
  ::create();
SetIntLong("This is room E.\n");
AddExit("north",#'do_c);
AddExit("west",#'do_d);
AddExit("northwest",#'do_b);
 }

