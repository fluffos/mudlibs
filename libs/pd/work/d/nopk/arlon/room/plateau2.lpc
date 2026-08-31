#include <std.h>
#include <arlon.h>

inherit ROOM;

void create()
{
 ::create();
 set_short("Top of the plateau");
 set_long("The sight of a whole new land is seen from here as "
          "you can see as far as you can see off the side of "
          "this cliff. To the east is a whole different "
          "scenerio.");
 set_listen("default", "You hear the beautiful music sung by birds.");
 set_exits( ([ "down" : ROOMS "plateau1",
//               "east" : ROOMS "quicksand" ]) );
]) );
}


void reset()
{
 ::reset();
 if (!present("snake"))
   {
     new (MOB "snake")->move(this_object());
//     new (MOB "snake")->move(this_object());
//     new (MOB "snake")->move(this_object()); 
   }
}
