#include <teleport.h>
#include <mudlib.h>

inherit ROOM;

void create()
{   
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author","blood");
    set( "short", "In the Clouds" );
    set( "long", @EndText
You are floating on fluffy white clouds here.  Large droplets of
water crystallize against your skin, which is turning pink.  You
feel a sense of peace here, not found in many places.
EndText
    );
    set("no_teleport", NO_IN_OR_OUT);
}
