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
          "make it a bit darker. Animals are scurring away "
          "as you make your presence in the area." );
 set_listen("default", "The breeze blows on you lightly.");
 set_exits( ([ "west" : ROOMS "plains16",
               "north" : ROOMS "plains18" ]) );
}

void reset()
{
 ::reset();
 if (!present("cheeta"))
   {
    new( MOB "cheeta")->move(this_object());
   }
}



