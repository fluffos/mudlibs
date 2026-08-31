#include <std.h>
#include <arlon.h>

inherit ROOM;

void create()
{
 ::create();
 set_short("Plains");
 set_long("The green grass starts to get taller as you wander "
          "farther away. Trees start to be more common and "
          "make it a bit darker. Animals are scurring away "
          "as you make your presence in the area. Animals "
          "can be seen eating fruits off the trees. ");
 set_listen("default", "The breeze blows on you lightly.");
 set_exits( ([ "west" : ROOMS "plains18",
               "east" : ROOMS "plains21" ]) );
}

void reset()
{
 ::reset();
 if (!present("lynx"))
    new( MOB "lynx")->move(this_object());
 if (!present("zebra"))
    new( MOB "zebra")->move(this_object());
  
}



