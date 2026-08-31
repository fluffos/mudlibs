#include <std.h>
#include <arlon.h>


inherit ROOM;

void create()
{
 ::create();
 set_short("arlon stables");
 set_long("There are steel silver bars around the horses with a small "
          "gate on it. There is hay on the ground and a small water "
          "trough where horses can drink from. There is a cover over "
          "the steel bars on top to provide shade to the horses.");

 set_exits( ([ "north" : ROOMS "esquare2",
               "east":   ROOMS "shed" ]) ); 
 }

void reset()
{
 ::reset();
 if (!present("horse"))
   {
    new (MOB"horse")->move(this_object());
    new (MOB"horse")->move(this_object());
   } 
}
