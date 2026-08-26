#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("short", "The Lair of the Queen of Dragonkind");
    set ("long", @EndText
You are in a massive cave complex illuminated by torches set into the 
cavern walls. Dozens of small, young dragons prowl in the shadows, hissing
at you menacingly, and the overpowering reek of sulfur and ammonia burns 
your nostrils and brings tears to your eyes.
EndText
    );
    set("item_desc", ([
        "torches" : "They provide the scarce light here\n",
        "walls" : "They are almost invisible in the darkness.\n",
        "dragons" : "Generally, they are mere hatchlings, most of them "+
            "only about a dozen or so\nfeet in length.\n",         
    ]) );
    set("smell", "The air badly burns your nose as you inhale!\n");
}
