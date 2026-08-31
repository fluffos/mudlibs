
#include <std.h>
#include <daemons.h>

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^BLACK%^"
#define COL2 RES+"%^MAGENTA%^"

#define FAIL(s) return notify_fail(s+"\n")

#define SOULBURN_PROP "soulburn_spell_hit"
#define DOT_HITS 2

inherit DAEMON;

int soulburn_hit(object victim);
int is_undead(object tgt);

object *who=({});

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "necromancer" &&
      tp->query_skill("necromancy") >= 50*6 &&
      tp->query_skill("magic attack") >= 50*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <soulburn [whom]>\n\n"
    "One of the most feared spells of necromancy, this spell attacks the "
    "soul of the target. It cannot hurt those without souls, such as "
    "the undead.",
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
    FAIL("Soulburn whom?");

  if (!living(tgt))
    FAIL("That is not alive.");

  if (tgt == tp)
    FAIL("Your spell fails to take effect.");

  if (tgt->query(SOULBURN_PROP))
    FAIL(capitalize(tgt->query_possessive())+" soul is already burning!");

  if (is_undead(tgt))
    FAIL("The undead have no souls to burn!");
  
  if (!tp->kill_ob(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");
  
  return 1;
}

int cmd_sb(string str) {
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

  dmg = BALANCE3_D->get_damage(tp, tgt, 4,
    ({"necromancy", "magic attack"}),
    ({"intelligence", "intelligence", "wisdom"}),
    ({"intelligence"}) );

  dmg = dmg*1.1;
  
  cost = dmg/8.4;
  
  if (tp->query_mp() < cost)
    FAIL("You need more magic.");

  tp->add_mp(-(cost+random(cost/10)));
  tp->add_alignment(-3);
  
  message("magic", COL2+"You wave your hand at "+
                   tgt->query_cap_name()+"."+RES, tp);
  message("magic", COL2+tp->query_cap_name()+" waves "+tp->query_possessive()+
                   " hand at you."+RES, tgt);
  message("magic", COL2+tp->query_cap_name()+" waves "+tp->query_possessive()+
                   " hand at "+tgt->query_cap_name()+"."+RES, env, ({tp,tgt}));

  tgt->set(SOULBURN_PROP, ({tp,dmg,1}) );
  who += ({tgt});
  soulburn_hit(tgt);
  set_heart_beat(1);

  return 1;
}

int soulburn_hit(object victim) {
  mixed *arr;
  object env;
  object caster;
  int dmg;
  int count;

  if (!victim) return DOT_HITS;

  env=environment(victim);
  arr=victim->query(SOULBURN_PROP);
  caster=arr[0];
  dmg=arr[1];
  count=arr[2];

  if (!sizeof(arr) || !caster || !dmg ||
      !env || environment(caster) != env ||
      env->query_property("no magic") ||
      env->query_property("no attack"))
        return DOT_HITS;

  dmg = (dmg*0.7)*count;

  message("magic", COL+"An "+
    COL2+"ex"+COL+"cr"+COL2+"ut"+COL+"ia"+COL2+"ti"+COL+"ng "+COL2+"pa"+COL+"in "
    "burns your soul!"+RES, victim);
  message("magic", COL+victim->query_cap_name()+" "
    COL2+"wr"+COL+"it"+COL2+"he"+COL+"s i"+COL2+"n a"+COL+"go"+COL2+"ny"+COL+
    " as "+victim->query_possessive()+" soul burns!",
    env, victim);
  
  victim->do_damage(victim->return_limb(), dmg);
  victim->set(SOULBURN_PROP, arr[0..1]+({count+1}) );
  caster->set_magic_round(1);

  return count;
}

void heart_beat() {
  foreach (object victim in who) {
    int count;
    if (!victim) who -= ({victim});
    else {
      count = soulburn_hit(victim);
      if (victim) {
        if (count >= DOT_HITS || victim->query_ghost()) {
          victim->set(SOULBURN_PROP,0);
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

