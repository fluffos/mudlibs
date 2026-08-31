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
          "as you make your presence in the area. Animals "
          "can be seen eating fruits off the trees. ");
 set_listen("default", "The breeze blows on you lightly.");
 set_exits( ([ "south" : ROOMS "plains17",
               "east" : ROOMS "plains19" ]) );
}

void reset()
{
 ::reset();
 if (!present("antelope"))
   {
    new( MOB "antelope")->move(this_object());
    new( MOB "antelope")->move(this_object());
   }
}



