#include <std.h>
#include <arlon.h>
inherit ROOM;
void create()
{
 ::create();
  set_property("forest",1);
 set_short("An oasis");
 set_long("The oasis has a body of crystal clear water in the middle, "
          "surrounded by soft sand. Palm trees tower over you and provide "
          "shade for the animals that live in the area. The path "
          "continues around the oasis");
 set_listen("default", "The breeze blows lightly.");
 set_exits( ([ "north" : ROOMS "plains6",
               "south" : ROOMS "plains7" ]) );
}
void reset()
{ 
 ::reset();
 if (!present("cheetah"))
   {
    new(MOB "cheeta")->move(this_object());
    present("cheetah")->force_me("sleep");
   }
 if (!present("lion"))
   {
    new(MOB "lion")->move(this_object());
    present("lion")->force_me("sleep");
   }
}
