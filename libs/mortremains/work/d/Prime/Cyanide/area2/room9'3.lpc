#include <config.h>
#include <mudlib.h>

inherit ROOM;
clean_up () {
remove () ;
}

void create()
{
  ::create();//<- gets all the information from the original create()
  seteuid( getuid());
  set( "light", 1 );
set("area_type", ([
"black" : 2,
]) );
set("short", "this room needs a short description");
  set( "long", @EndText
This room needs a long description.
EndText
  );
set("arena", 1);
  set( "exits", ([
    "start" : START,
  ]) );
}