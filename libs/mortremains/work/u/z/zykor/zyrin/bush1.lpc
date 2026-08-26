#include <config.h>
#include "zyrin.h"
#include <mudlib.h>

inherit ROOM;


void create(){
  ::create();
    seteuid(getuid());
  set( "light", 1 );
set("short","Forest outside Ksyia village");
  set( "long", @EndText
Overturned trees and bushes have been scattered across the area, small animals
about searching for food within the mess. A small pathway seems to have formed
through constant travel through this area and you can see smoke heading off if
you follow the path.

A large rock that is embedded into the soil is here.
EndText
  );
  set( "exits", ([
"north" : "path1"
  ]) );
   set ("item_desc", ([
   ]) );
reset();
}
