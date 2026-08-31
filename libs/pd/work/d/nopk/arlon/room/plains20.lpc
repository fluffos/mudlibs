#include <std.h>
#include <arlon.h>

inherit ROOM;

void create()
{
 ::create();
 set_short("Plains");
 set_long("The green grass stands tall waving in the wind. The ground "
          "is a little moist and foot prints and an assortment of "
          "animal foot prints going in all directions. The grass is "
          "too thick to continue in any other direction but north.");
 set_listen("default", "The breeze blows on you lightly.");
 set_exits( ([ "north" : ROOMS "plains15" ]) );
}

void reset()
{
 ::reset();
 if (!present("rock"))
   new( OBJ "rock" )->move(this_object());
}



