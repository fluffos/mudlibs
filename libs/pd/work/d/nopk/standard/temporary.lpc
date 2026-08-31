#include <locations.h>
#include <locations.h>
#include <std.h>

inherit ROOM;

void create() {
   ::create();
   
   set_short("...Lost in the temporary room...");
   set_long( "This is where temporary objects can be stuck in "
             "here to execute on a player without them being "
             "in the users inventory. if you're in here and not an "
             "immortal.. RUN BEFORE I FIND OUT...." );

   set_exits( ([ "square" : SQUARE_LOC ]) );
   set_no_clean(1);
}

