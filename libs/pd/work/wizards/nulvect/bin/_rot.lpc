
#include <std.h>
#include <daemons.h>

#define COL "%^BOLD%^%^GREEN%^"
#define COL2 "%^BOLD%^%^BLACK%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n")

#define ROT_PROP "rot_spell_hit"
#define DOT_HITS 2

inherit DAEMON;

int rot_hit(object victim);
int is_undead(object tgt);

object *who=({});

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "necromancer" &&
      tp->query_skill("necromancy") >= 6*4)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <rot [whom]>\n\n"
    "A basic necromancy spell which causes the victim's body "
    "to rot slowly.",
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
    FAIL("Rot whom?");

  if (!living(tgt))
    FAIL("That is not alive.");

  if (tgt == tp)
    FAIL("Your spell fails to take effect.");

  if (tgt->query(ROT_PROP))
    FAIL(capitalize(tgt->query_subjective())+" is already afflicted with rot!");

  if (is_undead(tgt))
    FAIL("You cannot rot the undead!");
  
  if (!tp->kill_ob(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");
  
  return 1;
}

int cmd_rot(string str) {
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

  dmg = BALANCE3_D->get_damage(tp, tgt, 1,
    ({"necromancy"}),
    ({"intelligence"}) );

  // I'm doing over 1.0 on a newbie spell because multiple hits means
  // there are multiple damage reductions from armour/etc
  dmg = dmg*1.2;

  if (dmg > 220) dmg = 220;

  cost = dmg/6.4;
  
  if (tp->query_mp() < cost)
    FAIL("You need more magic.");

  tp->set_magic_round(2);
  tp->add_mp(-(cost+random(cost/10)));
  tp->add_skill_points("necromancy", 10);
  tp->add_alignment(-1);
  
  message("magic", COL2+"You wave your hand at "+
                   tgt->query_cap_name()+"."+RES, tp);
  message("magic", COL2+tp->query_cap_name()+" waves "+tp->query_possessive()+
                   " hand at you."+RES, tgt);
  message("magic", COL2+tp->query_cap_name()+" waves "+tp->query_possessive()+
                   " hand at "+tgt->query_cap_name()+"."+RES, env, ({tp,tgt}));

  tgt->set(ROT_PROP, ({tp,dmg,1}) );
  who += ({tgt});
  rot_hit(tgt);
  set_heart_beat(1);

  return 1;
}

int rot_hit(object victim) {
  mixed *arr;
  object env;
  object caster;
  int dmg;
  int count;

  if (!victim) return DOT_HITS;

  env=environment(victim);
  arr=victim->query(ROT_PROP);
  caster=arr[0];
  dmg=arr[1];
  count=arr[2];

  if (!sizeof(arr) || !caster || !dmg ||
      !env || environment(caster) != env ||
      env->query_property("no magic") ||
      env->query_property("no attack"))
        return DOT_HITS;

  dmg = (dmg*0.3)*count;

  message("magic", COL+"Your skin rots away in patches!"+RES, victim);
  message("magic", COL+victim->query_cap_name()+"'s skin rots away in patches!",
    env, victim);
  
  victim->do_damage(victim->return_limb(), dmg);
  victim->set(ROT_PROP, arr[0..1]+({count+1}) );

  return count;
}

void heart_beat() {
  foreach (object victim in who) {
    int count;
    if (!victim) who -= ({victim});
    else {
      count = rot_hit(victim);
      if (victim) {
        if (count >= DOT_HITS || victim->query_ghost()) {
          victim->set(ROT_PROP,0);
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

