#include "path.h"
#include <moving.h>
inherit MAZE("base");


do_b(){
  object map;
  if (!this_player()) return 0;
  if (!map= present("mmap",this_player())) return 0;
  map= present("mmap",this_player());
  if(map->QueryD()){NoGo();return 1;}
  else{
    map->SetD();
    this_player()->move(MAZE("b"),M_GO,"north");
  return 1;
  }
 }

do_e(){
  object map;
  if (!this_player()) return 0;
  if (!map= present("mmap",this_player())) return 0;
  map= present("mmap",this_player());
  if(map->QueryH()){NoGo();return 1;}
  else{
    map->SetH();
    this_player()->move(MAZE("e"),M_GO,"east");
  return 1;
  }
 }

do_c(){
  object map;
  if (!this_player()) return 0;
  if (!map= present("mmap",this_player())) return 0;
  map= present("mmap",this_player());
  if(map->QueryF()){NoGo();return 1;}
  else{
    map->SetF();
    this_player()->move(MAZE("c"),M_GO,"northeast");
  return 1;
  }
 }

CheckStuck(){
object map;
  if (!this_player()) return 0;
  if (!map= present("mmap",this_player())) return 0;
  map= present("mmap",this_player());
  if(map->QueryF() && map->QueryH() && map->QueryD()){map->Stuck();}
  return 1;
 }

create(){
  ::create();
SetIntLong("This is room D.\n");
AddExit("north",#'do_b);
AddExit("east",#'do_e);
AddExit("northeast",#'do_c);
 }
