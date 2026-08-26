#include "/u/c/cyanide/debug.h"

int checkob(object player) {
     object ob;

    ob = present("#CLASS_OBJECT#", player);

    if (!ob || !ob->query("equipped")) {
	tell_object(player, 
	  "You must have your implant equipped to use that.\n");
	return 0;
    } else {
	return 1;
    }
}
