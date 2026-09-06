/* Allows Players to reset Miniature Area */

#include "../priest.h"

#define GARDEN_SERVER PRIEST_GARDENS "virtual/server"

#define MIN_TIME 400

int old_time;

push(string s){
    if(!s || s != "pane"){
	notify_fail("What are you trying to push?\n");
	return 0;
    }

    if((time() - old_time)<MIN_TIME || 
      this_player()->query_guild() != "priest"){
	notify_fail("Nothing happens.\n");
	return 0;
    }

    this_player()->tell_me("Your hand sinks into the pane of glass as if \
it were made of water. There is a tingling throughout your entire body.");

    write("A rumbling voice says: The Gardens will ");
    GARDEN_SERVER->reboot_world(1);
    old_time=time();
    SERVER->inform("Gardens will reboot in 1 minute.");

    return 1;
}
