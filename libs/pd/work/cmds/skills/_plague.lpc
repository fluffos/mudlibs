#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define COL "%^BOLD%^%^GREEN%^"
#define COL2 "%^BOLD%^%^BLACK%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n")

#define PLAGUE_PROP "plague_spell_hit"
#define DOT_HITS 5

inherit DAEMON;

int plague_hit(object victim);
int is_undead(object tgt);
int can_hit(object tp, object tgt);

object *who=({});

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "necromancer" &&
      tp->query_skill("necromancy") >= 30*6 &&
      tp->query_skill("magic attack") >= 30*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <plague>\n\n"
    "This nasty spell of infection spreads a plague out among everyone "
    "in the area to slowly kill them.",
    this_player() );
}

int can_cast(object tp) {
  object env;
  
  if (!tp) return 0;

  env=environment(tp);

  if (env->query_property("no attack") || env->query_property("no magic"))
    FAIL("Some force prevents your spell.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You would have to be alive first.");
  
  return 1;
}

int cmd_plague(string str) {
  object tp=this_player();
  object env=environment(tp);
  object *tgts, *hit = ({});
  int dmg, cost;

  if (!spell()) return 0;

  if (!can_cast(tp)) return 0;

  tgts = filter(all_inventory(env)-({tp}),
    function (object who, object tp) {
      string party = tp->query_party();
      object mount = tp->query_riding();
      object *riders = who->query_riders();
      if (!who->is_living()) return 0;
      if (is_undead(who)) return 0;
      if (party && who->query_party() == party) return 0;
      if (mount && mount == who) return 0;
      foreach (object ob in riders)
        if (party && ob->query_party() == party) return 0;
      if (!strlen(who->query_long())) return 0;
      return 1;
    }, tp );

  
  foreach (object tgt in tgts) {
    mixed can = can_hit(tp, tgt);

    if (can != 1) {
      if (stringp(can))
        message("info", can, tp);
      continue;
    }
        
    dmg = BALANCE3_D->get_damage(tp, tgt, 3,
      ({"necromancy", "necromancy", "magic attack"}),
      ({"intelligence", "intelligence", "wisdom"}),
      ({"magic attack", "necromancy"}) );

    // multi hits == multi damage reductions so make this higher than normal
    dmg = dmg*1.15;

    cost = BALANCE3_D->get_cost(dmg, 3, "mp")*4/5;
  
    if (tp->query_mp() < cost) {
      if (!sizeof(hit))
        FAIL("You need more magic.");
      else {
        break;
      }
    }

    tp->add_mp(-(cost+random(cost/15)));
    tgt->set(PLAGUE_PROP, ({tp,dmg,1}) );
    hit += ({tgt});
    who += ({tgt});

  }
  message("magic", COL2+"You wave your hand in an arc."+RES, tp);
  message("magic", COL2+tp->query_cap_name()+" waves "+tp->query_possessive()+
                   " hand in an arc.", env, tp);
  if (sizeof(hit)) {
    tp->add_skill_points("necromancy", 25);
    tp->add_skill_points("magic attack", 20);
    tp->add_alignment(-4);
    tp->set_magic_round(2);
    set_heart_beat(1);
    foreach (object tgt in hit)
      plague_hit(tgt);
  }

  return 1;
}

int plague_hit(object victim) {
  mixed *arr;
  object caster;
  object env;
  int dmg;
  int count;

  if (!victim) return DOT_HITS;

  env=environment(victim);
  arr=victim->query(PLAGUE_PROP);
  caster=arr[0];
  dmg=arr[1];
  count=arr[2];

  if (!sizeof(arr) || !caster || !dmg ||
      !env || environment(caster) != env ||
      env->query_property("no magic") ||
      env->query_property("no attack"))
        return DOT_HITS;

  dmg = (dmg*0.25)*count;

  message("magic", COL+"Your body "+COL2+"spasms"+COL+" as the "
                   "p"+COL2+"la"+COL+"gu"+COL2+"e"+COL+
                   " "+COL2+"eats away"+COL+" at it!"+RES, victim);
  message("magic", COL+victim->query_cap_name()+"'s body "+
                   COL2+"spasms"+COL+" as the "
                   "p"+COL2+"la"+COL+"gu"+COL2+"e"+COL+
                   " "+COL2+"eats away"+COL+" at it!"+RES, env, victim);

  victim->do_damage("random", dmg, DAMAGE_MAGIC | DAMAGE_DISEASE, DAMAGE_NO_SEVER, caster);
  victim->set(PLAGUE_PROP, arr[0..1]+({count+1}) );

  caster->set_magic_round(1);

  return count;
}

void heart_beat() {
  foreach (object victim in who) {
    int count;
    if (!victim) who -= ({victim});
    else {
      count = plague_hit(victim);
      if (victim) {
        if (count >= DOT_HITS || victim->query_ghost()) {
          victim->set(PLAGUE_PROP,0);
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

mixed can_hit(object tp, object tgt) {

  if (!tp || !tgt) return 0;

  if (tgt->query(PLAGUE_PROP))
    return capitalize(tgt->query_subjective())+" is already infected!";

  if (!tp->kill_ob(tgt))
    return "You cannot attack "+tgt->query_cap_name()+".";

  return 1;
}

