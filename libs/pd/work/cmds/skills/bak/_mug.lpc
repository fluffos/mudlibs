
#include <std.h>
#include <money.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n")

#define CURRENCIES ({"platinum","gold","electrum","silver","copper"})

#define MUG_PROP "mug_abil_check"

inherit DAEMON;

void make_outlaw(object tp, int t);
void retaliate(object tp, object tgt, int t);
void do_stealing(object tp, object tgt, object item);

int abil() {
  object tp=this_player();
  if (tp &&
      (tp->query_subclass() == "thug" ||
      tp->query_subclass() == "thief") &&
      tp->query_skill("stealing") >= 6*6)
        return 1;
  return 0;
}

string type() { return "deception"; }

void help() {
  message("help",
    "Syntax: <mug [whom] for [what]>\n"
    "        <mug [whom] for money>\n\n"
    "Some rogues prefer to use force, rather than finesse, "
    "to get what they want. This is the ability to grab an item "
    "right out of someone's hand, or even knock them over and take "
    "it, if needed. It can be much easier than trying to steal "
    "quietly, as long as you're stronger than your victim, "
    "but the chances of being identified (and brought to justice) "
    "are much higher as well.",
    this_player() );
}

int can_cast(object tp, object tgt, object item, string what) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no steal") ||
      tp->query_arena())
        FAIL("Some force prevents your mischief.");


  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You should look into getting a body first.");

  if (!tgt)
    FAIL("Mug whom for what?");

  if (!living(tgt))
    FAIL("That isn't alive.");

  if (tgt == tp)
    FAIL("That would be pretty stupid.");

  if (tp->query_current_attacker())
    FAIL("You're too busy fighting!");

  if (userp(tp) && userp(tgt)) {

    if (!interactive(tgt))
      FAIL("Some force prevents your mischief.");
    
    if (tp->query_level() < 20)
      FAIL("You are protected from PK, so "+tgt->query_subjective()+
           "is protected from your sticky fingers.");

    if (tgt->query_level() < 20)
      FAIL("You may not steal from newbies.");

    if (wizardp(tgt) && !wizardp(tp))
      FAIL("That is not advisable.");

  }

  if (tgt->query_property("no steal"))
    FAIL("You cannot steal from "+tgt->query_objective()+".");

  if (tgt->query(MUG_PROP))
    FAIL("You already mugged "+tgt->query_objective()+"!");

  if (what != "money" && what != "purse") {

    if (!item)
      FAIL(capitalize(tgt->query_subjective())+" does not have that.");

    else if (item->query_property("no steal") || !item->get())
      FAIL("You cannot steal that.");

  }
  
  return 1;
}

int cmd_mug(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  object item;
  int steal, resist;
  string name, what;
  int ret;

  if (!abil()) return 0;
  
  if (str) {
    if (sscanf(str, "%s for %s", name, what) == 2) {
      tgt = present(name, env);
      if (tgt && what != "money" && what != "purse")
        item = present(what, tgt);
    }
  }

  if (!can_cast(tp, tgt, item, what)) return 0;

  if (what == "money")
    what = "purse";

  if (tp->query_sp() < 25)
    FAIL("You're too tired.");

  steal = tp->query_skill("stealing")/2;
  steal += tp->query_skill("murder")/8;
  steal += tp->query_stats("strength")*6;
  steal += tp->query_stats("dexterity");
  steal += random(tp->query_level()/2);

  resist = tgt->query_skill("stealing")*2/7;
  resist += tgt->query_skill("perception")*4/7;
  resist += tgt->query_stats("strength")*7;
  resist += tgt->query_stats("dexterity")*2;
  resist += random(item?item->query_weight()*2:20);
  resist += random(tgt->query_level());

  // they're already holding on to it...
  if (item && item->query_wielded())
    resist += tgt->query_stats("strength");

  steal -= resist;
  
  if (steal < -150)
    steal = -150;
  if (steal > 150)
    steal = 150;

  if (steal < -3) {
    message("info", "You try to take "+tgt->query_cap_name()+"'s "+what+
                    ", but "+tgt->query_subjective()+" is too strong for you!", tp);
    message("info", tp->query_cap_name()+" tries to grab your "+what+
                    ", but you are too strong for "+tp->query_objective()+"!", tgt);
    message("info", "You notice a scuffle between "+tp->query_cap_name()+
                    " and "+tgt->query_cap_name()+".", env, ({ tp, tgt }) );
    retaliate(tp, tgt, 0);
  }
  
  else if (steal < 1) {

    message("info", "You try to take "+tgt->query_cap_name()+"'s "+what+
                    ", but "+tgt->query_subjective()+" resists you!", tp);
    message("info", tp->query_cap_name()+" tries to grab your "+what+
                    ", but you resist!", tgt);
    message("info", "You notice a scuffle between "+tp->query_cap_name()+
                    " and "+tgt->query_cap_name()+".", env, ({ tp, tgt }) );

    if (random(tp->query_stats("strength")) > tgt->query_stats("strength")/2) {

      if (ret=do_stealing(tp, tgt, item)) {
        message("info", "After a brief struggle, you wrench the "+what+
                        " away from "+tgt->query_objective()+".", tp);
        message("info", "After a brief struggle, "+tp->query_cap_name()+
                        " wrenches the "+what+" away from you.", tgt);
        // some items dest themselves when unwielded
        if (!item)
          message("info", "The "+what+" suddenly vanishes.", env);
        else if (ret == 3) {
          message("info", "The "+item->query_name()+" is too heavy, so you drop it.", tp);
          message("info", tp->query_cap_name()+" can't carry the "+item->query_name()+
                          ", so "+tp->query_subjective()+" drops it.", env, tp);
        }
      }
      else {
        message("info", "After a brief struggle, you wrench "+
                        tgt->query_cap_name()+"'s purse away only to find "
                        "that it is empty!", tp);
        message("info", "After a brief struggle, "+tp->query_cap_name()+
                        "wrenches your empty purse away.", tgt);
      }

      retaliate(tp, tgt, 1);

    }

    else {
      message("info", "After a brief struggle, "+tgt->query_cap_name()+
                      " wrenches "+tgt->query_possessive()+" purse out "
                      "of your hands!", tp);
      message("info", "After a brief struggle, you wrench your purse out "
                      "of "+tp->query_cap_name()+"'s hands!", tgt);

      retaliate(tp, tgt, 0);
    }
  }

  else {
    message("info", "You grab the "+what+" right out of "+
                    tgt->query_cap_name()+"'s hands!", tp);
    message("info", tp->query_cap_name()+" grabs your "+what+
                    " right out of your hands!", tgt);
    message("info", tp->query_cap_name()+" grabs "+
                    tgt->query_cap_name()+"'s "+what+
                    " right out of "+tgt->query_possessive()+" hands!",
                    env, ({tp, tgt}) );
    if (!(ret=do_stealing(tp, tgt, item))) {
      message("info", "Unfortunately, it seems to be empty.", tp);
      message("info", "Fortunately, it was empty.", tgt);
    }
    if (ret == 3) {
      message("info", "The "+item->query_name()+" is too heavy, so you drop it.", tp);
      message("info", tp->query_cap_name()+" can't carry the "+item->query_name()+
                      ", so "+tp->query_subjective()+" drops it.", env, tp);
    }
    if (ret >= 2 && !item) {
      message("info", "The "+what+" suddenly vanishes.", env);
    }
    retaliate(tp, tgt, 1);
  }

  tgt->set(MUG_PROP, 1);
  tp->set_disable();
  tp->add_sp(-(15+random(6)));
  
  return 1;
}

// returns 0 for no money, 1 for money successful,
// 2 for item successful, 3 for item on ground since player's inv was full
int do_stealing(object tp, object tgt, object item) {
  object env;
  
  if (!tp || !tgt) return;

  env=environment(tp);

  if (userp(tgt))
    tp->add_exp(tgt->query_level()*1000);
  else
    tp->add_exp(tgt->query_modified_exp()/8);
  
  if (item) {
    item->set_theft(1);
    if (item->query_worn() || item->query_wielded())
      item->unequip();
    item->set_theft(0);
    if (item && item->move(tp)) {
      item->move(env);
      return 3;
    }
    return 2;
  }
  // money/purse follows
  else {
    int broke=1;
    foreach (string curr in CURRENCIES) {
      int m, r;
      if (m = tgt->query_money(curr)) {
        if (m > 6000)
          m = 6000+(m-6000)/8;
        r = m/4 + random(m*3/4);
        tgt->add_money(curr, -r);
        tp->add_money(curr, r);
        broke=0;
      }
    }
    return !broke;
  }
}

void make_outlaw(object tp, int t) {
  if (file_name(environment(tp))[0..9] == "/d/freepk/")
    return;
  if (t)
    tp->add_outlaw("theft", 1);
  // being disguised or invis helps avoid the second charge
  if ((tp->query_disquised_short() || tp->query_invis()) && random(100) < 75)
    return;
  // this is supposed to represent an assault charge
  tp->add_outlaw("other1", 1);
}

void retaliate(object tp, object tgt, int t) {
  if (userp(tgt))
    make_outlaw(tp, t);
  else
    tgt->force_me("kill "+tp->query_name());
}

