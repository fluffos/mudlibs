
#include <std.h>
#include <daemons.h>

#define COL "%^BOLD%^%^BLACK%^"
#define COL2 "%^BOLD%^%^GREEN%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n")

#define DEATHTOUCH_PROP "deathtouch_spell_charge"

inherit DAEMON;

int is_undead(object tgt);

object *who=({});

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "necromancer" &&
      tp->query_skill("necromancy") >= 20*6 &&
      tp->query_skill("magic attack") >= 20*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <deathtouch corpse>\n"
    "        <deathtouch [whom]>\n\n"
    "A specialty of the necromancer, this spell takes its power "
    "directly from the dead. Using <deathtouch corpse>, a necromancer "
    "can pull all of the pain, rot, and horror of death out of a "
    "dead body and store it for a time. Using a deathtouch against the "
    "living then causes them to suffer almost as if they had died.",
    this_player() );
}

int can_cast(object tp, object tgt) {
  
  object env;

  if (!tp) return 0;

  env=environment(tp);

  if (env->query_property("no magic") || env->query_property("no attack"))
    FAIL("Some force prevents your magic.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You're too dead to do that.");

  if (!tgt)
    FAIL("Deathtouch what?");

  if (living(tgt)) {
    if (tp->query_rest_type())
      FAIL("You have to be standing first.");

    if (!tp->query(DEATHTOUCH_PROP))
      FAIL("You have no death energy stored.");

    if (is_undead(tgt))
      FAIL("You cannot use that against the undead!");

    if (tgt == tp)
      FAIL("Your magic fails.");

    if (!tp->kill_ob(tgt))
      FAIL("You may not attack "+tgt->query_cap_name()+".");
  }
  else if (!tgt->query_corpse())
    FAIL("That's not alive and not a corpse.");
    
  return 1;
}

int cmd_deathtouch(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  int dmg, cost, rank;
  int charge;

  if (!spell()) return 0;

  if (str)
    tgt=present(str, env);

  if (!can_cast(tp, tgt)) return 0;

  if (tgt->query_corpse()) {

    charge = tgt->query_level();
    charge *= 0.7;
    charge += tp->query(DEATHTOUCH_PROP);
    if (charge > tp->query_level()*4)
      charge = tp->query_level()*4;

    tp->set(DEATHTOUCH_PROP, charge);
    tp->add_mp(-(tgt->query_level()/2));
    tp->set_magic_round();

    who += ({tp});
    set_heart_beat(3);

    message("magic", COL+"You touch the corpse, "+COL2+"drawing out"+COL+
                     " the power of its death."+RES, tp);
    message("magic", COL+tp->query_cap_name()+" touches the corpse and "+
                     COL2+"draws out"+COL+" some power.", env, tp);
    message("magic", "The corpse turns to dust and blows away.", env);

    tgt->remove();
  }

  else {

    if (tp->query_level() >= 45) rank=4;
    else if (tp->query_level() >= 32) rank=3;
    else rank=2;
    
    dmg = BALANCE3_D->get_damage(tp, tgt, rank,
      ({ "necromancy", "necromancy", "magic attack" }),
      ({ "intelligence", "intelligence", "wisdom" }),
      ({ "necromancy" }) );
      
    charge = tp->query(DEATHTOUCH_PROP);
    if (charge > tp->query_level()*2)
      charge = tp->query_level()*2;

    tp->set(DEATHTOUCH_PROP, tp->query(DEATHTOUCH_PROP)-charge);
    // multiply by random between 4.0 and 6.0
    dmg += charge*(to_float(random(21)+40)/10.0);

    cost = dmg/12.6;

    if (tp->query_mp() < cost)
      FAIL("Your magic is too low.");

    message("magic", COL+"You "+COL2+"touch"+COL+" "+tgt->query_cap_name()+
                     " and send the "+COL2+"pain of death"+COL+" flooding "
                     "through "+tgt->query_objective()+"!"+RES, tp);
    message("magic", COL+tp->query_cap_name()+" "+COL2+"touches"+COL+" you "
                     "and sends the "+COL2+"pain of death"+COL+" flooding "
                     "through your body!"+RES, tgt);
    message("magic", COL+tp->query_cap_name()+" "+COL2+"touches"+COL+
                     tgt->query_cap_name()+
                     "and sends the "+COL2+"pain of death"+COL+" flooding "
                     "through "+tgt->query_objective()+"!"+RES,
                     env, ({tp, tgt}) );

    tp->add_mp(-(cost+random(cost/8)));
    tp->set_casting(dmg);
    
  }
 
  tp->add_alignment(-1);
  
  return 1;
}

void heart_beat() {
  foreach (object p in who) {
    int charge;
    if (!p ||
        !(charge = p->query(DEATHTOUCH_PROP)) ||
        !(charge -= p->query_level()/10))
          who -= ({p});
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

