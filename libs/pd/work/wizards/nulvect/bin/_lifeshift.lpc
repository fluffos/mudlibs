
#include <std.h>

#define RES "%^RESET%^"
#define COL RES+"%^RED%^"
#define COL2 "%^BOLD%^%^WHITE%^"

#define FAIL(s) return notify_fail(s+"\n")

#define LIFESHIFT_PROP "lifeshift_spell_time"
#define LIFESHIFT_DELAY 40

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "necromancer" &&
      tp->query_skill("necromancy") >= 35*6)
        return 1;
  return 0;
}

string type() { return "healing"; }

void help() {
  message("help",
    "Syntax: <lifeshift [whom]>\n\n"
    "This spell allows the caster to transfer some of his life force "
    "and energy into another person. The caster is drained a bit after "
    "each use and must wait a short while before using it again.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your spell.");

  if (tp->query_casting() || tp->query_disable() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_rest_type())
    FAIL("You need to stand up first.");
  
  if (!tgt)
    FAIL("Lifeshift to whom?");

  if (!living(tgt))
    FAIL("That is not alive.");

  if (tp->query(LIFESHIFT_PROP)+LIFESHIFT_DELAY > time())
    FAIL("You cannot use this spell again so soon.");

  if (tp->query_hp() < tp->query_max_hp()*0.6)
    FAIL("Your life force is too low to transfer right now.");

  if (tp == tgt)
    FAIL("You cannot transfer to yourself!");

  return 1;
}

int cmd_lifeshift(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  int amt, cost;

  if (!spell()) return 0;

  if (str)
    tgt=present(str, env);

  if (!can_cast(tp, tgt)) return 0;

  amt = tp->query_skill("necromancy")*1.65;
  if (amt > tp->query_max_hp()*0.6)
    amt = tp->query_max_hp()*0.6;
  amt -= random(amt/10);

  cost = amt*0.6;

  if (tp->query_mp() < cost)
    FAIL("You need more magic power.");

  message("magic", COL+"You to"+COL2+"uc"+COL+"h "+tgt->query_cap_name()+
    " and tr"+COL2+"ansfe"+COL+"r some of your "+COL2+"life force"+COL+
    " into "+tgt->query_objective()+"."+RES, tp);
  message("magic", COL+tp->query_cap_name()+" to"+COL2+"uc"+COL+"hes you "
    " and tr"+COL2+"ansfe"+COL+"rs some "+COL2+"life force"+COL+
    " into you."+RES, tgt);
  message("magic", COL+tp->query_cap_name()+" to"+COL2+"uc"+COL+"hes "+
    tgt->query_cap_name()+
    " and tr"+COL2+"ansfe"+COL+"rs some "+COL2+"life force"+COL+
    " into "+tgt->query_objective()+"."+RES, env, ({tp, tgt}) );
  
  tp->set(LIFESHIFT_PROP, time());
  tp->set_magic_round(1);
  tp->add_mp(-cost);
  tp->add_hp(-amt);
  tp->add_sp(-(amt/4.3));
  tp->add_alignment(amt/17);
  tgt->add_hp(amt);
  tgt->add_sp(amt/4.3);
  
  return 1;
}

