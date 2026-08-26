#include <mudlib.h>

inherit ROOM ;
  

object monster ;
int monster_flag ;

void reset() {
     monster_flag = 0 ;
}


void create() {
  seteuid(getuid()) ;
  set("short", "example room") ;
  set("long", @ENDLONG
  This is the example from chronos to YOU.
   Search "grass" or "tall grass" to see what I did.
ENDLONG
  ) ;
  set("search_func", ([
     "grass" : "mon_func", 
    "tall grass" : "mon_func",
  ]) ) ;
  ::create();
   reset() ;
}

int mon_func() {
  if (monster_flag) {
     write("You find nothing this time..\n") ;
   return 1;
  }
  write("You search through the grass and something suddenly jumps out at you!\n") ;
  say(TPN+" searches through the tall grass and is surprised by something!\n") ;
   monster=clone_object("../mon/wraith") ;
  monster->move(TO) ;
  monster->kill_ob(TP) ;
  return 1;
}
