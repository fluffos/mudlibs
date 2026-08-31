
#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^BOLD%^%^WHITE%^"
#define COL2 RES+"%^RED%^"
#define RES "%^RESET%^"

#define LUNGE_PROP "lunge_abil_slow_time"
#define LUNGE_DELAY 20

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "swashbuckler" &&
      tp->query_skill("blade") >= 23*6 &&
      tp->query_skill("attack") >= to_int(23*4.5))
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <lunge [opponent]>\n\n"
    "This strong lunging attack can really hurt your opponent, "
    "causing bleeding and making him fight more slowly.",
    this_player() );
}

int can_cast(object tp, object tgt, object *weps) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You are too insubstancial to even hold a sword!");

  if (!tgt)
    FAIL("Lunge at whom?");

  if (!tgt->is_living())
    FAIL("This isn't fencing practice!");

  if (!sizeof(weps))
    FAIL("You must use a blade for that.");

  if (tgt == tp)
    FAIL("That is both impossible and highly dishonorable.");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  if (tp->query_sp() < 50)
    FAIL("You are too tired.");

  return 1;
}

int cmd_lunge(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt, wep;
  object *weps;
  string wepname;
  int rank, dmg, cost, bleed, slow, rounds;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  weps = filter(tp->query_wielded(), (: $1->query_type() == "blade" :) );

  if (!can_cast(tp, tgt, weps)) return 0;

  weps = sort_array(weps, (: $1->query_wc() < $2->query_wc() ? -1 : 1 :) );
  wep = weps[0];
  wepname = remove_article(strip_color(wep->query_short()));
  wepname = replace_string(wepname, " (wielded)", "");

  rank = tp->query_level()/15 + 1;
  if (tp->query_stats("dexterity") >= tp->query_level()*2)
    rank += 1;
  if (rank > 4) rank = 4;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({ "blade", "blade", "attack", "entertainment" }),
    ({ "dexterity", "dexterity", "strength" }),
    ({ "dexterity", "strength" }) );

  dmg = dmg * 87/100;

  cost = dmg/13;
  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  tp->add_sp(-(cost+random(7)));
  tp->set_disable(1);
  tp->kill_ob(tgt);

  if (tgt->query_stats("dexterity") >
      tp->query_stats("dexterity")+random(15)) {

    message("combat", "You lunge at your opponent, but miss "+
      tgt->query_objective()+" entirely.", tp);
    message("combat", tp->query_cap_name()+" lunges at you, but "
      "misses entirely.", tgt);
    message("combat", tp->query_cap_name()+" lunges at "+
      tgt->query_cap_name()+", but misses entirely.", env, ({ tp, tgt }) );

    return 1;
  }

  bleed = dmg/8;
  slow = 1;
  if (tp->query_stats("strength") > tgt->query_stats("constitution")*125/100) {
    if (random(500) < 250) slow++;
    bleed = bleed*3/2;
  }
  // every 7 percent of max hp, add another round of slow
  rounds = 3 + (dmg * 100 / tgt->query_max_hp())/7;
  if (rounds > 5)
    rounds = 5 + (rounds-5)/2;
  if (rounds > 8)
    rounds = 8 + (rounds-8)/3;

  message("combat", "You "+COL+"lu"+COL2+"n"+COL+"ge"+RES+" forward and "+
    COL+"stab"+RES+" your "+wepname+" into your opponent!", tp);
  message("combat", tp->query_cap_name()+" "+COL+"lu"+COL2+"n"+COL+"ges"+RES+
    " forward and "+COL+"stabs"+RES+" "+tp->query_possessive()+" "+wepname+
    "into you!", tgt);
  message("combat", tp->query_cap_name()+" "+COL+"lu"+COL2+"n"+COL+"ges"+RES+
    " forward and "+COL+"stabs"+RES+" "+tp->query_possessive()+" "+wepname+
    "into "+tgt->query_cap_name()+"!", env, ({ tp, tgt }) );
  message("combat", "Blood "+COL2+"seeps"+RES+" from the wound.", env);

  if (tgt->query(LUNGE_PROP) < time()) {
    tgt->set(LUNGE_PROP, time() + rounds*2 + LUNGE_DELAY);
    tgt->add_combat_round_bonus(-slow, rounds*2);
  }
  tgt->add_bleeding(bleed);
  tgt->do_damage(tgt->return_target_limb(), dmg);

  return 1;
}

