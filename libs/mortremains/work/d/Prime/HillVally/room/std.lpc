#include <config.h>
#include <mudlib.h>

inherit ROOM;

#include "../camel.h"

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
   set("short", "Inside the old Abbey");
    set( "long", @EndText
EndText
    );
    set( "exits", ([
    ]) );
    set("item_desc", ([
   "floor" : "Right there under you feet, what did you expect?\n",
    ]) );
}
