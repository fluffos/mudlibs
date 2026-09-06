/*
 * Your basic non-cash based storage facilility
 *
 */



#include "../rooms/priest_room.h"
#include <criminal.h>
#include <generic_items.h>

mixed Store; /* string or object */

void init_room() {

    add_action("cmd", "list");
    add_action("cmd", "borrow");
    add_action("cmd", "donate");
    this_object()->init_shop();
}

void reset_room() {
    if(!present("trashcan")) {
	object ob;
	ob=clone_object(GENERIC_TRASHCAN);
	move_object(ob,this_object());
    }
    this_object()->reset_shop();
}

void create_room() {
#ifdef UIDS
    seteuid(getuid());
#endif
    set_light_level(LT_LIGHTS);
    set_wd(WD_INDOORS);
    set_short("Storage");
    set_long(
      "You are in a storage area. You can borrow and donate things here.");
    this_object()->create_shop();
    reset_room();
}

/* Redefine when needed */
int
shop_open() {
    object ob;

    if (!(ob = present("shopkeeper", this_object()))) {
	notify_fail("The shop keeper is not here.\n");
	return 0;
    }


    return 1;
}


int cmd(string item) {
    if(!shop_open()) return 0;

    return (int)call_other(Store, query_verb()+"_item",item);
}


void set_store(mixed st) { if(!Store) Store = st; }



