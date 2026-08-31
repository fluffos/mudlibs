#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s);
#define COL "%^BOLD%^%^RED%^"
#define RES "%^RESET%^"

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "pyromancer" &&
      tp->query_skill("pyromancy") >= 11*6 &&
      tp->query_skill("magic attack") >= to_int(11*5.5) )
        return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <firebomb [living] [with [drink]]>\n\n"
    "A spell that shoots a smallish jet of flame at a target. "
    "Using an alcoholic drink, the caster can cause the flames "
    "to ignite the alcohol and splatter more fire around, "
    "doing more damage and hitting more opponents.\n"
    "This spell is for novice pyromancers.",
    this_player());
}

int can_cast(object tp, object ob, object drink) {
  object env;
  
  if (!tp) return 0;

  if (!ob)
    FAIL("You do not see that here.\n");
  
  env = environment(tp);

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");

  if (env->query_property("no attack") || env->query_property("no magic"))
    FAIL("You cannot cast that here.\n");

  if (!living(ob))
    FAIL("That is not alive.\n");
  
  if (tp == ob)
    FAIL("Sizzle sizzle.\n");

  if (userp(ob) && !interactive(ob))
    FAIL("You cannot attack link-dead players.\n");

  if (env != environment(ob))
    FAIL(capitalize(ob->query_subjective())+" is not here.\n");

  if (objectp(drink) && drink->query("type") != "alcoholic")
    FAIL(capitalize(drink->query_name())+" is not an alcoholic drink.\n");
  
  if (!(tp->kill_ob(ob)))
    FAIL("You cannot attack "+ob->query_cap_name()+".\n");

  return 1;
}

int cmd_firebomb(string str) {
  object tp=this_player();
  object env;
  object tgt;
  object *tgts;
  object drink;
  string tmp, tmp2;
  int drinkpower=0;
  int cost, dmg;

  if (!spell()) return 0;

  env = environment(tp);

  if (!str || str == "")
    tgt=tp->query_current_attacker();
  else if (sscanf(str, "with %s", tmp) == 1) {
    tgt=tp->query_current_attacker();
    drink=present(tmp, tp);
  }
  else if (sscanf(str, "%s with %s", tmp, tmp2) == 2) {
    tgt=present(tmp, env);
    drink=present(tmp2, tp);
  }
  else
    tgt=present(str, env);

  if (!can_cast(tp, tgt, drink)) return 0;

  if (objectp(drink))
    drinkpower = drink->query_strength();

  tp->clean_up_attackers();
  tgts = tp->query_attackers()-({tgt});

  dmg = BALANCE3_D->get_damage(tp, tgt, 1,
    ({"pyromancy", "magic attack"}),
    ({"intelligence"}) );

  dmg += drinkpower*2;
    
  cost = dmg/3;

  if (tp->query_mp() < cost)
    FAIL("Not enough magic.\n");

  tp->add_mp(-(cost+random(cost/10)));

  tp->set_paralyzed(1,"You are concentrating on your spell.");
  
  if (drinkpower) {
    message("magic", "You throw "+drink->query_name()+" at "+
                     tgt->query_cap_name()+" and it shatters!", tp);
    message("magic", tp->query_cap_name()+" throws "+drink->query_name()+
                     " at you and it shatters!",tgt);
    message("magic", tp->query_cap_name()+" throws "+drink->query_name()+
                     " at "+tgt->query_cap_name()+" and it shatters!",tgt);
  }

  if (dmg < 10) {
    message("magic", COL+"You shoot a flame at "+tgt->query_cap_name()+
                     ", but fail to hurt "+tgt->query_objective()+"."+RES, tp);
    message("magic", COL+tp->query_cap_name()+ " shoots a flame at you, "
                     "but it does no damage."+RES, tgt);
    message("magic", COL+tp->query_cap_name()+ " shoots a flame at "+
                     tgt->query_cap_name()+", but it does no damage."+RES,
                     env, ({tp,tgt}) );
  }

  else {
    message("magic", COL+"You shoot a jet of flame that burns "+
                     tgt->query_cap_name()+"!"+RES, tp);
    message("magic", COL+tp->query_cap_name()+" shoots a jet of flame that "
                     "burns you!", tgt);
    message("magic", COL+tp->query_cap_name()+" shoots a jet of flame that "
                     "burns "+tgt->query_cap_name()+"!", env, ({tp,tgt}) );
    
    tgt->do_damage(tgt->return_target_limb(), dmg);
  }

  if (drinkpower) {
    foreach (object t in tgts) {
      int d=dmg/3;
      message("magic", COL+"The alcohol ignites and burns you!", t);
      message("magic", COL+"The alcohol ignites and burns "+
                       t->query_cap_name()+"!", env, t);
      t->do_damage(t->return_target_limb(), d);
    }
    drink->remove();
  }

  return 1;
}
