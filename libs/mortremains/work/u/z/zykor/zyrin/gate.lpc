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
The gate creeks to the south, echoing throughout the abandoned village of
Ksyua. The dry wind flutters the redish colored dirt up into the air, creating
and illusion of a fine mist hovering overtop the ground. Small huts line the
road, and it appears this is the only road here. A main hut appears through
the dust, directly north from here and back south is a small forest.
EndText
  );
  set( "exits", ([
"out" : "vilenter",
"north" : "main1",
  ]) );
   set ("item_desc", ([
   ]) );
reset();
}
