
#include <std.h>
#include <effect_cl.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^BOLD%^%^BLACK%^"
#define RES "%^RESET%^"

inherit DAEMON;

void end_bane(class Effect bane);

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "antipaladin" &&
      tp->query_skill("magic attack") >= 14*4)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <bane [living]>\n\n"
    "A terrible curse of the antipaladin, this magic weakens the target's "
    "body and makes it unable to heal for a time.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your own ethereal form causes the spell to fizzle.");

  if (!tgt)
    FAIL("Cast it at whom?");

  if (!tgt->is_living())
    FAIL("That is not alive.");

  if (tp == tgt)
    FAIL("That would be unwise.");

  if (tgt->query_effect("bane"))
    FAIL(capitalize(tgt->query_subjective())+
         " has already been afflicted with that!");

  if (tp->query_mp() < 70)
    FAIL("Your magic power is too low.");

  if (!tp->kill_ob(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_bane(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int cost, rounds, debuff, amt;
  class Effect bane;

  if (!spell()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  rounds = 15;
  rounds += (tp->query_stats("wisdom") - 20)/7;
  rounds += random(3) - random(3);

  debuff = 15;
  debuff += (tp->query_skill("magic attack") - 50) * 100 / (80*4);
  if (debuff > 35)
    debuff = 35 + (debuff-35)/2;

  cost = rounds*7 + debuff*4;
  if (tp->query_mp() < cost)
    FAIL("Your magic power is too low.");

  if (tgt->query_stat_bonus("constitution") < 0)
    debuff = 0;

  amt = tgt->query_base_stats("constitution");
  amt = amt * debuff/100;
  // this is needed because max hp is automatically linked to constitution
  if (tgt->is_player())
    amt = amt * 60 / 100;
  if (amt < 5)
    amt = 5;

  bane = new(class Effect);
  bane->name = "bane";
  bane->castername = tp->query_name();
  bane->caster = tp;
  bane->target = tgt;
  bane->desc = "Your body is afflicted with a terrible weakness.";
  bane->endtime = time()+(rounds*2);
  bane->endfunc = (: end_bane :);
  bane->endmessages = ({
    COL+"The weakness upon your body has lifted."+RES,
    COL+"The ethereal wind leaves "+tgt->query_cap_name()+"'s body."+RES,
  });
  bane->misc = ({ amt });

  tgt->add_stat_bonus("constitution", -amt);
  tgt->add_effect(bane);

  message("magic", COL+"An ethereal wind surrounds "+tgt->query_cap_name()+
                   " as "+tgt->query_possessive()+" body is weakened."+RES,
                   env, tgt);
  message("magic", COL+"An ethereal wind surrounds you"
                   " as your body is weakened."+RES, tgt);

  tp->add_mp(-(cost+random(cost/6)));
  tp->set_magic_round(1);
  tp->add_skill_points("magic attack", 5+debuff);

  return 1;
}

void end_bane(class Effect bane) {
  object who = bane->target;
  int *info = bane->misc;
  int amt = info[0];

  who->add_stat_bonus("constitution", amt);
}

