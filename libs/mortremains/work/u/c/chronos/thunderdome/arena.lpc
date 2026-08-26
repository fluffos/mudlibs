#include <mudlib.h>
#include "td.h"

inherit ROOM ;

void create() {
  object ob ;
  seteuid(getuid()) ; 
  set("short", "In the ThunderDome Arena") ;
  set("long", @ENDLONG
You are in the ThunderDome Area.  Prepare for Battle!
ENDLONG
  );
  set("light", 1) ;
  ::create() ;
  ob = clone_object(TD+"echo_device") ;
  ob->move(TO) ;
}

void init() {
  add_action("go", "go") ;
}

int go(string str) {
   write("There is nowhere to go until you are finished with Battle.\n") ;
   return 1;
}
