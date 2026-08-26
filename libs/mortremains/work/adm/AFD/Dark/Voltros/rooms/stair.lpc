#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());

  set("author", "Gendor");

  set("light", 0);


  set("short", "staircase.");

set("long", @ENDLONG
All you can see here is a staircase leading down into some light.
ENDLONG
   );
                set("exits", ([
    "north" : ROOMS(pit),
    "down" :  ROOMS(foyer),
    ]) );
set("objects", ([
    MON(wraith) : 2,
  ]) );
   set("pre_exit_func", ([
     "down" : "guarded",
  ]) );
  ::create();
}
int guarded() {


  if (present("wraith", TO)) {
    write("The wraith is standing in front of the staircase....Looks like yer gonna have to go through it!\n");
   return 1;
  }
}

