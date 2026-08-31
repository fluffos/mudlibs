#include <std.h>
#include <daemons.h>
#include <money.h>

#define STORAGE_ROOM "/d/nopk/standard/astorage"
#define AUCTION_HOUSE "/d/nopk/tirun/auc_house"
#define AUC_CURR_RATES ({ 10, 1, 0.1, 0.02, 0.01 })

inherit DAEMON;

object thing, auctioner, bidder;
int canbid, minpriceset;
string lastbid_curr;
int lastbid_amt;

void reset_vars();
void start_it(string str);
void do_timer();
void second();
void last();
int do_bid(string str);
void help();
void fix();

int cmd_auction(string str) {

  object tp=this_player();
  
  if(!str || (str == ""))
    return CHAT_D->do_chat("auction");

  if(thing) {
    message("system", "Something is already up for auction.\n"
                      "You will have to wait for the auction to end.", tp);
    return 1;
  }

  reset_vars();
  
  if(!(thing=present(str,tp))) {
    message("system", "You do not have that to auction!", tp);
    return 1;
  }
  
  if(thing->query_property("no auction")) {
    message("system", "You cannot auction that.", tp);
    return 1;
  }

  message("system", "You have chosen to put "+thing->query_short()+" up for auction.\n"
                    "Are you sure you want to do this? (y/n): ", tp);
  auctioner = tp;
  input_to("start_it");
  return 1;
}

void reset_vars() {
  thing = 0;
  auctioner = 0;
  bidder = 0;
  lastbid_amt = 0;
  lastbid_curr = "";
  minpriceset = 0;
  canbid = 0;
}

void start_it(string str) {
  object tp=auctioner;
  string stuff;

  switch (str) {
    
    case "n":
      reset_vars();
      break;

    case "y":
      thing->move(STORAGE_ROOM);
      if(strlen(stuff=thing->query_long_contents())) {
        CHAT_D->do_auction_line(capitalize(auctioner->query_name())+
          " has put "+thing->query_short()+" up for auction!");
        CHAT_D->do_auction_line(stuff);
      }
      else {
        CHAT_D->do_auction_line(capitalize(auctioner->query_name())+
          " has put "+thing->query_short()+" up for auction!");
      }
      canbid = 1;
      call_out("do_timer",30);
      break;

    default:
      message("system", "You have chosen to put "+thing->query_short()+" up for auction.\n"
                        "Are you sure you want to do this? (y/n): ", tp);
      input_to("start_it");
      break;
  }
  return;
}

void fix() {
  if (!auctioner || !interactive(auctioner)) {
    load_object(AUCTION_HOUSE)->store_item(auctioner, thing);
  }
  if (bidder) {
    if (!interactive(bidder)) {
      load_object(AUCTION_HOUSE)->store_money(bidder, lastbid_amt, lastbid_curr);
    }
    else {
      bidder->add_money(lastbid_curr, lastbid_amt);
    }
  }
  reset_vars();
}

void do_timer() {
  if (!auctioner) {
    fix();
    return;
  }
  CHAT_D->do_auction_line("There are 30 seconds left to bid on "+
    capitalize(auctioner->query_name())+"'s "+thing->query_short()+"!");
  call_out("second",25);
}

void second() {
  if (!auctioner) {
    fix();
    return;
  }
  CHAT_D->do_auction_line("There are only 5 seconds left to bid on "+
    capitalize(auctioner->query_name())+"'s "+thing->query_short()+"!");
  call_out("last",5);
}

void last() {
  if(!bidder || lastbid_amt == 0) {
    message("system","No one bid on your "+thing->query_short()+".",auctioner);
    CHAT_D->do_auction_line("No one bid on "+capitalize(auctioner->query_name())+"'s "+
      thing->query_short()+"!");
    
    if (interactive(auctioner)) {
      if (thing->move(auctioner)) {
        message("system","Your hands are too full and you drop it.",auctioner);
        thing->move(environment(auctioner));
      }
    }
    else
      load_object(AUCTION_HOUSE)->store_item(auctioner, thing);
  }
  
  else {
    CHAT_D->do_auction_line("SOLD!!!  To "+capitalize(bidder->query_name())+
      " for "+lastbid_amt+" "+lastbid_curr+"!");

    if(interactive(auctioner))
      auctioner->add_money(lastbid_curr, lastbid_amt);
    else
      load_object(AUCTION_HOUSE)->store_money(auctioner, lastbid_amt, lastbid_curr);
    
    if (auctioner == bidder) {
      if (interactive(auctioner)) {
        if (thing->move(auctioner)) {
          message("system","Your hands are too full and you drop it.",auctioner);
          thing->move(environment(auctioner));
        }
      }
    }
    else {
      load_object(AUCTION_HOUSE)->store_item(bidder, thing);
      message("system", "You can collect your winnings at the auction house in Tirun.", bidder);
    }
  }

  reset_vars();
}

int do_bid(string str) {
  string curr;
  int amnt, pos;
  float gold, lastbid_gold;
  object tp=this_player();
  
  if (!str || str == "") {
    message("system","Syntax: <bid [amount] [currency]>",tp);
    return 1;
  }
  
  if(sscanf(str, "%d %s", amnt, curr) != 2) {
    message("system","Syntax: <bid [amount] [currency]>",tp);
    return 1;
  }
  
  if(!thing || canbid == 0) {
    message("system","There is no item to bid on!",tp);
    return 1;
  }
  
  // HARD_CURRENCIES macro from /adm/include/money.h
  if ((pos=member_array(curr,HARD_CURRENCIES)) == -1) {
    message("system","Invalid currency.", tp);
    return 1;
  }
  
  if(!(tp->query_money(curr)) || (tp->query_money(curr) < amnt)) {
    message("system", "You do not have that much to bid!", tp);
    return 1;
  }
  
  if(amnt < 10) {
    message("system", "You cannot bid that low an amount!", tp);
    return 1;
  }

  gold = to_float(amnt)*AUC_CURR_RATES[pos];
  if (lastbid_amt)
    lastbid_gold = to_float(lastbid_amt)*AUC_CURR_RATES[member_array(lastbid_curr,HARD_CURRENCIES)];
  else
    lastbid_gold=0;
  
  if(lastbid_amt && gold <= lastbid_gold) {
    message("system", "You cannot bid less than what it is already going for!", tp);
    return 1;
  }

  if (tp == auctioner) {
    if (!minpriceset) minpriceset = 1;
    else {
      message("system","You have already set the minimum price.", tp);
      return 1;
    }
  }
  
  if (bidder)
    if (interactive(bidder))
      bidder->add_money(lastbid_curr, lastbid_amt);
    else
      load_object(AUCTION_HOUSE)->store_money(bidder, lastbid_amt, lastbid_curr);

  lastbid_amt = amnt;
  lastbid_curr = curr;
  bidder = tp;

  bidder->add_money(curr, -(amnt));
  
  CHAT_D->do_auction_line(capitalize(bidder->query_name())+" has bid "+
    lastbid_amt+" "+lastbid_curr+" on "+capitalize(auctioner->query_name())+"'s "+
    thing->query_short()+".");
  
  remove_call_out("do_timer");
  remove_call_out("second");
  remove_call_out("last");

  call_out("do_timer",30);
  

  return 1;
}

void help() {
  message("help",
    "Syntax: <auction [item]>\n"
    "Puts an item up for auction.\n"
    "See also: bid\n\n\n"
    "There are specific rules regarding the use of auction, "
    "be sure to read <help rules>.",
    this_player());
}

