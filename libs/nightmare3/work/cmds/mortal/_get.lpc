
/*
// This file is part of the TMI distribution mudlib.
// Please include this header if you use the code here.
// Originally written by Brian Leet.
// Adapted by Sulam (12-13-91)
// Help added by Brian (1/28/92)  *smirk*
// Better messages added by Brian (2/5/92)
// Light checking added by Hanse 4/11/92  :P
*/

#include "move.h"
#include <std.h>

inherit DAEMON;

int help();

int
cmd_get(string str) {
   object ob, *inv;
   int silly;
   int res, i;
   string tmp, type;
   int ammount;
   
    if(this_player()->query_ghost()) {
        notify_fail("You cannot do that in your immaterial state.\n");
        return 0;
    }
   if (!str) {
      return help();
   }
    if(effective_light(this_player()) < -1) {
	notify_fail("It is too dark.\n");
	return 0;
    }
   if(sscanf(str, "%d %s %s", ammount, type, tmp) != 3)
      if(sscanf(str, "%d %s", ammount, type) != 2) {
      if(str == "all") {
         inv = all_inventory(environment(this_player()));
         for(i=0;i<sizeof(inv); i++) {
            if(!inv[i]->query_short()) continue;
            if((int)inv[i]->allow_get(this_player())) {
		res = (int)inv[i]->move(this_player());
                if (res == MOVE_OK) {
                   write("You take " + inv[i]->query_short() + ".");
                  say(this_player()->query_cap_name() + " takes " +
                   inv[i]->query_short() + ".");
		}
	        else if(res == MOVE_NO_ROOM) {
              write(inv[i]->query_short() + ": You cannot carry that much.");
		}
	    }
	  }
         return 1;
         }
      ob = present(str, environment(this_player()));
      if (!ob) {
         if ((int)environment(this_player())->id(str)) {
            notify_fail("You can't take that!\n");
            return 0;
          }
         notify_fail("What " + str + "?\n");
         return 0;
         }
    if(!((int)ob->allow_get(this_player()))) {
	return 1;
      }
      res = (int)ob->move(this_player());
      if (res == MOVE_OK) {
         write("You take " + ob->query_short() + ".");
         this_player()->message("takes " + (string)ob->query_short(), 0, 0);
         return 1;
         }
      if (res == MOVE_NOT_ALLOWED)
         notify_fail("You can't do that.\n");
      else if (res == MOVE_NO_ROOM)
	notify_fail("You cannot carry that much.\n");
      return 0;
   }
   type = lower_case(type);
   if(ammount < 1) {
      notify_fail("You can only take positive ammounts of coins.\n");
      return 0;
   }
   if(this_player()->query_money(type) < 0)
      return 0;
   ob = present("coin", environment(this_player()));
   if(!ob || ob->query_money(type) < ammount) {
      notify_fail("I don't see that much "+type+" here.\n");
      return 0;
   }
   if(!this_player()->add_money(type, ammount)) {
      notify_fail("Your purse cannot hold that much.\n");
      return 1;
   }
   ob->add_money(type, -ammount);
   if((int)ob->query_total_money() == 0)
      destruct(ob);
   write("You put " + ammount + " " + type + " pieces into your purse.");
   say(this_player()->query_cap_name() + " takes some " + type + ".");
   return 1;
}

int
help() {
  write("Command: get\nSyntax: get <item | all>\n"+
        "This command will have your character try to pick up the\n"+
        "item specified, or if all is typed, it will make your\n"+
        "character try to pick up everything in the room.\n");
  return 1;
}
/* EOF */
