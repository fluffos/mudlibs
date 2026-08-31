#include <std.h>

#define FAIL(s) return notify_fail(s);

#define COL "%^BOLD%^%^WHITE%^"
#define RES "%^RESET%^"

inherit DAEMON;

int item_value(object item);

int abil() {
  object tp=this_player();
  if (tp->query_subclass() == "gypsy" &&
      tp->query_skill("bargaining") >= 32*5 &&
      tp->query_skill("perception") >= 100)
        return 1;
  return 0;
}

string type() { return "deception"; }

void help() {
  message("help",
    "Syntax: <barter [your item] for [his item] with [who]>\n\n"
    "This is a fast talking ability where the user trades one of "
    "his own items for an item someone else is carrying. Many things "
    "determine how valuable items are, and the user's ability to "
    "bargain and influence others is very important.",
    this_player() );
}

int can_cast(object tp, object tgt, object mine, object yours) {
  object env;
  
  if (!tp) return 0;

  env = environment(tp);

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");
  
  if (!tgt)
    FAIL("Barter with whom?\n");
  
  if (!living(tgt))
    FAIL("That's not alive, so you can probably just, uh, take it.\n");

  if (sizeof(tgt->query_attackers()))
    FAIL(tgt->query_subjective()+" is too busy fighting.\n");
  
  if (sizeof(tp->query_attackers()))
    FAIL("You are too busy fighting.\n");
  
  if (tgt == tp)
    FAIL("You manage to convince yourself to give you your own item.\n");

  if (!mine)
    FAIL("You do not have that to barter.\n");

  if (!yours)
    FAIL(tgt->query_subjective()+" does not have that.\n");

  if (userp(tgt))
    FAIL("You can't use this on players... just ask "+tgt->query_objective()+".\n");
  
  return 1;
}

int cmd_barter(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  object mine, yours;
  int amt;
  string a, b, c;

  if (!abil())
    return 0;

  if (str && sscanf(str, "%s for %s with %s", a, b, c) == 3) {
    tgt = present(c, env);
    mine = present(a, tp);
    if (tgt)
      yours = present(b, tgt);
  }

  if (!can_cast(tp, tgt, mine, yours))
    return 0;

  if (tp->query_sp() < 20)
    FAIL("You're just too tired to barter right now.\n");
  
  amt = 0;
  amt -= item_value(yours);
  amt += item_value(mine);
  amt -= tgt->query_skill("perception");
  amt -= tgt->query_skill("bargaining");
  amt -= tgt->query_stats("intelligence")/2;
  amt -= tgt->query_stats("wisdom")/2;
  amt += tp->query_skill("perception")/2;
  amt += tp->query_skill("bargaining");
  amt += tp->query_skill("clairvoyance")/3;
  amt += tp->query_stats("charisma")*2/3;

  amt = amt + random(7) - random(7);
  
  tp->add_sp(-(20+random(10)));
  tp->set_paralyzed(4, "You are busy bartering.", "");
  call_out("do_barter", 4, ({tp, tgt, mine, yours, amt}) );

  message("info", "You try to barter your "+mine->query_name()+" for "+
                  tgt->query_cap_name()+"'s "+yours->query_name()+".", tp);
  message("info", tp->query_cap_name()+" tries to barter with "+
                  tgt->query_cap_name()+".", env, tp);

  return 1;
}

int item_value(object item) {
  int amt=0;
  
  if (!item) return 0;

  if (sizeof(item->query_curr_value()))
    amt += item->query_curr_value()["gold"]*2;
  amt += 50 - item->query_weight();
  if (item->is_armour())
    amt += 20+item->query_ac()*3/2;
  if (item->is_weapon()) {
    amt += 20+item->query_wc()*3/2;
    if (functionp(item->query_hit()))
      amt+=20;
  }
  if (item->is_bag())
    amt += item->query_max_internal_encumbrance()/90;
  if (item->query_auto_load()) amt += 15;
  if (sizeof(item->query_property("magic item"))) amt += 15;
  if (function_exists("heart_beat",item,1) != 0) amt += 15;
  if (item->query_enchanted()) amt += 10;
  if (item->give() || item->drop()) amt -= 50;
  if (item->query_property("no auction")) amt -= 25;
  if (item->query_strength()) amt += item->query_strength();

  return amt;
}

void do_barter(mixed *args) {

  object tp=args[0];
  object tgt=args[1];
  object mine=args[2];
  object yours=args[3];
  int amt=args[4];

  if (!tp || !tgt) return;

  if (!mine) {
    message("info", "You can't find the item you were bartering with.", tp);
    return;
  }
  
  if (!yours) {
    message("info", tgt->query_cap_name()+" seems to have lost "
                    "the item you wanted.", tp);
    return;
  }

  if (environment(tgt) != environment(tp)) {
    message("info", COL+tgt->query_subjective()+" seems to be uninterested."+RES, tp);
    return;
  }

  if (amt < -30 && tgt->query_alignment() <= 500 && !(mine->move(tgt)))
    message("info", COL+tgt->query_cap_name()+" agrees and takes your "+
                    mine->query_name()+", then refuses to hand over the "+
                    yours->query_name()+".", tp);
  else if (amt < -5)
    message("info", COL+tgt->query_cap_name()+" seems to be uninterested."+RES, tp);
  else if (amt < 20)
    message("info", COL+tgt->query_cap_name()+" looks interested in your "+
                    mine->query_name()+" but doesn't want to trade.", tp);
  else {
    if (mine->move(tgt))
      message("info", COL+tgt->query_cap_name()+" wants to trade, but "+
                      tgt->query_subjective()+" can't carry your "+
                      mine->query_name()+".", tp);
    else {
      message("info", COL+tgt->query_cap_name()+" agrees to the trade.", tp);
      if (yours->move(tp)) {
        yours->move(environment(tp));
        message("info", "The "+yours->query_name()+" is too heavy for you "
                        "to carry, and you drop it.", tp);
        message("info", tp->query_cap_name()+" drops "+yours->query_name()+".",
                        environment(tp), tp);
      }
    }
  }

}
