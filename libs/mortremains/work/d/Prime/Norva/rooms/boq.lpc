// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "The Bachelor Officer Quarters.");
  set("long", @ENDLONG
You stand at the front desk of the Bachelor Officer Quarters, home to
the non-married Naval Officers stationed on the base.  The room is lavishly
decorated and looks like a 5 star hotel.
ENDLONG
  );
  set("item_desc", ([
  ]) ) ;
  set("exits", ([
    "east" : ROOMS(base3),
    "west" : ROOMS(boq1),
  ]) ) ;
  ::create();
  reset();
}

void init() {
  add_action("block_dir", "go") ;
}

int block_dir(string str) {
  if (str != "west") return 0 ;
  write("The doors have a security system on them, and you don't appear\nto have a keycard.\n");
  return 1;
}
