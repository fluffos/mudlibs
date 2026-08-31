#include <std.h>
#include <arlon.h>

inherit ROOM;

void create()
{
 ::create();
  set_property("plains",1);
 set_short("Plains");
 set_long("The green grass starts to get taller as you wander "
          "farther away. Trees start to be more common and "
          "make it a bit darker." );
 set_listen("default", "The breeze blows on you lightly.");
 set_exits( ([ "south" : ROOMS "plains15",
               "east" : ROOMS "plains17" ]) );
}

void reset()
{
 ::reset();
 if (!present("lynx"))
   {
    new( MOB "lynx")->move(this_object());
   }
}



