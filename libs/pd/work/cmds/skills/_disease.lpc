
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define COL "%^BOLD%^%^GREEN%^"
#define COL2 "%^BOLD%^%^BLACK%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n")

#define DISEASE_PROP "disease_spell_hit"
#define DOT_HITS 3

inherit DAEMON;

int disease_hit(object victim);
int is_undead(object tgt);

object *who=({});

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "necromancer" &&
      tp->query_skill("necromancy") >= 15*6 &&
      tp->query_skill("magic attack") >= 15*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <disease [whom]>\n\n"
    "A spell that infects the victim with a potent but short-lived "
    "disease that ravages his body.",
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
    FAIL("You would have to be alive first.");

  if (!tgt)
    FAIL("Disease whom?");

  if (!living(tgt))
    FAIL("That is not alive.");

  if (tgt == tp)
    FAIL("Your spell fails to take effect.");

  if (tgt->query(DISEASE_PROP))

    FAIL(capitalize(tgt->query_subjective())+" is already infected!");

  if (is_undead(tgt))
    FAIL("You cannot infect the undead!");
  
  if (!tp->kill_ob(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");
  
  return 1;
}

int cmd_disease(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  int dmg, cost;

  if (!spell()) return 0;

  if (str)
    tgt=present(str, env);
  else
    tgt=tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  dmg = BALANCE3_D->get_damage(tp, tgt, 2,
    ({"necromancy", "magic attack"}),
    ({"intelligence", "intelligence", "wisdom"}) );

  // multi hits == multi damage reductions so make this higher than normal
  dmg = dmg*1.2;

  if (dmg > 700) dmg=700+random(50);

  cost = BALANCE3_D->get_cost(dmg, 2, "mp");
  
  if (tp->query_mp() < cost)
    FAIL("You need more magic.");

  tp->add_mp(-(cost+random(cost/10)));
  tp->add_skill_points("necromancy", 15);
  tp->add_skill_points("magic attack", 10);
  tp->add_alignment(-3);
  tp->set_magic_round(2);
  
  message("magic", COL2+"You wave your hand at "+
                   tgt->query_cap_name()+"."+RES, tp);
  message("magic", COL2+tp->query_cap_name()+" waves "+tp->query_possessive()+
                   " hand at you."+RES, tgt);
  message("magic", COL2+tp->query_cap_name()+" waves "+tp->query_possessive()+
                   " hand at "+tgt->query_cap_name()+"."+RES, env, ({tp,tgt}));

  tgt->set(DISEASE_PROP, ({tp,dmg,1}) );
  who += ({tgt});
  disease_hit(tgt);
  set_heart_beat(1);

  return 1;
}

int disease_hit(object victim) {
  mixed *arr;
  object caster;
  object env;
  int dmg;
  int count;

  if (!victim) return DOT_HITS;

  env=environment(victim);
  arr=victim->query(DISEASE_PROP);
  caster=arr[0];
  dmg=arr[1];
  count=arr[2];

  if (!sizeof(arr) || !caster || !dmg ||
      !env || environment(caster) != env ||
      env->query_property("no magic") ||
      env->query_property("no attack"))
        return DOT_HITS;

  dmg = (dmg*0.42)*count;

  message("magic", COL+"You "+COL2+"bleed"+COL+" and "
                   "c"+COL2+"o"+COL+"nv"+COL2+"u"+COL+"ls"+COL2+"e"+COL+
                   " from the pain!"+RES, victim);
  message("magic", COL+victim->query_cap_name()+" "+COL2+"bleeds"+COL+" and c"+
                   COL2+"o"+COL+"nv"+COL2+"u"+COL+"ls"+COL2+"e"+COL+"s!"+RES,
                   environment(victim), victim);

  victim->do_damage("random", dmg, DAMAGE_MAGIC | DAMAGE_DISEASE, DAMAGE_NO_SEVER, caster);
  victim->set(DISEASE_PROP, arr[0..1]+({count+1}) );

  caster->set_magic_round(1);

  return count;
}

void heart_beat() {
  foreach (object victim in who) {
    int count;
    if (!victim) who -= ({victim});
    else {
      count = disease_hit(victim);
      if (victim) {
        if (count >= DOT_HITS || victim->query_ghost()) {
          victim->set(DISEASE_PROP,0);
          who -= ({victim});
        }
      }
      else {
        who -= ({victim});
      }
    }
  }
  if (!sizeof(who)) set_heart_beat(0);
}

int is_undead(object tgt) {
  if (tgt->query_undead() || member_array(tgt->query_race(),
      ({"undead","vampire","lich","ghoul","zombie",
      "corpse","ghost","ghast","wight","spirit",
      "skeleton","spectre","wraith","spirit"})) != -1)
        return 1;
  return 0;
}

