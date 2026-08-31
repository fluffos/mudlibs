
#include <std.h>
#include <daemons.h>

#define COL "%^BLUE%^"
#define COL2 "%^ORANGE%^"
#define RES "%^RESET%^"

#define DIRT_PROP "dirt_abil_time"
#define DIRT_DELAY 20

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

int abil() {
  object tp = this_player();
  if ((tp->query_subclass() == "thief" || tp->query_subclass() == "thug") &&
      tp->query_level() >= 16)
        return 1;
  return 0;
}

string type() { return "deception"; }

void help() {
  message("help",
    "Syntax: <dirt [who]>\n\n"
    "One of the oldest tricks known, some rogues will throw a handful of dirt "
    "into the eyes of an enemy to blind him.",
    this_player() );
}

int can_cast(object tp, object tgt) {
  object env;

  if (!tp) return 0;

  env = environment(tp);

  if (env->query_property("no attack"))
    FAIL("Some force prevents your mischief.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("The dirt slips right through your ghostly fingers.");

  if (env->query_property("swamp") ||
      env->query_property("polar") ||
      env->query_property("water"))
        FAIL("There is no dirt around to throw!");

  if (!tgt)
    FAIL("Throw dirt at whom?");

  if (!living(tgt))
    FAIL("You throw some dirt at it. Now it's dirty.");

  if (!tgt->query_is_limb("head"))
    FAIL(capitalize(tgt->query_subjective())+" has no head, and thus, "
         "no eyes to aim for.");

  if (!sizeof(tp->query_wielding_limbs()))
    FAIL("You don't have any hands.");

  if (tgt == tp)
    FAIL("That would be supremely stupid.");

  if (tgt->query(DIRT_PROP)+DIRT_DELAY > time())
    FAIL(capitalize(tgt->query_subjective())+" is too wary for that.");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_dirt(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int dex, stealth, perc, def, time, surprise, rounds, cost;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  dex = tp->query_stats("dexterity");
  stealth = tp->query_skill("stealth");
  perc = tgt->query_skill("perception");
  def = tgt->query_skill("defense");

  time = time() - (int)tgt->query(DIRT_PROP);
  time -= 120;

  if (member_array(tgt, tp->query_attackers()) != -1) {
    surprise = 2;
    if (sizeof(tgt->query_attackers()))
      surprise += 1;
  }
  else
    surprise = 0;

  rounds =  (dex*3 + stealth/2)/35 + surprise;;
  rounds -= (perc/2+def/3)/80;

  // this is a RESISTANCE against this abil
  if (time < 0) rounds += time/15;

  /*
  if (rounds > 3)
    rounds = 3 + (rounds-3)/3;
  if (rounds > 5)
    rounds = 5 + (rounds-5)/6;
  */
  if (rounds < 3) rounds = 1;
  else rounds = 2.8*log(rounds*2/3);

  cost = 10 + stealth/45 + rounds*5/3;

  if (tp->query_sp() < cost)
    FAIL("You are way too tired.");

  tp->add_sp(-cost);
  tp->set_disable();
  tp->kill_ob(tgt);

  message("combat", "You reach down and grab some "+COL2+"dirt"+RES+
                  " from the ground.", tp);

  if (rounds > 0) {
    message("combat", "You "+COL+"throw the dirt"+RES+" right into "+
                      tgt->query_cap_name()+"'s eyes, "+COL+"blinding"+RES+" "+
                      tgt->query_objective()+"!", tp);
    message("combat", "A handful of "+COL2+"dirt"+RES+" hits you right "+
                      "in the "+COL+"eyes"+RES+", "+COL+"blinding"+RES+" you!",
                      tgt);
    message("combat", "A handful of "+COL2+"dirt"+RES+" suddenly hits "+
                      tgt->query_cap_name()+" in the "+COL+"face"+RES+"!",
                      env, ({ tp, tgt }) );
    tgt->set_blind(-1);
    DELAY_D->add_delay(rounds*2, this_object(), "dirt_wear_off", ({ tgt }), 1);
  }

  else {
    message("combat", "You "+COL+"throw the dirt"+RES+" at "+
                      tgt->query_cap_name()+"'s face, but "+
                      tgt->query_subjective()+" easily blocks it.", tp);
    message("combat", "A handful of "+COL2+"dirt"+RES+" comes flying at your "
                      "face, but you easily block it.", tgt);
    message("combat", "A handful of "+COL2+"dirt"+RES+" suddenly flies at "+
                       tgt->query_cap_name()+"'s face, but "+
                       tgt->query_subjective()+" easily blocks it.",
                       env, ({ tp, tgt }) );
  }

  tgt->set(DIRT_PROP, time());

  return 1;
}

void dirt_wear_off(object tgt) {
  if (tgt && tgt->query_blind()) {
    tgt->set_blind(0);
    //message("info", "You can see again.", tgt);
  }
}

