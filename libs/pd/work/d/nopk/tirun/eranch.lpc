#include <std.h>
#include <tirun.h>

inherit ROOM;


void create()
{

 ::create();
 set_short("East Stables");
 set_long("The stable looks like its a clean place for "
          "horses to stay in. There is a bail of hay on the "
          "ground, along with a huge water trench. Horses "
          "roam around here freely.");
 set_listen("default", "The sounds of horses neiighing fills your ears.");
 set_smell("default", "The smell of manure fills your senses.");
 set_exits ( ([ "out" : ROOMS "ehonin6" ]) );

}

void reset()
{
 ::reset();
 if (!present("horse"))
   {
    new(MOB"horse")->move(this_object());
    new(MOB"horse")->move(this_object());
   }
}
