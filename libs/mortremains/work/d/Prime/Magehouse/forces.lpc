#include <teleport.h>
#include <mudlib.h> 

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author","blood");
    set("no_teleport", NO_IN_OR_OUT);
    set( "short", "Forces of Energy" );
    set( "long", @EndText
Pure symbols of power burn away all else from your mind and
soul.  Lines of force converge here, and forming a complex 
web of magic. Artifacts of great power, may lay here.
EndText
    ); 
}
