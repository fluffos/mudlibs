#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define FAIL(s) return notify_fail(s+"\n");
#define COL "%^RED%^"
#define RES "%^RESET%^"

#define PIN_PROP "pin_abil_info"
#define PIN_TIME 16

inherit DAEMON;

object *who = ({});

int abil() {
  object tp=this_player();
  if (tp &&
      member_array(tp->query_subclass(), ({"thief","assassin"}) ) != -1 &&
      tp->query_skill("knife") >= 25*5 &&
      tp->query_skill("agility") >= 25*6 &&
      tp->query_skill("murder") >= 100)
    // level 25 assassins, 30 thieves
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help","\n"
    "Syntax: <pin [living] (hand|foot)>\n\n"
    "A nasty ability that assassins and even some thieves practice, "
    "this attack aims to put a dagger through your enemy's hand or foot, "
    "rendering it useless for a while.",
    this_player());
}

int ok_cast(object tp, object tgt, object *weps, string what, string *limbs) {

  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot do that here.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You're a little too dead to be hurting anyone right now.");

  if (tp->query_rest_type())
    FAIL("You must be standing to do that.");
  
  if (!tgt)
    FAIL("Pin who?");

  if (!living(tgt))
    FAIL("That is not alive.");

  if (tp == tgt)
    FAIL("You cannot attack yourself.");

  if (!sizeof(weps))
    FAIL("You need to use a knife for that.");

  if (!sizeof(limbs))
    FAIL(capitalize(tgt->query_subjective())+
         " doesn't have a "+what+" to pin!");

  if (!tp->kill_ob(tgt))
    FAIL("That cannot be attacked by you yet.");

  return 1;
}

int cmd_pin(string str) {
  object tp=this_player();
  object tgt, tgtwep;
  object *weps;
  string wep;
  string *limbs;
  int cost, dmg, rank, hit, miss, tmp;
  mapping pin_info;
  string name, what;

  if (!abil()) return 0;

  if (str) {
    if ((tmp = strsrch(str, "hand", -1)) != -1)
      what = "hand";
    else if ((tmp = strsrch(str, "foot", -1)) != -1)
      what = "foot";
    if (what)
      name = str[0..tmp-2];
  }

  if (!name) tgt=tp->query_current_attacker();
  else tgt=present(name,environment(tp));

  weps = filter(tp->query_wielded(), (: $1->query_type() == "knife" :) );
  
  if (tgt) {
    if (!what) {
      if (random(100) < 50) what = "hand";
      else what = "foot";
    }
    if (what == "hand") {
      limbs=tgt->query_limbs_wielded();
      if (!sizeof(limbs))
        limbs=tgt->query_wielding_limbs();
    }
    else if (what == "foot") {
      limbs = tgt->query_walking_limbs();
    }
    limbs -= tgt->query_crippled();
  }

  if (!ok_cast(tp,tgt,weps,what,limbs)) return 0;

  rank=2;
  
  dmg=BALANCE3_D->get_damage(tp, tgt, rank,
        ({ "knife", "murder", "agility" }),
        ({ "dexterity" }) );
  
  dmg = dmg/2;

  cost = BALANCE3_D->get_cost(dmg, rank, "sp") * 120 / 100;
  
  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  tp->set_disable(1);
  tp->add_sp(-(cost+random(cost/10)));

  // this is very tricky - not sure if we're going to hit or miss yet,
  // so don't do pin_info = query(PIN_PROP), it would always change the prop
  // but addition creates a new mapping so it's ok
  pin_info = ([ limbs[0] : time()+PIN_TIME ]);
  if (sizeof(tgt->query(PIN_PROP)))
    pin_info = tgt->query(PIN_PROP) + pin_info;

  hit = tp->query_stats("dexterity")*2/3;
  hit += tp->query_skill("agility")/5;
  hit += random(20);
  miss = tgt->query_stats("dexterity")/2;
  miss += tgt->query_skill("defense")/3;
  miss += (sizeof(pin_info)-1)*45;

  if (hit < miss) {

    message("combat", "You miss your attempt to pin "+tgt->query_cap_name()+
                      "'s "+limbs[0]+" with your knife.", tp);

    message("combat", tp->query_cap_name()+" misses an attempt "
                      "to stab "+tgt->query_cap_name()+".",
                      environment(tp), ({ tp, tgt }) );
    
    message("combat", tp->query_cap_name()+" misses an attempt "
                      "to stab you.", tgt);

    return 1;
  }

  message("combat","You "+COL+"stab"+RES+" your dagger into "+
                   tgt->query_cap_name()+"'s "+COL+limbs[0]+RES+"!", tp);
  
  message("combat",tp->query_cap_name()+" "+COL+"stabs"+RES+" "+
                   tp->query_possessive()+" dagger into your "+
                   COL+limbs[0]+RES+"!\n"
                   "Your "+limbs[0]+" goes limp and numb with pain!", tgt);

  message("combat",tp->query_cap_name()+" "+COL+"stabs"+RES+" "+
                   tp->query_possessive()+" dagger into "+
                   tgt->query_cap_name()+"'s "+COL+limbs[0]+RES+"!",
                   environment(tp), ({ tp, tgt }) );

  tgt->do_damage(limbs[0], dmg, DAMAGE_PHYSICAL | DAMAGE_PIERCE, DAMAGE_NO_SEVER, tp);

  if (tgtwep=tgt->query_weapon(limbs[0])) {
    tgtwep->unequip();
    message("combat", "You drop your "+tgtwep->query_name()+".", tgt);
    message("combat", tgt->query_cap_name()+" drops "+tgt->query_possessive()+
                      " "+tgtwep->query_name()+".", environment(tgt), tgt);
    tgtwep->move(environment(tgt));
  }

  // if the limb got severed from damage, don't even bother with this part...
  if (tgt->query_is_limb(limbs[0])) {
    tgt->set_crippled(limbs[0], -1);
    tgt->set(PIN_PROP, pin_info);
    who += ({ tgt });
    set_heart_beat(5);
  }
  
  return 1;
}

void heart_beat() {
  foreach (object p in who) {
    mapping prop;
    if (!p) {
      who -= ({ p });
      continue;
    }
    prop = p->query(PIN_PROP);
    foreach (string limb, int time in prop) {
      if (!p->query_is_limb(limb))
        map_delete(prop, limb);
      else if (time < time()) {
        map_delete(prop, limb);
        p->remove_crippled(limb);
        //message("info", "You feel like you can use your "+limb+" again.", p);
      }
    }
    p->set(PIN_PROP, prop);
    if (!sizeof(prop))
      who -= ({ p });
  }
  if (!sizeof(who)) set_heart_beat(0);
}

