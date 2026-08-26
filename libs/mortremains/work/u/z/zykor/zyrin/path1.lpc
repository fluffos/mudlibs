#include <config.h>
#include "zyrin.h"
#include <mudlib.h>

inherit ROOM;


void create(){
  ::create();
    seteuid(getuid());
  set( "light", 1 );
set("short","Path to Ksyua village");
  set( "long", @EndText
The path here is narrow and has trees and bushes flourishing on either side
of it. The large trees are home to many animals, although you cannot see them
you know they are there. Up ahead you can see a few huts and a large fire in
the middle of the village.
EndText
  );
  set( "exits", ([
"northeast" : "path2",
"south" : "bush1"
  ]) );
   set ("item_desc", ([
   ]) );
reset();
}
