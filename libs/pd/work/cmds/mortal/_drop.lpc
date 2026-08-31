//      _drop.c
//      Mostly the _drop.c from the TMI distribution mudlib
//      Originally written by Brian Leet
//      Adapted 12.13.91 by Sulam
//      Help added by Brian 1.28.92
//      Messages improved by Brian 2.5.92
//      Money handling added by Descartes of Borg Halloween 1992
//      Rewritten with consolidation by Nightshade 10-09-02

#include "move.h"
#include <std.h>
#include <objects.h>

inherit DAEMON;

int help();

int
cmd_drop(string str) {
   object ob;
   int res, i;
   string tmp, type;
   int ammount;
   
   if (!str) {
      return help();
   }
   seteuid(getuid(previous_object()));
   if(sscanf(str, "%d %s %s", ammount, type, tmp) != 3)
      sscanf(str, "%d %s", ammount, type);
   if(type) {
      if(tmp == "coins" || this_player()->query_money(type) > 0) {
         if((int)this_player()->query_money(type) < 0) {
            notify_fail("That type of currency doesn't exist.\n");
            return 0;
         }
         if(this_player()->query_money(type) < ammount) {
            notify_fail("There is not that much "+type+" in your purse.\n");
            return 0;
         }
         ob = present("pile of coins", environment(this_player()));
         if(!ob) {
            ob = new(OB_COINS);
         }
         ob->add_money(type, ammount);
         if(this_player()->is_player())
           ob->set_last_holder(this_player()->query_name());
         this_player()->add_money(type, -ammount);
         write("You drop "+ammount+" "+type+" pieces.");
         say(this_player()->query_cap_name()+" drops some "+type+".");
         ob->move(environment(this_player()));
         return 1;
      }
   }
   if(!type) {
      type = str;
      ammount = 1;
   }
   if(tmp)
      type = type+tmp;
   if(type == "all") {
      object *inv;
      inv = all_inventory(this_player());
      if (sizeof(inv) == 0) {
         write("Nothing to drop!");
         return 1;
      }
      write("You drop your whole inventory on the ground.");
      say(this_player()->query_cap_name()+" drops everything they have.");
      for(i=0;i<sizeof(inv); i++ ){
         ob = inv[i];
         tmp = (string)ob->query_short();
         if(ob->drop()) continue;
         res = (int)ob->move(environment(this_player()));
     /*    if (res == MOVE_OK) {
            message("info", previous_object()->query_cap_name()+" drops "+tmp+".", environment(this_player()), this_player());
         }  */
      }
      return 1;
   }
   if(ammount > 1) {
      ob = present(type+" "+(string)ammount, this_player());
      if(!ob) {
         notify_fail("You do not have "+cardinal(ammount)+" "+pluralize(type)+" to drop.\n");
         return 0;
      }
      write("You drop "+cardinal(ammount)+" "+pluralize(ob->query_short())+".");
      say(this_player()->query_cap_name()+" drops "+cardinal(ammount)+" "+pluralize(ob->query_short())+".");
      for(;ammount > 0;ammount--) {
         ob = present(type+" "+(string)ammount, this_player());
         if(ob->drop()) continue;
         ob->move(environment(this_player()));
      }
   }
   else {
      ob = present(type, this_player());
      if (!ob) {
         notify_fail("What " + type + "?\n");
         return 0;
         }
      if(ob->drop(type)) return 1;
      tmp = (string)ob->query_short();
      res = (int)ob->move(environment(this_player()));
      if (res == MOVE_OK) {
        say(this_player()->query_cap_name()+" drops "+tmp+".\n", this_player());
         write("You drop "+tmp+".");
         return 1;
         }
      if (res == MOVE_NOT_ALLOWED)
         notify_fail("You can't do that.\n");
      else if (res == MOVE_NO_ROOM)
         notify_fail("Not enough room.\n");
      return 0;
   }
   return 1;
}

int 
help() {
  write("Command: drop\nSyntax: drop <item | all>\n"+
        "This makes your character try to drop the specified\n"+
        "item.  If all is used then your character drops all\n"+
        "items carried.\n");
  return 1;
}
/* EOF */
