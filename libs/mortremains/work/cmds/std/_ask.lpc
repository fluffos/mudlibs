// _ask.c
// Lets a player ask a monster about a subject. If the monster has set
// the inquiry property to a mapping, then if that mapping has an entry under
// the subject, then the monster will say that string.
// Written by Pyrosius@TMI-2
// He and Mobydick integrated it into the lib on 8-18-93.
// Modified by Chronos to allow people to refer to monsters with something
// other than their NAME.  It checks ID's now.

#include <mudlib.h>
inherit DAEMON;

int cmd_ask(string str) {

   string mon_name, subject;
   object mon_obj;
   mapping cmd_map;
/* More unneeded code..
  int i;
  i = TP->query_rest_status() ;
  if (i==2) {
    write("You can't ask anyone anything while you are sleeping.\n");
    return 1;
  }
*/

  if (TP->query("mute")) {
    write("You are mute, and cannot speak.\n");
    return 1;
  }
  if (!str) {
     notify_fail("Ask who about what?\n");
     return 0;
     }
  if (sscanf(str, "%s about %s", mon_name, subject) != 2) {
     notify_fail("Ask <monster> about <what>?\n");
     return 0;
     }

  mon_name = lower_case(mon_name);
  mon_obj = present(mon_name, environment(this_player()));
  if (mon_obj == TP) {
    write("That doesn't make a whole lot of sense.\n");
   return 1;
  }

  if (!present(mon_name, environment(this_player()))) {
     notify_fail(capitalize(mon_name) + " is nowhere to be found.\n");
     return 0;
     }

  if (mon_obj->query("user")) {
	write ("You ask "+capitalize(mon_name)+ " about "+subject+".\n") ;
	tell_object(mon_obj,this_player()->query("cap_name")+" asks you: Know anything about "+subject+"?\n") ;
	say (this_player()->query("cap_name")+" asks "+capitalize(mon_name)+": Know anything about "+subject+"?\n", mon_obj) ;
    return 1 ;
    }

  cmd_map = ([ ]);
  cmd_map = mon_obj-> query("inquiry");

  if (sizeof(cmd_map)==0) {
    switch(random(5)) {
     case 1: write(capitalize(mon_name) + " ignores you.\n");
   break;
     case 2: write(capitalize(mon_name) + " looks at you.\n");
   break;
     case 3: write(capitalize(mon_name) + " didn't seem to hear you.\n");
   break;
    default: write(capitalize(mon_name) + " looks at you blankly.\n");
   break;  
   }
	return 1 ;
    }
  if (undefinedp(cmd_map[subject])) {
	tell_room(environment(this_player()), this_player()-> query("cap_name") +
	    " asks " + capitalize(mon_name) + " about " + subject + ".\n",
	    this_player()) ;
     tell_room(environment(this_player()), capitalize(mon_name) + " says: " +
              "I don't know about that.\n");
     return 1;
  }
  else
      tell_room(environment(this_player()), this_player()-> query("cap_name") +
	    " asks " + capitalize(mon_name) + " about " + subject + ".\n",
		this_player()) ;
  tell_room(environment(TP), iwrap(capitalize(mon_name)+ " says: "+
   cmd_map[subject] ) ) ;
  return 1;
  }

string help() {
  return (@ENDHELP

Usage: ask <target> <topic>

This command allows you to ask another living being about a certain
topic you might have in mind.

ENDHELP
  );
}
