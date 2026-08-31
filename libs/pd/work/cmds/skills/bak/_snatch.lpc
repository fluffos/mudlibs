#include <std.h>
#include <daemons.h>
#include <money.h>

#define FAIL(s) return notify_fail(s+"\n");

#define STAB_ABIL "/cmds/skills/_stab"
#define SNATCH_PROP "snatch_abil_info"

// can get these even if worn (regexp)
#define SNATCH_WORN "ring|earring|bracelet|necklace"
// can never get these, even if not worn (regexp)
#define SNATCH_NEVER "armour"

#define RES "%^RESET%^"
#define COL RES+"%^WHITE%^"

inherit DAEMON;

void forget_snatch(object tgt);
int find_gold_value(object item);

int abil() {
  object tp=this_player();
  if (tp->query_subclass() == "thief" &&
      tp->query_skill("stealing") >= 15*6)
    return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <snatch [item] from [victim]>\n\n"
    "Thieves can attack someone and try to steal an item at the same time. "
    "It's not possible to snatch most worn things or any heavy armour, "
    "but the distraction of a knife in the arm makes it easier to steal.\n\n"
    "Beware, though, as even the dumbest of targets will only fall for it "
    "a few times, and the penalties for assault can be worse than "
    "for simple theft.",
    this_player());
}

void make_outlaw(object tp) {
  if (file_name(environment(tp))[0..9] == "/d/freepk/")
    return;
  if (wizardp(tp))
    message("info", "If you weren't immortal, you'd have gained an other2 (assault) offense.", tp);
  else
    tp->add_outlaw("other2", 1);
}

int can_cast(object tp, object tgt, object *weps, string thing) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot do that here.");

  if (tp->query_busy())
    FAIL("You are busy doing something else.");

  if (!tgt)
    FAIL("You don't see that here.");

  if (!living(tgt))
    FAIL("That is not alive.");

  if (tp == tgt)
    FAIL("Steal from yourself?");

  if (!sizeof(weps))
    FAIL("You need a knife to do that.");
  
  if (tp->query_rest_type())
    FAIL("You must be standing to do that.");
  
  if (tp->query_sp() < 40)
    FAIL("You are too tired to snatch anything.");

  if (userp(tgt) && !interactive(tgt))
    FAIL("You cannot attack link-dead players.");

  if (strlen(thing) && !present(thing, tgt))
    FAIL(capitalize(tgt->query_subjective())+
         " does not have "+a_or_an(thing)+" "+thing+".");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_snatch(string str) {
  object tp=this_player();
  object env = environment(tp);
  object tgt;
  object item, stab, wep;
  object *weps, *inv;
  int steal, perc;
  int cost, dmg, rank, exp;
  string thing, who, limb;
  
  if (!abil()) return 0;

  if (str) {
    if (sscanf(str, "%s from %s", thing, who) == 2) {
      if (tgt = present(who, env))
        item = present(thing, tgt);
    }
    else if (!(tgt = present(str, env)) && tgt = tp->query_current_attacker())
      item = present(str, tgt);
  }
  else
    tgt=tp->query_current_attacker();

  weps = filter(tp->query_wielded(), (: $1->query_type() == "knife" :) );

  if (!can_cast(tp, tgt, weps, thing)) return 0;
  
  steal = tp->query_skill("stealing");
  steal += tp->query_skill("stealth")*2/3;
  
  perc = tgt->query_skill("perception");
  perc += tgt->query(SNATCH_PROP);

  rank = 1+(tp->query_level()-10)/15;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({ "knife", "agility", "attack", "murder" }),
    ({ "dexterity" }),
    ({ "dexterity" }) );
  
  dmg = dmg * 2 / 3;

  cost = log(pow(dmg,3))+dmg/40;
  
  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  // this lets me make this look EXACTLY like stab
  if (!objectp(stab = load_object(STAB_ABIL)))
    FAIL("A problem occurred, please contact an immortal.");

  inv = filter(all_inventory(tgt), (:
    !$1->query_wielded() &&
    strlen($1->query_short()) &&
    !($1->drop() || $1->give() || $1->put() || $1->bury() || $1->store()) &&
    !$1->query_property("no steal") &&
    (!$1->query_worn() || regexp($1->query_type() || "", SNATCH_WORN)) &&
    !regexp($1->query_type() || "", SNATCH_NEVER) &&
    $1->query_weight() <= $(tp)->query_stats("strength")*2/3
  :) );

  if (sizeof(inv) == 0) {
    message("combat",COL+tgt->query_subjective()+
      " doesn't have anything you can snatch!"+RES,tp);
    return 1;
  }

  if (item && member_array(item, inv) == -1)
    FAIL("You can't snatch that!");

  if (!item)
    item=inv[random(sizeof(inv))];

  if (!tp->kill_ob(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  tp->set_disable(1);
  tp->add_sp(-cost);

  wep = sort_array(weps, (:
    $1->query_wc() > $2->query_wc() ? 1 : 0
  :) )[0];
  limb=tgt->return_target_limb();

  if (tgt->query_stats("dexterity")-random(10) > tp->query_stats("dexterity")) {
    stab->do_messages("miss", tp, tgt, rank, wep, limb);
    return 1;
  }

  stab->do_messages("hit", tp, tgt, rank, wep, limb);

  tgt->do_damage(limb,dmg);

  /*
  message("combat", COL+tp->query_cap_name()+
    " seems to quickly grab at "+tgt->query_cap_name()+"."+RES,
    env, ({ tp, tgt }) );
  */

  if ((perc -= steal) > 0) {
    message("combat", COL+"You try to snatch "+item->query_short()+
      " from "+tgt->query_cap_name()+", but "+tgt->query_subjective()+
      " sees your attempt!"+RES, tp);
    message("combat", COL+"You catch "+tp->query_cap_name()+
      " trying to steal something, "
     "but you're too quick for "+tp->query_objective()+"."+RES, tgt);
    if (userp(tp) && userp(tgt) && (perc > 20+random(10) || random(100) > 89))
      make_outlaw(tp);
  }
  else {
    message("combat", COL+"While "+tgt->query_cap_name()+
      " is distracted by the pain, "
      "you snatch "+item->query_short()+" from him!"+RES, tp);
    item->set_theft(1);
    if(item->move(tp)) {
      message("drop", "It is too heavy, and you drop it.", tp);
      message("drop", tp->query_cap_name()+" drops "+
        item->query_short()+".", env, tp);
      item->move(env);
    }
    item->set_theft(0);

    tp->add_skill_points("stealing", steal/3);
    exp = find_gold_value(item)*5;
    if (userp(tgt))
      exp += tgt->query_level()*20;
    else
      exp += tgt->query_modified_exp(tp, tgt)/8 +
             random(tgt->query_modified_exp(tp, tgt)/6);
    if (tp->query_stolen(tgt))
      exp /= 4;
    tp->add_exp(exp);
    tgt->set(SNATCH_PROP,
        tgt->query_stats("intelligence")*2+
        tgt->query_skill("perception")/3+
        tgt->query(SNATCH_PROP)
    );
    DELAY_D->add_delay(120, this_object(), "forget_snatch", ({ tgt }), 1);

  }

  return 1;
}

void forget_snatch(object tgt) {
  int s;
  if (!tgt) return;
  s = tgt->query(SNATCH_PROP);
  s = s/3 - 10;
  if (s < 0) s = 0;
  tgt->set(SNATCH_PROP, s);
  if (s != 0) DELAY_D->add_delay(60, this_object(), "forget_snatch", ({ tgt }), 1);
}

int find_gold_value(object item) {
  int g = 0;
  mapping currvals;
  if (!item) return 0;
  currvals = item->query_curr_value();
  for (int i = 0; i < sizeof(currvals); i++) {
    string k = keys(currvals)[i];
    int v = values(currvals)[i];
    if (member_array(k, HARD_CURRENCIES) == -1) continue;
    g = v / EXCHANGE_RATES[i];
    if (g > 0) break;
  }
  return g;
}

