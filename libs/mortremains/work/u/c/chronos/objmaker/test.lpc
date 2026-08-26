// Coded by Chronos.
#include <mudlib.h>

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "This is a test room.");
  set("long", @ENDLONG
You are in a room that I am using to test this shit
It needs to be two lines.
ENDLONG
  );
  ::create();
  reset();
}
