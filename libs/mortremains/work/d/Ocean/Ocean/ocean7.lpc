#include <mudlib.h>

inherit ROOM ;

void create() {
  seteuid(getuid());
  set("short", "Somewhere in the Ocean.");
  set("long", @ENDLONG
You are floating about in the middle of the ocean.
You have no idea where you are, and you can't see land in any direction.
ENDLONG
  );
  set("hide_exits", 1) ;
  set("light", 1) ;
  ::create() ;
  reset() ;
}

void init() {
  add_action("swim", "swim") ;
  add_action("dive", "dive") ;
  add_action("swim", "go") ;
}

int swim(string str) {
  write(@ENDLONG
You swim about for a bit, but with no point of reference, you can't
tell if you are making any progress or not.
ENDLONG
  );
  return 1;
}

int dive(string str) {
  write(@ENDLONG
You dive down into the black water, but quickly run out of air and
return to the surface.
ENDLONG
  );
  return 1;
}


