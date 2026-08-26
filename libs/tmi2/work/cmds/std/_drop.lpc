// File: /cmds/std/_drop.c
// based on TMI-2 version
// completely rewritten...cleaned up...modified
// by Zeus, 13-03-1993
// Fixed dropping nothing (no objs or no droppable objs)
// Leto 26/5/95

#include <mudlib.h>
#include <money.h>
#include <move.h>

#define CAP_NAME this_player()->query("cap_name")

inherit DAEMON;

string help();

int cmd_drop(string str) {
     mapping coins;
     object *inv, ob, env;
     int res, amount, capac, i, money, dropped;
     string short, *types, type, word, tmp;

     if(!str) return write(help());
     if (!(env = environment(this_player()))) {
          notify_fail("You can't drop anything in the void!\n");
          return 0;
     }
     this_player()->block_attack(2);
     if(sscanf(str, "%d %s %s", amount, type, tmp) == 3 ||     
     sscanf(str, "%d %s", amount, type) == 2) {
          money = this_player()->query("wealth/"+type);
	  if (amount<1) {
	    notify_fail ("You can't do that.\n") ;
	    return 0 ;
	  }
          if(money < amount) {
               notify_fail("You don't have that much "+type+".\n");
               return 0;
          }
          this_player()->set("wealth/"+type, money-amount);
          capac = this_player()->query("capacity");
          this_player()->set("capacity", capac+amount);
          ob = clone_object(COINS);
          ob->set_type(type);
          ob->set_number(amount);
          res = ob->move(environment(this_player()));
          if(res != MOVE_OK) {
               this_player()->set("wealth/"+type, money);
               this_player()->set("capacity", capac);
               ob->remove();
               notify_fail("You can't drop that.\n");
               return 0;
          }
          if(amount == 1) word = "coin"; else word = "coins";
          write("You drop "+amount+" "+type+" "+word+".\n");
          say(CAP_NAME+" drops some "+type+" "+word+".\n");
          return 1;
     }
     if(str == "all") {
          inv = all_inventory(this_player());
    //if(!pointerp(inv) && sizeof(inv) < 1) {
         if(sizeof(inv) < 1) {
               notify_fail("You are not carrying anything.\n");
               return 0;
          }
          for(i = 0; i < sizeof(inv); i++) {
		if(!inv[i] || inv[i]->query("prevent_drop"))  continue;
               res = inv[i]->move(environment(this_player()));
               if(res != MOVE_OK) continue;
		if(inv[i])
		short = (string)inv[i]->query("short");
               if(!short) short = "something";
               say(CAP_NAME+" drops "+short+".\n");
               dropped++;
          }
       if(dropped)
      {
          write("You drop your whole inventory on the ground.\n");
        return 1;
       }
          else notify_fail("You are not carrying anything you wish to part with.\n");
        return 0;
     }
     if(str == "all coins") {
          coins = this_player()->query("wealth");
          if(!mapp(coins) || sizeof(coins) == 0) {
               notify_fail("You have no coins in your purse.\n");
               return 0;
          }
          types = keys(coins);
          if(!pointerp(types) || sizeof(types) == 0) {
               notify_fail("You have no coins in your purse.\n");
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
               res = ob->move(environment(this_player()));
               if(res != MOVE_OK) {
                    this_player()->set("wealth/"+types[i], coins[types[i]]);
                    this_player()->set("capacity", capac);
                    ob->remove();
                    continue;
               }
               if(coins[types[i]] == 1) word = "coin"; else word = "coins";
               write("You drop "+coins[types[i]]+" "+types[i]+" "+word+".\n");
               say(CAP_NAME+" drops some "+types[i]+" "+word+".\n");
          }
          return 1;
     }
     if(sscanf(str, "all %s", type) == 1) {
          money = this_player()->query("wealth/"+type);
          if(!money) {
               notify_fail("You don't have any "+type+".\n");
               return 0;
          }
          this_player()->set("wealth/"+type, 0);
          capac = this_player()->query("capacity");
          this_player()->set("capacity", capac+money);
          ob = clone_object(COINS);
          ob->set_type(type);
          ob->set_number(money);
          res = ob->move(environment(this_player()));
          if(res != MOVE_OK) {
               this_player()->set("wealth/"+type, money);
               this_player()->set("capacity", capac);
               ob->remove();
               notify_fail("You can't drop that.\n");
               return 0;
          }
          write("You drop all your "+type+" coins.\n");
          say(CAP_NAME+" drops some "+type+" coins.\n");
          return 1;
     }
     ob = present(str, this_player());
     if(!ob) {
          notify_fail("You don't have that on you.\n");
          return 0;
     }
 
    if(ob->query("prevent_drop")) {
 	notify_fail("You can't drop that object.\n");
    return 0; }
 
     res = ob->move(environment(this_player()));
     if(res != MOVE_OK) {
          notify_fail("You can't drop that.\n");
          return 0;
     }
      short = (string)ob->query("short") ;
     if(!short) short = "something";
     write("You drop "+short+".\n");
     say(CAP_NAME+" drops "+short+".\n");
     return 1;
}

string help() {
     return("Syntax: drop <item | all>\n\n"+
           "This makes your character try to drop the specified\n"+
           "item.  If all is used then your character drops all\n"+
           "items carried. If you type \"drop all gold\" or other\n"+
           "type, then all of your coins of that type are dropped.\n"+
           "\"Drop all coins\" drops all your money.\n"+
           "\nSee also: get, put\n");
}
