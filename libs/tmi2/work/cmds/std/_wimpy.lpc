/*
// The "wimpy" command.
// Coded by Buddha@TMI on 2/16/92
// Modified for 0.9.0 mudlib by Mobydick, 9/19/92
// This file is part of the TMI distribution mudlib.
// Please retain this header if you use it.
*/

#include <mudlib.h>

inherit DAEMON ;

int help();

mixed cmd_wimpy(string arg) {

   int level;

   this_player()->block_attack(2) ;
   if(!arg) {
	write ("Your wimpy is set to: "+(int)previous_object()->query("wimpy")+"%.\n") ;
      return 1;
   }
   if(!sscanf(arg, "%d", level)) {
      help();
      return 1;
   }
	previous_object()->set ("wimpy", level) ;
	write ("Your wimpy is now set to "+arg+"%.\n") ;
   return 1;
}

int help() {
   write("Usage:\nwimpy <number>\n" +
      "Sets the percentage of your total hit points you can lose before you\n" +
      "flee from an attacker.\n") ;
   return 1;
}

