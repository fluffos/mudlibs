#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{	
	::create();
	seteuid( getuid() );
	set( "light", 1 );

   set( "short", "Vera's fruit garden" );

   set( "long", @EndText
Actually, Vera's fruit garden is not the right word for the place, where piles of yellow and brown grass are standing around. Berries, which look very old, dry and partly rotten, are spread all over the ground. Some poor and naked looking bushes and small trees are surrounding the area. A sweet stench is hanging in the air which makes you feel a bit dizzy.
You can either go back to the start or to the Void, since there is no obvious exit.
EndText
      );
   set( "exits", ([
	"start" : START,
    	"void"  : VOID,
   ]) );
}