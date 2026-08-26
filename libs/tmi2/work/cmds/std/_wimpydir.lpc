/*
// command: wimpydir
// Sets the direction in which one will flee in.
// Written by Buddha@TMI on 2/16/92
// Modified for mudlib 0.9.0 by Mobydick@TMI-2 on 9/19/92
// This file is a part of the TMI distribution mudlib.
// Please retain this header if you use it.
   */

#include <mudlib.h>

inherit DAEMON ;

int help();

int cmd_wimpydir(string str) {
   this_player()->block_attack(2) ;
   if(!str) {
	str = previous_object()->query("wimpydir") ;
	if (!str) {
		write ("Your wimpy direction is not set.\n") ;
	} else {
		write ("Your wimpy direction is now set to "+(string)previous_object()->query("wimpydir")+".\n") ;
	}
      return 1;
   }
   if (str=="none") {
	previous_object()->delete("wimpydir") ;
	write ("Your wimpy direction is now unset.\n") ;
	return 1 ;
   }
   if(!stringp(str)) {
      help();
      return 1;
   }
	previous_object()->set("wimpydir", str) ;
	write ("Your wimpy direction is now set to "+str+".\n") ;
   return 1;
}

int help() {
   write("Usage:\nwimpydir <direction>\n" +
      "This command will set the direction you will flee in when in combat.\n" +
      "If the direction isn't set or doesn't work, you will flee in a random\n" +
      "direction.\n" +
      "You can unset your wimpy direction by typing 'wimpydir none'.\n" +
      "If no direction is specified, it will tell you the current setting.\n");
   return 1;
}

