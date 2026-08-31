
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define RES "%^RESET%^"
#define COL RES+"%^RED%^"
#define COL2 "%^BOLD%^%^BLACK%^"
#define COL3 "%^BOLD%^%^WHITE%^"

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

int spell() {
  object tp=this_player();
  string *allowed = ({ "kataan", "necromancer" });
  if (tp && tp->query_level() >= 3 &&
      member_array(tp->query_subclass(), allowed) != -1)
        return 1;
  return 0;
}

string type() { return "healing"; }

void help() {
  message("help",
    "Syntax: <absorb [whom]>\n\n"
    "With this spell, you absorb the life force of your enemies.",
    this_player() );
}

int can_cast(object tp, object tgt) {
  object env;

  if (!tp) return 0;

  env=environment(tp);
  if (env->query_property("no attack") || env->query_property("no magic"))
    FAIL("Some force prevents your spell.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your spell fails because, well, you're dead.");

  if (!alignment_ok(tp))
    FAIL("You have betrayed the source of your powers!");

  if (!tgt)
    FAIL("Absorb from whom?");

  if (!living(tgt))
    FAIL("That has no life force to absorb.");

  if (tgt == tp)
    FAIL("You cannot absorb from yourself.");

  if (!tp->kill_ob(tgt))
    FAIL("You may not attack "+tgt->query_cap_name()+".");
  
  return 1;
}

int cmd_absorb(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  int dmg, cost, heal;

  if (!spell()) return 0;

  if (str)
    tgt=present(str, env);
  else
    tgt=tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  dmg = BALANCE3_D->get_damage(tp, tgt, 1,
    ({"magic attack"}),
    ({"intelligence", "wisdom"}) );

  cost = BALANCE3_D->get_cost(dmg, 1, "mp") * 95 / 100;
  heal = dmg/4;
  dmg = dmg*3/5;

  if (tp->query_mp() < cost)
    FAIL("Too low on magic power.");

  message("magic",COL+"You r"+COL2+"eac"+COL+"h a hand out towards "+
                  tgt->query_cap_name()+
                  " and "+COL3+"absorb"+COL+" some "+
                  COL2+"he"+COL+"al"+COL2+"th"+COL+
                  " from "+tgt->query_objective()+"!"+RES,tp);
  message("magic",COL+tp->query_cap_name()+" r"+COL2+"eache"+COL+"s a hand "
                  "out towards you and "+
                  COL3+"absorbs"+COL+" some of your "+
                  COL2+"he"+COL+"al"+COL2+"th"+COL+"!"+RES,tgt);
  message("magic",COL+tp->query_cap_name()+" r"+COL2+"eache"+COL+"s a hand "
                  "out towards "+tgt->query_cap_name()+" and "+
                  COL3+"absorbs"+COL+" some of "+tgt->query_possessive()+" "+
                  COL2+"he"+COL+"al"+COL2+"th"+COL+"!"+RES,
                  environment(tp), ({tp,tgt}) );

  tgt->do_damage(0, dmg, DAMAGE_MAGIC, DAMAGE_HP_ONLY | DAMAGE_BYPASS_ARMOUR, tp);
  tp->set_magic_round(1);
  tp->add_hp(heal);
  tp->add_mp(-(cost+random(cost/9)));
  tp->add_alignment(-4);
  tp->add_skill_points("magic attack", random(dmg/20));
  
  return 1;
}


