#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();    
    seteuid(getuid()) ;
    set("author", "cyanide");
    set ("light", 1) ;
    set ("long", @EndLong
You find yourself in a most bizarre city. All around you are thousands of
iron chains of every possible form and variety. The roads, the buildings, and
even the inhabitants are made of the chains. Other chains, with no apparant
use, run across the roads, into the buildings, and even reach into the skies.
EndLong
    );
    set ("short", "The City of Chains");
    set("item_desc", ([
      "chains" : "Everything here is made of them.\n",
    ]) );
    reset();
}
