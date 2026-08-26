#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {    
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("long", @EndLong
You are on a small road in the Sinking City of Minauros, the Third Layer of
Baator. The road here is made of thick, sticky black mud, and the buildings
here are made of chalky black stone, forever sinking slowly into the mire.
EndLong
    );
    set ("short","Sinking city of Minauros");
    set("item_desc", ([
      "mud" : "It seems unnaturally sticky, and is a sooty black.\n",
      "buildings" : "Stone must be very rare in this place.\n",
      "mire" : "The whole city is build on a swamp.\n",
      "mionauros" : "That's the city you're in right now.\n",
    ]) );
    set("smell", ([
      "mud" : "It stinks like shit, to be very frank.\n",
      "default" : "The entire city reeks with the stench of decay.\n"
    ]) );
    reset();
}


