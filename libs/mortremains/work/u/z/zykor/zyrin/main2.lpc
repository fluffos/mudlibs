#include <config.h>
#include "zyrin.h"
#include <mudlib.h>

inherit ROOM;


void create(){
  ::create();
    seteuid(getuid());
  set( "light", 1 );
set("short","Main Road");
  set( "long", @EndText
Main road of village. Finish later. :P
EndText
  );
  set( "exits", ([
"south" : "main1",
"north" : "main3"
  ]) );
   set ("item_desc", ([
   ]) );
reset();
}
