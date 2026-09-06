// A depot for the madmonks guild
// made by magictcs - 4 may 97
// a player can 'deposit' items here
// and another can get the items with the command 'withdraw'

// not used the "/obj/guild/storage" don't fit the needings!

// TODO: add an own store (see man guild) to build a shop which never forget
// the items

// replace shop by a chest?!?! would be a little bit nicer

#include <properties.h>
#include <moving.h>
#include "/p/guilds/madmonks/madmonks.h"

inherit "/std/shop";
inherit "/lib/string";

// remove the "a sign is .. counter."
string QueryIntLong(string what) {
  return
  "This is the depot of the madmonk's guild. Here you can store items\n"
  "for a small amount of money.\n"
  "An old paper hangs on a wall.\n";
}


/* not working :((
int PutInStore(object ob) {
write("check it\n");
  if (GetStore()->CheckList(ob)==0) return 0;
  return ::PutInStore(ob);
}
*/

create() {
  ::create();
  SetIntShort("The madmonks depot");

  AddDetail(({"depot","madmonks depot","madmonk's depot"}),#'IntLong);
  AddDetail(({"items","item"}),
    "Better use the command 'info'.\n");

  RemoveDetail("sign");            // kill the standard sign of shop
  RemoveReadMsg("sign");
  RemoveDetail("counter");         // and remove the counter too
  AddDetail(({"paper","old paper","paper on wall","paper on the wall",
    "old paper on wall","old paper on the wall"}),
    "It hangs on the west wall. It is old, but still readable.\n");
  AddDetail(({"wall","west wall","wall west","western wall","walls"}),
    "Made of the same brown paper as everywhere in the guild. An old\n"
    "paper hangs on the wall.\n");
  AddDetail("brown paper","All the walls consist of it.\n");
  AddReadMsg(({"paper","old paper"}),#'detail_sign);

  // shopkeeper:  
  SetShopkeeper(MONKNPC("nishimura"));

  RemoveDustbin();                       // no dustbin :)
  SetStore(MONKROOM("depotstore"));      // own (special) store
  SetIndoors(1);

  // change the verbs:
  SetSell("deposit");                     // sell==deposit
  SetBuy("withdraw");                     // buy==withdraw
  SetList("info");                        // list==info
  SetIdentify(0);                         // disabled!
  SetAppraise(0);                         // disabled!
  SetShow(0);                             // disabled!

  // change it later:
  AddExit("south",MONKROOM("madmonks"));
  RemoveExit("store");                    // remove the exit to store!
}

// no extra wizard message (which is disabled!)
string detail_sign() {
  string ret;
  ret= 
  "You can withdraw or deposit things here.\n"
  "Nishimura understands the following commands:\n"
  "info [<what>] ..... List (all/matching) items in the depot.\n"
  "                    Example: info, info armour\n"
  "deposit <what> .... Deposit items you have.\n"
  "                    Example: deposit all, deposit torches from bag\n"
  "withdraw <what> ... Get items from the depot.\n"
  "                    Example: withdraw sunglasses, withdraw 3, withdraw\n"
  "                    all torch\n";
  if (!present("nishimura"))
    ret+="But Nishimura isn't here yet.\n";
  return ret;
}

// disable the following functions 
int do_toss(string str) { return 0; }
int do_appraise(string str) { return 0; }
int do_identify(string str) { return 0; }
int do_show(string str) { return 0; }
int wiz_funcs(string str) { return 0; }

// shopkeeper functions:
// switch output from "sell" to "withdraw" and so on
string change_msg(string str) {
  string new;
  new=string_replace(str,"store","depot");
  new=string_replace(new,"all prices in copper","");
  new=string_replace(new,"sell","withdraw");
  new=string_replace(new,"buy","deposit");
  return new;
}

int SkSay(string str) {
//  dtell("magictcs","SAY-MSG: "+str);
  return ::SkSay(change_msg(str));
}

int SkWrite(string str) {
//  dtell("magictcs","Write-MSG: "+str);
  return ::SkWrite(change_msg(str));
}


int SkEmote(string str) {
//  dtell("magictcs","Write-MSG: "+str);
  return ::SkEmote(change_msg(str));
}


// forbid entering for all non guild member:
int allow_enter (int method, mixed extra) {
  if (interactive(PO)) {
    if (PO->QueryGuild() == GC_MADMONKS) return ME_OK;
    else {
      tell_object(PO,
        "You can't enter the depot of the madmonk's guild. You are no member\n"
        "of this guild!\n");
      return ME_NO_ENTER;
    }
  }
  tell_object(PO,
    "You can't enter the depot of the madmonk guild. You are no a member!\n");
  return ME_OK;
}

//************************
// shop specific function:
//************************
// it is not a real shop - it is a depot!
int ModifyPrice(object ob,int price,string verb) {
  return 0;             // for selling you will get nothing
  // but it costs ever 1 copper :((
}

// no weapons
// TODO: adding a no magic check?
status CheckTrade(object ob) {
  if (member(ob->QueryClassIds()||({}),"weapon")!=-1) {
    ::SkSay("This is a weapon.\n");
    ::SkEmote("grumbles.\n");
    return 0;
  }
  if (member(ob->QueryAds()||({}),"blessed")!=-1) {
    ::SkSay(
    "This is a blessed item. I don't want to touch it! Go away with it!\n");
    ::SkEmote("is very angry.\n");
    return 0;
  }
//  if (GetStore()->GetEqual(ob)!=({})) {
//    ::SkSay("I have already such an item in my depot.\n");
//    return 0;
//  }
  return 1;
}

