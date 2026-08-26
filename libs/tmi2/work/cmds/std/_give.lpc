// File: /cmds/std/_give.c
// based on TMI-2 version
// completely rewritten...cleaned up...modified
// added give all to <player>
// added give all <gold | coins> to <player>
// by Zeus, 13/03/1993

#include <mudlib.h>
#include <money.h>
#include <move.h>

#define CAP_NAME this_player()->query("cap_name")

inherit DAEMON;

string help();

int cmd_give(string str) {
     object *inv, ob, target;
     int res, amount, i, money, capac;
     string short, who, item, word, *types, type;
     mapping coins;

     if(!str) return write(help());
     if(!this_player()->query_vision()) {
          notify_fail("It is dark and you can't see anything.\n");
          return 0;
     }
     this_player()->block_attack(2);
     if(sscanf(str, "%d %s to %s", amount, type, who) == 3) {
	if (amount<1) {
	    notify_fail ("You can't do that.\n") ;
	    return 0 ;
	}
          money = this_player()->query("wealth/"+type);
          if(money < amount) {
               notify_fail("You don't have that much "+type+".\n");
               return 0;
          }
          target = present(who, environment(this_player()));
          if(!target || !living(target)) {
               notify_fail("There's no one here by that name.\n");
               return 0;
          }
          this_player()->set("wealth/"+type, money-amount);
          capac = this_player()->query("capacity");
          this_player()->set("capacity", capac+amount);
          ob = clone_object(COINS);
          ob->set_type(type);
          ob->set_number(amount);
          res = ob->move(target);
          if(res != MOVE_OK) {
               this_player()->set("wealth/"+type, money);
               this_player()->set("capacity", capac);
               notify_fail(target->query("cap_name")+" can't carry that.\n");
               return 0;
          }
          if(amount == 1) word = "coin"; else word = "coins";
          write("You give "+target->query("cap_name")+" "+amount+" "+type+
               " "+word+".\n");
          say(CAP_NAME+" gives "+target->query("cap_name")+" some "+type+
               " "+word+".\n", target);
          tell_object(target, CAP_NAME+" gives you "+amount+" "+type+
               " "+word+".\n");
          return 1;
     }
     if(sscanf(str, "all %s to %s", type, who) == 2) {
          target = present(who, environment(this_player()));
          if(!target || !living(target)) {
               notify_fail("There's no one here by that name.\n");
               return 0;
          }
          if(type == "coins" || type == "coin") {
               coins = this_player()->query("wealth");
               if(!mapp(coins) || sizeof(coins) == 0) {
                    notify_fail("You have no coins.\n");
                    return 0;
               }
               types = keys(coins);
               if(!pointerp(types) || sizeof(types) == 0) {
                    notify_fail("You have no coins.\n");
                    return 0;
               }
               for(i = 0; i < sizeof(types); i++) {
                    if(coins[types[i]] == 0) continue;
                    this_player()->set("wealth/"+types[i], 0);
                    capac = this_player()->query("capacity");
                    this_player()->set("capacity", capac+coins[types[i]]);
                    ob = clone_object(COINS);
                    ob->set_type(types[i]);
                    ob->set_number(coins[types[i]]);
                    res = ob->move(target);
                    if(res != MOVE_OK) {
                         this_player()->set("wealth/"+types[i],
                              coins[types[i]]);
                         this_player()->set("capacity", capac);
                         ob->remove();
                         continue;
                    }
                    if(coins[types[i]] == 1) word = "coin"; else word = "coins";
                    tell_object(target, CAP_NAME+" gives you "+coins[types[i]]+" "+
                         types[i]+" "+word+".\n");
                    say(CAP_NAME+" gives "+target->query("cap_name")+" some "+
                         types[i]+" "+word+".\n", target);
               }
               write("You give all your coins to "+target->query("cap_name")+
                    ".\n");
               return 1;
          }
          money = this_player()->query("wealth/"+type);
          if(money < 1) {
               notify_fail("You don't have any "+type+".\n");
               return 0;
          }
          this_player()->set("wealth/"+type, 0);
          capac = this_player()->query("capacity");
          this_player()->set("capacity", capac+money);
          ob = clone_object(COINS);
          ob->set_type(type);
          ob->set_number(money);
          res = ob->move(target);
          if(res != MOVE_OK) {
               this_player()->set("wealth/"+type, money);
               this_player()->set("capacity", capac);
               ob->remove();
               notify_fail(target->query("cap_name")+" can't carry any more "+
                    type+".\n");
               return 0;
          }
          if(money == 1) word = "coin"; else word = "coins";
          write("You give "+target->query("cap_name")+" all your "+type+
               " coins.\n");
          tell_object(target, CAP_NAME+" gives you "+money+" "+type+" "+word+".\n");
          say(CAP_NAME+" gives "+target->query("cap_name")+" some "+type+
               " "+word+".\n", target);
          return 1;
     }
     if(sscanf(str, "all to %s", who) == 1) {
          target = present(who, environment(this_player()));
          if(!target || !living(target)) {
               notify_fail("There's no one here by that name.\n");
               return 0;
          }
          inv = all_inventory(this_player());
          for(i = 0; i < sizeof(inv); i++) {
		if(!inv[i] || inv[i]->query("prevent_drop"))  continue;
               res = inv[i]->move(target);
               if(res == MOVE_OK) {
		    short = (string)inv[i]->query("short") ;
                    if(!short) short = "something";
                    write("You give "+target->query("cap_name")+" "+short+".\n");
                    say(CAP_NAME+" gives "+target->query("cap_name")+" "+
                         short+".\n", target);
                    tell_object(target, CAP_NAME+" gives you "+short+".\n");
               } else write(target->query("cap_name")+" can't carry that.\n");
          }
          return 1;
     }
     if(sscanf(str, "%s to %s", item, who) == 2) {
          ob = present(item, this_player());
          if(!ob) {
               notify_fail("I don't see that here.\n");
               return 0;
          }
	 
	if(ob->query("prevent_drop")) {
		notify_fail("You can't give that object away.\n");
	return 0; }

          target = present(who, environment(this_player()));
          if(!target || !living(target)) {
               notify_fail("There's no one here by that name.\n");
               return 0;
          }
          res = ob->move(target);
          if(res == MOVE_OK) {
	       short = (string)ob->query("short") ;
               if(!short) short = "something";
               write("You give "+target->query("cap_name")+" "+short+".\n");
               say(CAP_NAME+" gives "+target->query("cap_name")+" "+
                    short+".\n", target);
               tell_object(target, CAP_NAME+" gives you "+short+".\n");
               return 1;
          }
          notify_fail(target->query("cap_name")+" can't carry that.\n");
          return 0;
     }
     return write(help());
}

string help() {
     return("Syntax: give <item | all> to <player>\n\n"+
           "This command will make you give an item in your inventory\n"+
           "to the player specified.  You must be in the same room for\n"+
           "this to occur.\n"+
           "\nSee also: drop\n");
}
