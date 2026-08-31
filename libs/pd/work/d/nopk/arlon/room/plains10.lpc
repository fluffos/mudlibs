#include <std.h>
#include <arlon.h>

inherit ROOM;

void create()
{
 ::create();
  set_property("plains",1);
 set_short("A path");
 set_long("The green grass stands tall waving in the wind. The ground "
          "is a little moist and foot prints and an assortment of "
          "animal foot prints. There are a couple short trees "
          "scattered around. There is a dirt path leading into "
          "the town south.");
 set_listen("default", "The breeze blows on you lightly.");
 set_exits( ([ "north": ROOMS "plains9",
               "south": ROOMS "square" ]) );
}

void reset()
{
 ::reset();
 if (!present("sign"))
   new(OBJ "sign")->move(this_object());
 if (!present("soldier"))
   {
    new( MOB "soldierkeeper")->move(this_object());
    new( MOB "soldierkeeper")->move(this_object());
   }
}
