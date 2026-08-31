#include <std.h>
#include <arlon.h>


inherit ROOM;

void create()
{
 ::create();
 set_short("arlon stables");
 set_long("The shed has many saddles lined up on the walls. The shed is "
          "made out of wood and was poorly built by the looks of it. ");

 set_exits( ([ "west" : ROOMS "stables" ]) ); 
 }

void reset()
{
 ::reset();
 if (!present("hay"))
   {
    new (OBJ"hay")->move(this_object());
   } 
}
