/*
 *      /std/vendor.c
 *      from the Nightmare Mudlib
 *      a standard object that sells things in shops
 *      created by Descartes of Borg 921024
 *      rewritten by Descartes 931108
 *      minor change by Bohemund 940403
 */

#include <std.h>
#include <money.h>

#define MAX_ITEMS 75

inherit MONSTER;

private mapping __Eco, __Values, __Costs, __Discriminate;
private string *__ItemTypes;

protected  int __CheckDiscrimination();
protected  int __SellAll();
protected  int convert(int x);
string *query_item_types();
protected  int cost_bargaining(object who, int x);
protected  int value_bargaining(object who, int x);
protected  int __AlreadyThere(object ob);

void init() {
  ::init();
    add_action("__Buy", "buy");
    add_action("__Sell", "sell");
    add_action("__Show", "show");
    add_action("__List", "list");
    add_action("__Value", "value");
    add_action("__Cost", "cost");
}

void create() {
  ::create();
    __Eco = ([]);
    __Values = ([]);
    __Costs = ([]);
    __Discriminate = ([]);
    __ItemTypes = ({ "weapon" });
}

int __Buy(string str) {
  object ob;
  string tmp;
  int worth, val, x;

  if(!__Eco["storage object"])
    __Eco["storage object"] = load_object(__Eco["storage file"]);
  if(!(x = __CheckDiscrimination())) return 1;
  if(!str) {
    this_object()->force_me("speak Buy what?");
    return 1;
  }
  if(!(ob = present(str, __Eco["storage object"])) &&
     !(ob = parse_objects(__Eco["storage object"]))) {
    this_object()->force_me("speak I have nothing like that to sell.");
    return 1;
  }
  if(__Costs[tmp = (string)this_player()->query_name()])
    worth = __Costs[tmp][ob];
  if(!worth) {
    if(!(worth = (int)ob->query("value"))) worth = 1;
    if(worth > (val = cost_bargaining(this_player(), worth))) val = worth;
    val = convert(val);
  }
  else {
    map_delete(__Costs[tmp], ob);
    if(!__Costs[tmp] || !sizeof(__Costs[tmp])) map_delete(__Costs, tmp);
    val = worth;
  }
  if((int)this_player()->query_money(__Eco["currency"]) < val) {
    this_object()->force_me("speak "+(string)this_player()->query_cap_name()+
			    ", you are too poor for that!");
    return 1;
  }
  this_object()->force_me("speak Here is your "+str+" for "+val+" "+
			  __Eco["currency"]+"!");
  message("other_action", query_cap_name()+" hands "+
	  (string)this_player()->query_cap_name()+" "+
	  (string)ob->query_short()+".",
	  environment(this_object()), ({ this_player(), this_object() }));
  message("other_action", query_cap_name()+" hands you "+
	  (string)ob->query_short()+".", this_player());
  this_player()->add_money(__Eco["currency"], -val);
  if(ob->move(this_player())) {
    message("my_action", "You drop it as fast as you get it!", this_player());
    message("other_action", (string)this_player()->query_cap_name()+
	    " drops "+(string)ob->query_short()+".",
	    environment(this_object()), ({ this_player() }));
    ob->move(environment(this_object()));
  }
  return 1;
}

int __Sell(string str) {
  object ob;
  string tmp;
  int worth, val, x;

  if(!(x = __CheckDiscrimination())) return 1;
  if(!str) {
    this_object()->force_me("speak Sell what?");
    return 1;
  }
  if(!__Eco["storage object"])
    __Eco["storage object"] = load_object(__Eco["storage file"]);
  if(sizeof(all_inventory(__Eco["storage object"])) >= MAX_ITEMS) {
    this_object()->force_me("speak I cannot get rid of what I have "
			    "to sell right now!");
    return 1;
  }
  if(str == "all") return __SellAll();
  if(!(ob = present(str, this_player()))) {
    this_object()->force_me("speak You do not have that to sell!");
    return 1;
  }
  if(member_array((string)ob->query_vendor_type(), query_item_types()) == -1) {
    /* the following code is to allow for the selling of items
       with the "magic item" property */
    if(!(ob->query_property("magic item") &&
	 member_array("magic", query_item_types()) != -1)) {
      this_object()->force_me(sprintf("speak I do not buy %s goods.",
				      (string)ob->query_vendor_type()));
      return 1;
    }
  }
  if(__Values[tmp = (string)this_player()->query_name()])
    worth = __Values[tmp][ob];
  if(!worth) {
    if(!(worth = (int)ob->query("value"))) {
      this_object()->force_me("speak That thing is worthless.");
      return 1;
    }
    if(worth < (val = value_bargaining(this_player(), worth))) val = worth;
    if(val > 2000) {
      this_object()->force_me("speak I am low on money.");
      val = 1000 + random(1000);
    }
    val = convert(val);
  }
  else {
    val = worth;
    map_delete(__Values[tmp], ob);
    if(!__Values[tmp] || !sizeof(__Values[tmp]))
      map_delete(__Values, tmp);
  }
  this_player()->add_money(__Eco["currency"], val);
  this_player()->add_skill_points("bargaining",
				  random(query_skill("bargaining")));
  message("other_action", (string)this_player()->query_cap_name()+
	  " sells "+(string)ob->query_short()+".", environment(this_object()),
	  ({ this_player() }));
  message("my_action", "You sell "+(string)ob->query_short()+" for "+
	  val + " " + __Eco["currency"]+".", this_player());
  if(ob->query_destroy()) ob->remove();
  else if(__AlreadyThere(ob)) ob->remove();
  else {
    ob->move(__Eco["storage object"]);
    return 1;
  }
  if(ob) destruct(ob);
  return 1;
}

int __Show(string str) {
  object ob;

  if(!__CheckDiscrimination()) return 1;
  if(!str) {
    this_object()->force_me("Show you what?");
    return 1;
  }
  if(!__Eco["storage object"])
    __Eco["storage object"] = load_object(__Eco["storage file"]);
  if(!(ob = present(str, __Eco["storage object"])) &&
     !(ob = parse_objects(__Eco["storage object"]))) {
    this_object()->force_me("speak I do not have that here to show you.");
    return 1;
  }
  message("other_action", query_cap_name()+" shows you "+
	  (string)ob->query_short()+".", this_player());
  message("info", (string)ob->query_long(), this_player());
  return 1;
}

int __List(string str) {
  object *inv;
  string *tmp;
  int i, x;

  if(!__CheckDiscrimination()) return 1;
  if(!__Eco["storage object"]) {
    this_object()->force_me("speak I have nothing to sell right now.");
    return 1;
  }
  i = sizeof(inv = filter_array(all_inventory(__Eco["storage object"]),
				"filter_list", this_object(), str));
  if(!i) {
    this_object()->force_me("speak I have nothing like that to sell.");
    return 1;
  }
  message("info", arrange_string("Item", 55) +
	  "approximate value", this_player());
  message("info", "_________________________________________________"
	  "________________________", this_player());
  for(x=0, tmp = ({}); x<i; x++)
    tmp += ({ arrange_string((string)inv[x]->query_short(), 55) +
		"%^RESET%^"+convert((int)inv[x]->query("value"))+ " "+
		  __Eco["currency"] });
  this_player()->more(tmp);
  return 1;
}

int __Value(string str) {
  object ob;
  string tmp, cn;
  int worth, val;

  if(!__CheckDiscrimination()) return 1;
  if(!str) {
    this_object()->force_me("speak The value of what?");
    return 1;
  }
  if(!(ob = present(str, this_player()))) {
    if(!(ob = parse_objects(this_player(), str))) {
      this_object()->force_me("speak You don't have that!");
      return 1;
    }
  }
  message("other_action", (cn=(string)this_player()->query_cap_name())+
	  " asks for an appraisal.", environment(this_object()),
	  ({this_object(),this_player()}));
  if(__Values[tmp=(string)this_player()->query_name()] &&
     __Values[tmp][ob]) {
    this_object()->force_me("speak You have my offer!");
    return 1;
  }
  if(!(worth = (int)ob->query("value"))) {
    this_object()->force_me("speak That thing is worthless!");
    return 1;
  }
  if(worth < (val = value_bargaining(this_player(), worth))) val = worth;
  if(val > 2000) {
    this_object()->force_me("speak I am low on money.");
    val = 1000 + random(1000);
  }
  val = convert(val);
  if(!__Values[tmp]) __Values[tmp] = ([]);
  __Values[tmp][ob] = val;
  if(cn == "Someone") cn = "Invisible person";
  this_object()->force_me("speak "+cn+", I will offer you "+val+" "+
			  __Eco["currency"]+" for it.");
  return 1;
}

int __Cost(string str) {
  object ob;
  string cn, tmp;
  int val, worth;

  if(!__Eco["storage object"])
    __Eco["storage object"] = load_object(__Eco["storage file"]);
  if(!__CheckDiscrimination()) return 1;
  if(!str) {
    this_object()->force_me("speak The cost of what?");
    return 1;
  }
  if(!(ob = present(str, __Eco["storage object"])) &&
     !(ob = parse_objects(__Eco["storage object"], str))) {
    this_object()->force_me("speak I do not have any "+str+" to sell.");
    return 1;
  }
  message("other_action", (cn=(string)this_player()->query_cap_name())+
	  "asks about the cost of an item for sale.",
	  environment(this_object()), ({ this_object(), this_player() }));
  if(__Costs[tmp = (string)this_player()->query_name()] && __Costs[tmp][ob]) {
    this_object()->force_me("speak I will charge no less!");
    return 1;
  }
  if(!(worth = (int)ob->query("value"))) worth = 1;
  if(worth > (val = cost_bargaining(this_player(), worth))) val = worth;
  val = convert(val);
  if(!__Costs[tmp]) __Costs[tmp] = ([]);
  __Costs[tmp][ob] = val;
  if(cn == "Someone") cn == "Invisible person";
  this_object()->force_me("speak "+cn+", I will take "+val+" "+
			  __Eco["currency"]+" for it.");
  return 1;
}

int filter_list(object ob, string str) {
  if(!str || str == "") return 1;
  switch(str) {
  case "weapon": case "weapons": return (int)ob->is_weapon();
  case "armor": case "armour": case "armors": case "armours":
    return (int)ob->is_armour();
  case "bag": case "bags": return (int)ob->is_bag();
  case "other": return (!((int)ob->is_weapon()) &&
			!((int)ob->is_armour()));
  default:
    return ((string)ob->query_type() == str || ob->id(str));
  }
  return 0;  // just to be safe... Did I just comment some code?
             // i would have to say so... ;)
}

protected  int __SellAll() {
  object *inv;
  int i, worth, val, total;
  string tmp;

  total = 0;
  if(!(i = sizeof(inv = all_inventory(this_player())))) {
    this_object()->force_me("speak You have nothing to sell!");
    return 1;
  }
  while(i--) {
    if(!(worth = (int)inv[i]->query("value"))) {
      this_object()->force_me("speak "+(string)inv[i]->query_short()+
			      " is worthless.");
      continue;
    }
    if(member_array((string)inv[i]->query_vendor_type(),
		    query_item_types()) == -1) {
      this_object()->force_me(sprintf("speak %s is a %s item, and "
				      "I do not buy those.",
				      (string)inv[i]->query_short(),
				      (string)inv[i]->query_vendor_type()));
      continue;
    }
    if(worth < (val = value_bargaining(this_player(), worth))) val = worth;
    if(val > 2000) val= 1000 + random(1000);
    val = convert(val);
    total += val;
    this_player()->add_money(__Eco["currency"], val);
    message("my_action", "You sell "+(string)inv[i]->query_short()+".",
	    this_player());
    message("other_action", (string)this_player()->query_cap_name()+
	    " sells "+(string)inv[i]->query_short()+".",
	    environment(this_object()), ({ this_player() }));
    if(inv[i]->query_destroy()) inv[i]->remove();
    else if(__AlreadyThere(inv[i])) inv[i]->remove();
    else inv[i]->move(__Eco["storage object"]);
  }
  if(total)
    this_object()->force_me(sprintf("speak Your total comes to %d %s.",
				    total, __Eco["currency"]));
  /* Kalinash 1-14-94 */
  this_object()->force_me("speak Thank you for your business!");
  return 1;
}

protected  int cost_bargaining(object who, int x) {
  int val, vend, pl, cha;

  pl = (int)who->query_skill("bargaining");
  cha = (int)who->query_stats("bargaining");
  val = (2*x) + ((x*10)/100) + ((query_skill("bargaining")-cha)*x)/200;
  val -= (pl*x)/200;
  return val;
}

protected  int value_bargaining(object who, int x) {
  int val, pl, cha;

  pl = (int)who->query_skill("bargaining");
  cha = (int)who->query_stats("charisma");
  val = x + ((pl*x)/200) - ((query_skill("bargaining")-cha)*x)/200;
  return val;
}

protected  int __AlreadyThere(object ob) {
  object *inv;
  int i;

  if(!(i = sizeof(inv = all_inventory(__Eco["storage object"])))) return 0;
  while(i--)
    if((string)inv[i]->query_short() == (string)ob->query_short()) return 1;
  return 0;
}

protected  int __CheckDiscrimination() {
  int x, tmp, i;
  string *dis;

  if(__Discriminate["class"] &&
     member_array((string)this_player()->query_class(),
		  __Discriminate["class"]) == -1) {
    this_object()->force_me("speak I do not do business with people "
			    "like you.");
    return 0;
  }
  if(__Discriminate["race"] &&
     member_array((string)this_player()->query_class(),
		  __Discriminate["race"]) == -1) {
    this_object()->force_me("speak I do not do business with people "
			    "like you.");
    return 0;
  }
  if(__Discriminate["language"] && i = sizeof(__Discriminate["language"])) {
    while(i--)
      if(x < (tmp = (int)this_player()->query_lang_prof
	      (__Discriminate["language"][i]))) x = tmp;
    if(!x) {
      this_object()->force_me("speak I do not understand you.");
      return 0;
    }
    return x;
  }
  return 10;
}

protected  int convert(int x) {
  if(!x) return 0;
  return 1 + to_int(x * __Eco["exchange rate"]);
}

varargs void set_currency(string str, float wert) {
  int x;

  __Eco["currency"] = str;
  __Eco["exchange rate"] =currency_rate(str);
}

void set_discriminate(string who, string *which) {
  __Discriminate[who] = which;
}

void set_storage_room(string str) {
  __Eco["storage object"] =load_object(__Eco["storage file"] = str);
}

string query_currency() { return __Eco["currency"]; }

object query_storage_room() { return __Eco["storage object"]; }

void set_item_types(mixed val) {
  if(stringp(val)) val = ({ val });
  else if(!pointerp(val)) error("Bad argument 1 set_item_types().\n");
  __ItemTypes = val;
}

void add_item_type(string str) { __ItemTypes += ({ str }); }

string *query_item_types() { return __ItemTypes; }
