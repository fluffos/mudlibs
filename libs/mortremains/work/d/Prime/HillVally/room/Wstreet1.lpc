#include <config.h>
#include <mudlib.h>

inherit ROOM;

#include "../camel.h"

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
   set("short", "Crest Road");
    set( "long", @EndText
EndText
    );
    set( "exits", ([
    ]) );
    set("item_desc", ([
   "path" : "Right there under you feet, what did you expect?\n",
    ]) );
}
