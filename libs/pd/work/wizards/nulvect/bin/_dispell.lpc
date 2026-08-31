
#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s);

#define COL "%^YELLOW%^"
#define RES "%^RESET%^"

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "paladin") return 1;
  if (tp && member_array(tp->query_subclass(),
      ({"cleric","monk","blue","white"}) ) != -1 &&
      tp->query_level() >= 7 && tp->query_skill("faith") >= 7*5)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <dispell [whom] | all>\n\n"
    "This prayer of faith does damage to the enemies of your faith.",
    this_player() );
}

int can_cast(object tp, object tgt) {
  object env;

  if (!tp) return 0;

  env=environment(tp);

  if (env->query_property("no attack") || env->query_property("no magic"))
    FAIL("You cannot cast that here.\n");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");

  if (!alignment_ok(tp))
    FAIL("You have betrayed the source of your powers.\n");

  if (tp->query_ghost())
    FAIL("You cannot cast spells while dead.\n");

  if (!tgt)
    FAIL("Dispell whom?\n");

  if (!living(tgt))
    FAIL("That is not alive.\n");

  if (tp == tgt)
    FAIL("That would be stupid.\n");

  if (tgt->query_alignment() >= 200)
    FAIL(capitalize(tgt->query_cap_name())+" is not evil!\n");

  if (userp(tgt) && !interactive(tgt))
    FAIL("You may not attack link-dead players.\n");
  
  if (!(tp->kill_ob(tgt)))
    FAIL("You may not attack "+tgt->query_cap_name()+".\n");

  return 1;
}

int cmd_dispell(string str) {
  object tp=this_player();
  object env=environment(tp);
  object *tgts=({});
  int all=0, rank;

  if (!spell()) return 0;

  if (str == "all") all=1;

  if (all)
    tgts = filter(all_inventory(env),
      (: living($1) && $1 != this_player() && can_cast(this_player(), $1) :) );
  else if (str && str != "")
    tgts = ({ present(str, env) });
  else
    tgts = ({ tp->query_current_attacker() });
  
  if (!all && !can_cast(tp, tgts[0]))
    return 0;

  if (all && !sizeof(tgts))
    FAIL("There is nobody to dispell!\n");

  rank = 1+tp->query_skill("faith")/(15*5);
  if (rank > 3) rank=3;

  foreach (object who in tgts) {
    int dmg, cost, al;

    dmg = BALANCE3_D->get_damage(tp, who, rank,
            ({"faith"}),
            ({"wisdom"}),
            ({"faith"}) );
    dmg = dmg/sizeof(tgts);

    dmg = dmg * 0.9;

    al = who->query_alignment();
    dmg = dmg*(1.15+to_float(tp->query_stats("wisdom")/40)*0.1);
    if (al <= -500)
      dmg = dmg*(1.1+((absolute_value(al)-500)/100)*0.1);
    else if (al > -100)
      dmg = dmg*3/5;

    cost = dmg/12;

    if (tp->query_mp() < cost)
      FAIL("Your magic is too low.\n");

    tp->add_mp(-(cost+random(cost/10)));

    if (who == tgts[0]) {
      message("magic", "You pray to the gods.", tp);
      message("magic", tp->query_cap_name()+" mutters a prayer.", env, tp);
    }
    
    message("magic", COL+who->query_cap_name()+" is struck by the force "
                     "of your faith!"+RES, tp);
    message("magic", COL+"You are stuck by the force of "+
                     tp->query_cap_name()+"'s faith!"+RES, who);
    message("magic", COL+who->query_cap_name()+" is struck by the force "
                     "of "+tp->query_cap_name()+"'s faith!"+RES, env, ({tp, who}) );

    who->do_damage(who->return_limb(), dmg);

  }

  tp->set_magic_round(1);

  tp->add_skill_points("faith", 5+random(6));

  return 1;
}

