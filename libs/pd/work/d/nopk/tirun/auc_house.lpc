#include <std.h>
#include <tirun.h>
#include <money.h>

#define AUCTION_STORAGE ROOMS"auc_storage"

inherit ROOM;

mapping money;
// money = ([
//   "somename" : ([
//     "silver" : 25,
//     "gold"   : 500
//   ])
// ])
mapping items;
// items = ([
//   "somename" : ({
//     object 1,
//     object 2
//   })
// ])

int do_query_status(string str);
int do_claim(string str);
int do_read(string str);
void store_money(object who, int amt, string curr);
void store_item(object who, object what);
string query_status();
string read_sign();

void init() {
  ::init();
  add_action("do_claim", "claim");
  add_action("do_read", "read");
  if (wizardp(this_player()))
    add_action("do_query_status","query");
}

void create() {
  ::create();
  set_properties((["light" : 2, "indoors" : 1]));
  set_short("Tirun Auction House");
  set_long(
    "Two columns of long wooden benches stretch across "
    "the width of the auction house. The ceiling is low, "
    "held up by many small beams along the sides of the "
    "room. At one end, a stage rises slightly above the "
    "floor. A podium sits towards the front of the stage, "
    "with a small sign on it."
  );
  set_items( ([
    "sign" : (: read_sign :)
  ]) );
  set_exits(([ "out" : ROOMS"wfallor1" ]));
  set_no_clean(1);

  money=([]);
  items=([]);
}

int do_query_status(string str) {
  message("system","Stored things:\n"+query_status(),this_player());
  return 1;
}

int do_claim(string str) {
  object tp=this_player();
  string name=tp->query_name();
  string stuff="";
  
  if (sizeof(money[name])) {
    foreach (string curr in keys(money[name])) {
      tp->add_money(curr, money[name][curr]);
      money[name][curr]=0;
    }
    stuff+="money";
  }
  
  if (sizeof(items[name])) {
    foreach (object what in items[name]) {
      if (what->move(tp)) {
        what->move(environment(tp));
      }
      items[name] -= ({what});
    }
    if (sizeof(stuff)) stuff+=" and ";
    stuff+="item"+(sizeof(items[name]) == 1?"":"s");
  }

  if (sizeof(stuff))
    message("system", "You claim your "+stuff+".",tp);
  else
    message("system", "There is nothing for you to claim.", tp);
  
  return 1;
}

int do_read(string str) {
  if (!str || str=="" || str != "sign")
    return 0;
  message("look",read_sign(),this_player());
  return 1;
}

void store_money(object who, int amt, string curr) {
  string name;
  if (member_array(curr,HARD_CURRENCIES) == -1) return;
  if (who) name=who->query_name();
  if (!money) money = ([]);
  if (!(money[name])) money[name] = ([]);
  if (!(money[name][curr])) money[name][curr] = 0;
  money[name][curr] += amt;
}

void store_item(object who, object what) {
  string name;
  if (who) name=who->query_name();
  if (!items) items= ([]);
  if (!(items[name])) items[name] = ({});
  if (what->move(AUCTION_STORAGE)) {
    error("Problem moving "+identify(what)+" to auction storage room.");
    return;
  }
  items[name] += ({what});
}

string query_status() {
  string ret="", tmp="";
  
  ret+="Money\n=====";
  foreach (string who in keys(money)) {
    ret+= "\n"+who+": ";
    foreach (string curr in money[who]) {
      tmp+=(tmp?", ":"")+(string)(money[who][curr])+" "+curr;
    }
    ret+= tmp;
    tmp="";
  }
  tmp="";
  ret+="\n\nItems\n=====";
  foreach (string who in keys(items)) {
    ret+= "\n"+who+": ";
    foreach (object what in items[who]) {
      tmp+=(tmp?", ":"")+identify(items[who]);
    }
    ret+=tmp;
    tmp="";
  }
  return ret;
}

string read_sign() {
  return
    "Here you may <claim> your items from auction.\n"
    "If you disconnected during the auction and lost "
    "money or the item, this will also replace what "
    "you lost.";
}
