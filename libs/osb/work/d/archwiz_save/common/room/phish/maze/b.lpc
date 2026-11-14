#include "path.h"
#include <moving.h>
inherit MAZE("base");

do_d(){
  object map;
  if (!this_player()) return 0;
  if (!map= present("mmap",this_player())) return 0;
  map= present("mmap",this_player());
  if(map->QueryD()){NoGo();return 1;}
  else{
    map->SetD();
    this_player()->move(MAZE("d"),M_GO,"south");
  return 1;
  }
 }

do_c(){
  object map;
  if (!this_player()) return 0;
  if (!map= present("mmap",this_player())) return 0;
  map= present("mmap",this_player());
  if(map->QueryC()){NoGo();return 1;}
  else{
    map->SetC();
    this_player()->move(MAZE("c"),M_GO,"east");
  return 1;
  }
 }

do_e(){
  object map;
  if (!this_player()) return 0;
  if (!map= present("mmap",this_player())) return 0;
  map= present("mmap",this_player());
  if(map->QueryE()){NoGo();return 1;}
  else{
    map->SetE();
    this_player()->move(MAZE("e"),M_GO,"southeast");
  return 1;
  }
 }

do_a(){
  object map;
  if (!this_player()) return 0;
  if (!map= present("mmap",this_player())) return 0;
  map= present("mmap",this_player());
  if(map->QueryA()){NoGo();return 1;}
  else{
    map->SetA();
    this_player()->move(MAZE("a"),M_GO,"northeast");
  return 1;
  }
 }

CheckStuck(){
object map;
  if (!this_player()) return 0;
  if (!map= present("mmap",this_player())) return;
  map= present("mmap",this_player());
  if(map->QueryA() && map->QueryC() && map->QueryD() && map->QueryE()){map->Stuck();}
  return 1;
 }

create(){
  ::create();
SetIntLong("This is room B.\n");
AddExit("south",#'do_d);
AddExit("east",#'do_c);
AddExit("southeast",#'do_e);
AddExit("northeast",#'do_a);
}

