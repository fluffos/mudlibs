// config.h only included here for the defines of START and VOID
// it doesn't need to be included in most rooms.
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid(getuid());
    set("author", "cyanide");
    set( "light", 1 );
    set ("short", "The Suggestion Room" );
    set( "long", @EndText
This is the suggestion room for WHATEVER. 
Use it often - please. It goes right onto Cy's board.
EndText
    );
    set( "exits", ([
      "east" : WIZHALL,
    ]) );
    call_other("/d/Ancients/obj/suggestions", "dummy"); 
}

void init() {
}

