#include <mudlib.h>
#include "fuckstick.h"

inherit ROOM;

void create()

{
 ::create();
   seteuid(getuid());
   set("light", 1);
   set("short", "standard room");
   set("long", @ENDTEXT
this is a standard room
ENDTEXT
);
   set("exits", ([
]) );
}
