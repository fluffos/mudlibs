#include <config.h>
#include "zyrin.h"
#include <mudlib.h>

inherit ROOM;


void create(){
  ::create();
    seteuid(getuid());
  set( "light", 1 );
set("short","Gate to Ksyua Village");
  set( "long", @EndText
A large gate looms in your path, and on the other side you spot a few huts
made of sticks and straw. All the trees have been cleared away to allow room
for the huts and soft dirt has been layed down all around. You can see small
and large footprints in the dirt, but there are no people in sight. You can
hear the same strange mocking laughter of the native birds as they fly overhead
in circles. You notice one larger hut directly north, while smaller huts stand
to both east and west.
EndText
  );
  set( "exits", ([
"gate" : "gate",
"south" : "path3"
  ]) );
   set ("item_desc", ([
   ]) );
reset();
}
