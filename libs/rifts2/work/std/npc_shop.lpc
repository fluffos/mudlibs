//    A generic npc shopkeeper, used in both npc owned shops and pc owned shops.  Can be set to save
//    his inventory over reboots or not.  Note that if he saves his inventory, the stroage room
//    must inherit locker_room.c rather than room.c, and it must contain storage lockers, i.e.,
//    items that inherit locker.c and return 1 for query_stroage_locker().  If it is a pc
//    owned shop, it is most likely desirable that money be saved over reboots as well, and
//    the storage room must conatin at least one /std/safe.c for this to occur.
//    DarkeLIB 0.1
//    -Diewarzau 8/2/95

#include <std.h>
#include <move.h>
#include <daemons.h>
#define CURRS ({ "gold", "silver", "copper" })

inherit MONSTER;

void close_all_lockers();
object *obj_inventory();
varargs void say_this(string str, object whom);
void buy_item(string str, object who);
void sell_item(string str, object who);
object *search_inv(string str);
void show_me(string str, object who);
string *inventory(object cust);
void appraise_obj(string str, object who);
void offer_me(string arg, object who);
object empty_locker();
int add_money(string type, int amt);
mixed *money_val(object ob);
nomask void die();

mixed *money_val(object ob) {
  float val;
  int i, equiv;

  if(!ob) return ({ 0, "gold" });
  val = (float)ob->query_float_value();
  if(!val || val <= 0.0) return ({ 0, "gold" });
  for(i=0;i<sizeof(CURRS);i++) {
    equiv = to_int(val * currency_rate(CURRS[i]));
    if(equiv <= 4) continue;
    return ({ equiv, CURRS[i] });
  }
  return ({ equiv, "copper" });
}

void create() {
  ::create();
    set_name("shopkeeper");
    set_id( ({ "shopkeeper", "keeper" }) );
    set_short("A shopkeeper");
    set("markup", 0);
    set_long("The shopkeeper is who you need to talk to if you want to buy or sell stuff." +
	     "  He looks like he wants to help you.  Try asking him for help with "+
	     "say shopkeeper, help");
    set_level(10);
    set_property("melee damage", ([ "crushing" : 55 ]));

    set_lang_prof("common", 10);
    set("no clean up", 1);
    call_out("load_store", 2);
    return;
}

void load_store() {
  if(stringp(query("storage room")))
    call_other(query("storage room"), "???");
  return;
}

void init() {
  string *exits;
  int i;
  object env;

  ::init();
  if(!environment()) return;
  env = environment();
  exits = env->query_exits();
  i = sizeof(exits);
  while(i--) {
if((string)env->query_exit(exits[i]) && query("storage room"))
    if(replace_string((string)env->query_exit(exits[i]), "/", "") ==
      replace_string(query("storage room"), "/", ""))
      add_action("block_exit", exits[i]);
  }
  return;
}

int block_exit(string null) {
  if(this_player()->query_invis() && !this_object()->query("see invis"))
    return 0;
  if(skill_contest((int)this_player()->query_stealth(), query_skill("perception")+10, 1)
    == 1) return 0;
  write("The Shopkeeper blocks your way.");
  return 1;
}

int query_num_rounds() {
  if(!query("num rounds")) return 2;
  else return query("num rounds");
}

object empty_locker() {
  object room, *inv;
  int i;

  if(!query("save items")) return 0;
  room = load_object((string)query("storage room"));
  if(!room) return 0;
  inv = filter_array(all_inventory(room), "storage_filter", this_object());
  i = sizeof(inv);
  while(i--) {
    if(inv[i]->query_closed()) inv[i]->toggle_closed();
    if(inv[i]->receive_objects()) return inv[i];
    else inv[i]->toggle_closed();
  }
  return 0;
}

varargs void say_this(string str, object whom) {
  string your_lang;

  if(objectp(whom))
    your_lang = (string)whom->query_primary_lang();
  if(your_lang && stringp(your_lang) && (int)this_object()->query_lang_prof(your_lang)
     >= 8) force_me("speak "+your_lang);
  else force_me("speak common");
  force_me("say "+str);
  return;
}

void catch_tell(string str) {
  string who, lang, cmd, what;
  object cust;
  int i;

  if(sscanf(str, "%*s says something in %s.", lang) == 2 && random(2)) {
    say_this("I don't understand "+lang+".");
    return;
  }
}

void directed_message(object cust, string cmd) {
  string who, what;

  if(cust && (environment(cust) != environment(this_object()))) return;
  who = (string)cust->query_cap_name();
  if(sscanf(cmd, "buy %s", what)) {
    buy_item(what, cust);
    return;
  }
  if(sscanf(cmd, "sell %s", what)) {
    sell_item(what, cust);
    return;
  }
  if(cmd == "list") {
    say_this("Okay, "+who+", here's what I got...", cust);
    message("other_action", (string)this_object()->query_cap_name()+ " hands "+
	    who+" a list of the shop's inventory",
	    all_inventory(environment()), ({ this_object(), cust }));
    message("info", (string)this_object()->query_cap_name() +
	    " hands you a list of the shop's inventory.  It reads:\n"+
"---------------------------------------------------------------------\n", cust);
	  cust->more(inventory(cust));
    return;
  }
  if(sscanf(cmd, "show me %s", what)) {
    // show_me(what, cust);
    return;
  }
  if(cmd == "help") {
    say_this("If you wanna buy something, say shopkeeper, offer <amt> gold, <amt> platinum, etc. for <item>", cust);
    say_this("You can also use the item number for <item>.", cust);
   if(!query("no sell"))
    say_this("If you wanna sell something, say shopkeeper, sell <item>", cust);
    say_this("If you want a list of my inventory, say shopkeeper, list", cust);
    // say_this("If you want to see one of my items, say shopkeeper, show me <item>", cust);
   if(!query("no sell"))
    say_this("If you want me to appraise an item of yours, say shopkeeper, appraise <item>", cust);
    say_this("That do it for ya?", cust);
    return;
  }
  if(sscanf(cmd, "appraise %s", what)) {
    appraise_obj(what, cust);
    return;
  }
  if(sscanf(cmd, "offer %s", what)) {
    offer_me(what, cust);
    return;
  }
  return;
}

int add_money(string type, int amt) {
  object safe, room;

  if(type != "gold") {
    amt = to_int(to_float(amt) * currency_rate("gold") / currency_rate(type));
    type = "gold";
  }
  if(!query("save items")) {
    ::add_money(type, amt);
    return 1;
  }
  if(!(room = load_object((string)query("storage room")))) return 0;
  safe = first_inventory(room);
  if(!safe) return 0;
  while(safe && !safe->query_is_safe()) safe = next_inventory(safe);
  if(!safe) return 0;
  if(!safe->query_closed()) safe->toggle_closed();
  safe->add_money(type, amt);
  SAVE_ITEMS_D->update_lockers(room);
  return 1;
}

string *inventory(object cust) {
  object *inv;
  string *list, desc;
  int i, j, curr, k;
  mixed tmp;
  float val;

  inv = obj_inventory();
  list = ({ });
  i = 0;
  k = 1;
  while(i < sizeof(inv)) {
    desc = (string)inv[i]->query_short();
    val = (float)inv[i]->query_float_value();
    j= 0;
    while(i < sizeof(inv) && (string)inv[i]->query_short() == desc
	  && (float)inv[i]->query_float_value() == val) {
      i++;
      j++;
    }
    i--;
    if(i >= sizeof(inv)) continue;
    tmp = money_val(inv[i]);
    curr = tmp[0];
    if(query("markup"))
      curr += curr * (36 + (int)query("markup")) / 100;
    list += ({
	sprintf("%3d. %-40s (qty: %3d) %7d %-6s", k, arrange_string(desc, 40), j, curr,
		tmp[1]) });
	  k++;
	  i++;
  }
  close_all_lockers();
  return list;
}

int storage_filter(object ob) { return (int)ob->query_storage_locker(); }

object *search_inv(string str) {
  object *inv;
  string tmp, desc;
  int i, j, which, k;
  float val;

  inv = obj_inventory();
  if(sscanf(str, "%d", which)) {
    k = 1;
    i = 0;
    while(i < sizeof(inv)) {
    desc = (string)inv[i]->query_short();
    val = (float)inv[i]->query_float_value();
    j = 0;
    while(i < sizeof(inv) && (string)inv[i]->query_short() == desc
	    && (float)inv[i]->query_float_value() == val) {
	i++;
      }
      if(k == which) {
	if(query("save items")) return ({ environment(inv[i-1]), inv[i-1] });
	  else return ({ 0, inv[i-1] });
      }
	    k++;
    }
    return 0;
  }
  if(sscanf(str, "%s %d", tmp, which) != 2)
    which = 1;
  else
    str = tmp;
  i = 0;
  val = 0.0;
  desc = "";
  while(i < sizeof(inv)) {
    if(desc != (string)inv[i]->query_short()) j = 1;
    else
      j++;
    desc = (string)inv[i]->query_short();
    if(inv[i]->id(str) && which == j) {
      if(query("save items")) return ({ environment(inv[i]), inv[i] });
      else return ({ 0, inv[i] });
    }
    val = (float)inv[i]->query_float_value();
    while(i < sizeof(inv) && desc == (string)inv[i]->query_short() &&
	  val == (float)inv[i]->query_float_value()) {
      if(inv[i]->id(str)) {
	if(query("save items")) return ({ environment(inv[i]), inv[i] });
	else return ({ 0, inv[i] });
      }
      i++;
    }
  }
  return 0;
}

void close_all_lockers() {
  object *lockers, room;
  int i;

  if(!query("save items")) return;
  room = load_object((string)query("storage room"));
  if(!room) return;
  lockers = filter_array(all_inventory(room), "storage_filter",
			 this_object());
  i = sizeof(lockers);
  while(i--)
    if(!lockers[i]->query_closed()) lockers[i]->toggle_closed();
  return;
}

object safe_ob() {
  object safe, room;

  if(!query("save money")) return this_object();
  if(!(room = load_object((string)query("storage room")))) return 0;
  safe = first_inventory(room);
  if(!safe) return 0;
  while(safe && !safe->query_is_safe()) safe = next_inventory(safe);
  if(!safe) return 0;
  return safe;
}

int sort_monies(string first, string second) {
  int f_flag, s_flag;

  if(member_array(first, (string *)ECONOMY_D->__QueryCurrencies()) < 0) f_flag = 1;
  if(member_array(second, (string *)ECONOMY_D->__QueryCurrencies()) < 0) s_flag = 1;
  if(s_flag && f_flag) return 0;
  if(s_flag) return 1;
  if(f_flag) return -1;
  return ((float)ECONOMY_D->__Query(first, "rate") < (float)ECONOMY_D->
	  __Query(second, "rate"));
}

object *obj_inventory() {
  object room, *lockers, *inv;
  int i;

  room = load_object((string)query("storage room"));
  if(!room) return ({ });
  if(!query("save items"))
    return sort_array(all_inventory(room), "sort_inv", this_object());
  else {
    lockers = filter_array(all_inventory(room), "storage_filter",
			   this_object());
    i = sizeof(lockers);
    inv = ({ });
    while(i--) {
      if(lockers[i]->query_closed()) lockers[i]->toggle_closed();
      inv += all_inventory(lockers[i]);
    }
    return sort_array(inv, "sort_inv", this_object());
  }
}

int sort_inv(object one, object two) {
  string sh_one, sh_two;
  float val_one, val_two;

  if(!one->query_short() && !two->query_short()) return 0;
  else if(!one->query_short()) return -1;
  else if(!two->query_short()) return 1;
  else {
    sh_one = (string)one->query_short();
    sh_two = (string)two->query_short();
    if(sh_one != sh_two) return strcmp(sh_one, sh_two);
    val_one = (float)one->query_float_value();
    val_two = (float)two->query_float_value();
    if(val_one == val_two) return 0;
    return (val_one > val_two)?1:-1;
  }
}

int sell_all_filter(object item) {
  function pre_sell;

  if(item->drop()) return 0;
  if(functionp(pre_sell = query("pre sell function")))
    if((*pre_sell)(item)) return 0;
  if(!item->query_float_value() || (float)item->query_float_value() <= 0.0)
    return 0;
  return 1;
}

void sell_item(string str, object who) {
  object ob, where, *inv;
  int amt, i;
  string tmp;
  mixed *mtmp;
  function pre_sell;

  if(query("no sell")) return;
  if(str == "all") {
    inv = filter_array(all_inventory(who), "sell_all_filter", this_object(),
	who);
    if(!inv || !sizeof(inv)) {
      say_this("You don't have anyting to sell, "+(string)who->query_cap_name()+".",
	who);
      return;
    }
    i = sizeof(inv);
    while(i--) {
     if(inv[i]->query_property("KEEP"))
	continue;
      mtmp = money_val(inv[i]);
      amt = mtmp[0];
      if(!amt) continue;
      amt += amt * ((int)who->query_skill("trade lore") - random(36)) / 100;
      if((int)safe_ob()->query_money("gold") <
        to_int(to_float(amt) * currency_rate("gold") / currency_rate(mtmp[1]))) {
	say_this("Sorry, I don't have enough money to give you for "+
	  (string)inv[i]->query_short() + ".",
		who);
	continue;
      }
      add_money(mtmp[1], -amt);
      who->add_money(mtmp[1], amt);
      message("info", "You sell "+(string)inv[i]->query_short()+".", who);
      message("info", (string)who->query_cap_name() + " sells "+
		(string)inv[i]->query_short()+".", all_inventory(environment()),
		({ this_object() , who }));
      if(where = empty_locker())
	inv[i]->move(where);
      else inv[i]->move(load_object((string)query("storage room")));
    }
    close_all_lockers();
    say_this("Thanks very much for your sale, "+
	      (string)who->query_cap_name()+".", who);
	  return;
  }
  ob = present(str, who);
  if(!ob) {
    say_this("Hey, you don't have a "+str+"!  What are you trying to pull?!", who);
    return;
  }
  if(!safe_ob()) {
    say_this("I don't have any money to give you for it!", who);
    return;
  }
  if(functionp(pre_sell = query("pre sell function"))) {
    if(stringp((*pre_sell)(ob))) {
      say_this((string)(*pre_sell)(ob));
      return;
    }
  }
  mtmp = money_val(ob);
  amt = mtmp[0];
  if(!amt || ob->drop()) {
    say_this("That isn't worth a thing!", who);
    return;
  }
  amt += amt * ((int)who->query_skill("trade lore") - random(36)) / 100;
  if((int)safe_ob()->query_money("gold") <
    to_int(to_float(amt) * currency_rate("gold") / currency_rate(mtmp[1]))) {
    say_this("Sorry, I don't have enough money to give you for that.",
	     who);
    return;
  }
  add_money(mtmp[1], -amt);
  who->add_money(mtmp[1], amt);
  message("info", (string)who->query_cap_name() + " sells "+
	(string)ob->query_short()+".", all_inventory(environment()),
	({ this_object() , who }));
  if(where = empty_locker())
    ob->move(where);
  else ob->move(load_object((string)query("storage room")));
  close_all_lockers();
  say_this("Thanks very much for your sale, "+
	   (string)who->query_cap_name()+".", who);
  return;
}

void buy_item(string what, object who) {
  object room, ob, *search;
  int gold_equiv;

  search = search_inv(what);
  if(!search) {
    say_this("Sorry, I don't have a "+what+"!", who);
    return;
  }
  if(!pointerp(search) || sizeof(search) != 2) {
    say_this("Oops!  There's a BUG in my storage room!", who);
    return;
  }
  if(!objectp(search[1])) {
    say_this("I don't have a "+what+".", who);
    return;
  }
  gold_equiv = to_int((float)search[1]->query_float_value() * (float)
		      ECONOMY_D->__Query("gold", "rate"));
  gold_equiv += (query("markup") * gold_equiv) / 100;
  say_this(sprintf("That looks like it's worth about %d gold.",
		   gold_equiv), who);
  say_this("Make an offer by typing, 'say shopkeeper, offer 60 gold, "+
	   "30 copper, and 10 platinum for <what>'", who);
  close_all_lockers();
  return;
}

void appraise_obj(string what, object who) {
  object ob;
  mixed *tmp;
  int gold_equiv;

  ob = present(what, who);
  if(!ob) {
    say_this("You don't have a "+what+"!", who);
    return;
  }
  tmp = money_val(ob);
  gold_equiv = tmp[0];
  gold_equiv += ((int)who->query_skill("trade lore") - random(36)) * gold_equiv / 100;
  if(gold_equiv > 0)
    say_this("That looks like it's worth about "+gold_equiv+" "+tmp[1]+".",
	   who);
  else {
    say_this("That isn't worth a thing.",
	     who);
  }
  return;
}

void offer_me(string arg, object who) {
  float offer_val, item_val;
  int i, tmp;
  string *vals, what, what2, tmp_str1, tmp_str2;
  object *tmp_ob, ob;
  mapping trans_money;

  if(sscanf(arg, "%s for %s", what, what2) != 2) {
    say_this("What item are you offering me money for?", who);
    return;
  }
  tmp_ob = search_inv(what2);
  if(!tmp_ob) {
    say_this("I don't have a "+what2+".", who);
    return;
  }
  if(!pointerp(tmp_ob) || sizeof(tmp_ob) != 2) {
    say_this("Uh, there is a bug in one of the storage lockers.", who);
    return;
  }
  ob = tmp_ob[1];
  if(!objectp(ob)) {
    say_this("Oops, there is a bug with the object you requested.", who);
    return;
  }
  vals = explode(what,",");
  i = sizeof(vals);
  if(i >= 1 && sscanf(vals[i-1], "%s and %s", tmp_str1, tmp_str2) == 2) {
    vals[i-1] = tmp_str1;
    vals += ({ tmp_str2 });
    i++;
  }
  what = "";
  trans_money = ([]);
  offer_val = 0.0;
  while(i--) {
    if(!strlen(vals[i])) continue;
    while(strlen(vals[i]) && vals[i][0] == ' ')
      vals[i] = replace_string(vals[i], " ", "", 1);
    while((tmp = strlen(vals[i]) - 2) >= 0 && vals[i][tmp+1] == ' ')
      vals[i] = vals[i][0..tmp];
    if(sscanf(vals[i], "%d %s", tmp, what) != 2 &&
	sscanf(vals[i], "and %d %s", tmp, what) != 2) {
      say_this("I don't understand what you are trying to offer me.", who);
      say_this("The format is: say shopkeeper, offer 10 gold, 20 platinum, and "+
	       "45 copper for <item>", who);
      return;
    }
    if(member_array(what, (string *)ECONOMY_D->__QueryCurrencies()) < 0) continue;
    if(tmp > (int)who->query_money(what)) {
      say_this("You don't have "+tmp+" '"+what+"'.  Nice try.", who);
      return;
    }
    offer_val += to_float(tmp) / (float)ECONOMY_D->__Query(what, "rate");
    trans_money[what] = tmp;
  }
  item_val = (float)ob->query_float_value();
  item_val += (item_val * to_float(query("markup"))) / 100.0;
  item_val -= (to_float(((int)who->query_skill("trade lore") - random(36)) / 2) * item_val) / 100.0;
  if(item_val > offer_val) {
    say_this("Sorry, "+(string)who->query_cap_name()+
	     ", you're gonna have to do better than that.", who);
    return;
  }
  vals = keys(trans_money);
  i = sizeof(vals);
  while(i--) {
    who->add_money(vals[i], -1 * trans_money[vals[i]]);
    add_money(vals[i], trans_money[vals[i]]);
  }
  say_this("Here you go, "+(string)who->query_cap_name()+".");
  message("info", (string)who->query_cap_name()+" buys "+
	  (string)ob->query_short()+".", all_inventory(environment()),
	  ({ who, this_object() }));
  if((int)ob->move(who) != MOVE_OK) {
    message("info", "You cannot take the item, and it falls on the ground.",
		who);
    message("info", (string)who->query_cap_name()+" cannot carry it, and "+
	nominative(who) + " drops it.", environment(who),
		({ who }) );
    ob->move(environment(who));
  }
  close_all_lockers();
  return;
}

nomask void die()
{
int i;
string *currs;
  currs = query_currencies();
    for(i=0;i < sizeof(currs); i++) {
	add_money(currs[i], -query_money(currs[i]));
    }
::die();
}
















