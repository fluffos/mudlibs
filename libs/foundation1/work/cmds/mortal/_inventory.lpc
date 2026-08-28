//	_inventory.c written by Descartes October 1992

#include "move.h"
#include <std.h>

inherit DAEMON;

int cmd_inventory() {
   object *items ;
   int x,silly;
   string result;
    if(effective_light(this_player()) < 0) {
	notify_fail("It is too dark.\n");
	return 0;
    }
   items = all_inventory(this_player());
   result = "You are carrying:\n";
   for (x=0; x < sizeof(items); x++) {
      if(items[x]->query_short()) {
         result += (string)items[x]->query_short() + ".\n";
        }
   }
   if(result == "You are carrying:\n") result = "You are empty-handed.\n";
   write(result);
   return 1;
}

int
help() {
   write("Command: inventory\nSyntax: inventory\n"+
      "This command gives you a list of the items\n"+
      "contained in your inventory.\n"
      "See also: score\n"
   );
   return 1;
}
/* EOF */
