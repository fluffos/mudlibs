#include "/u/c/cyanide/debug.h"
#include <mudlib.h>
#include "central.h"

inherit SHOP ;

object can;

void create() {
    ::create();
    set ("light", 1) ;
    set("author", "cyanide");
    set ("long", wrap(
	"You find yourself in a dimly lit pawn shop. A strange mixture of "+
	"odds and ends can be found here, as well as a vast variety of "+
	"jewelery. A greasy half-orc eyeballs you as you enter.\n\n"+
	"Commands are: buy, list, sell, and appraise."
      ) );
    set("short", "The Pawn Shop") ;
    set("safe", 1);
    set ("exits", ([
      "west" : M_ROOM+"road0_-4",
    ]));
    can = clone_object(CAN);
    can->move(TO);
}

void reset() {
    object *stuff;
    int i;

    ::reset();

    can = present("can", TO);
    if (can) {
	stuff = all_inventory(TO);
	for (i=0; i<sizeof(stuff); i++) {
	    if (living(stuff[i])) continue;
	    if (stuff[i]->id("can")) continue;

	    stuff[i]->move(can);
	}
	stuff = all_inventory(can);
	for (i=sizeof(stuff)-1; i >= 0; i--) 
	    stuff[i]->remove();

	tell_room(TO, "A man in a blue uniform comes in and empties the "+
	  "garbage.\n");
    }
}
