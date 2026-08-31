#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s);
#define COL "%^BOLD%^%^RED%^"
#define RES "%^RESET%^"

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "pyromancer" &&
      tp->query_skill("pyromancy") >= 20*6 &&
      tp->query_skill("magic attack") >= to_int(20*5.5) )
        return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <flamebraid>\n\n"
    "This fiery spell shoots several braids of flame out in "
    "different directions, which can hit the caster's enemies.",
    this_player());
}

int can_cast(object tp, object *tgts) {
  object env;
  
  if (!tp) return 0;
  
  env = environment(tp);

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");

  if (env->query_property("no attack") || env->query_property("no magic"))
    FAIL("You cannot cast that here.\n");

  if (!sizeof(tgts))
    FAIL("You are not fighting anybody.\n");

  return 1;
}

int cmd_flamebraid(string str) {
  object tp=this_player();
  object env;
  object *tgts;
  int s, hits;
  int rank;

  if (!spell()) return 0;

  env = environment(tp);
  
  tp->clean_up_attackers();
  tgts = tp->query_attackers();

  if (!can_cast(tp, tgts)) return 0;
  
  tp->add_mp(-(30+random(20)));
  tp->set_magic_round();
  tp->set_paralyzed(1, "You are concentrating on your spell.");

  message("magic",COL+"Braids of flame shoot out from your body!"+RES,tp);
  message("magic",COL+"Braids of flame shoot out from "+tp->query_cap_name()+
                  "'s body!"+RES, env, tp);

  if (tp->query_skill("pyromancy") >= 32*6)
    rank=3;
  else
    rank=2;

  hits = rank+random(3);
  s = sizeof(tgts);

  for (int i=0; i<hits; i++) {
    int cost, dmg;
    object tgt=tgts[random(s)];

    if (environment(tgt) != env)
      continue;

    if (userp(tgt) && !interactive(tgt)) {
      message("info", "You cannot attack link-dead players.", tp);
      continue;
    }
    
    if (!(tp->kill_ob(tgt))) {
      message("info", "You cannot attack "+tgt->query_cap_name()+".", tp);
      continue;
    }
    
    dmg = BALANCE3_D->get_damage(tp, tgt, rank,
      ({"pyromancy", "pyromancy", "magic attack", "magic attack", "conjuring"}),
      ({"intelligence", "intelligence", "intelligence", "wisdom"}),
      ({"pyromancy"}) );
    dmg = dmg*4/10;
    
    cost = dmg/7;

    if (tp->query_mp() < cost) {
      message("info", "You run out of magic.", tp);
      break;
    }

    if (dmg < 30) {
      message("magic", COL+"A braid of flame shoots past your head."+RES, tgt);
      message("magic", COL+"A braid of flame shoots past "+
        tgt->query_cap_name()+"'s head."+RES, env, tgt);
      continue;
    }

    tp->add_mp(-(cost+random(cost/10)));

    message("magic", COL+"A braid of flame twines all around you!"+RES, tgt);
    message("magic", COL+"A braid of flame twines all around "+
      tgt->query_cap_name()+"!"+RES, env, tgt);
    
    tgt->do_damage(tgt->return_limb(), dmg);
    
  }

  return 1;
}
