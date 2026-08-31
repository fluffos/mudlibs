
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define COL "%^BLUE%^"
#define COL2 "%^BOLD%^%^RED%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s);

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "thug" &&
      tp->query_skill("murder") >= 25*5)
        return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <cripple [living] [limb]>\n\n"
    "An attempt to sneak behind someone and cause massive trauma to "
    "a specific body part. Thugs can use knives, blunt objects, or "
    "even their fists, but each one is best suited to hit different parts.\n"
    "This can only be done when you're not in combat.",
    this_player() );
}

string type() { return "attack"; }

int can_cast(object tp, object tgt, object wep, string limb) {

  if (!tp) return 0;

  if (tp->query_ghost())
    FAIL("You can't do that as a ghost.\n");

  if (tp->query_busy())
    FAIL("You are busy.\n");

  if (environment(tp)->query_property("no attack"))
    FAIL("You may not attack here.\n");

  if (tp->query_rest_type())
    FAIL("You must be standing to do that.\n");

  if (tp->query_riding())
    FAIL("You can't sneak around while riding.");

  if (sizeof(tp->query_riders()))
    FAIL("You can't sneak around with people riding on your back.");

  if (!tgt)
    FAIL("Cripple whom?\n");

  if (!limb)
    FAIL("Aim for what limb?\n");

  if (!living(tgt))
    FAIL("That is not alive.\n");

  if (tgt == tp)
    FAIL("You try to hit yourself, but just look stupid doing it.\n");

  if (!wep && sizeof(tp->query_limbs_wielded()) == sizeof(tp->query_wielding_limbs()))
    FAIL("You're not using the right weapons.\n");

  if (tp->query_current_attacker())
    FAIL("You are too busy fighting!\n");

  if (member_array(tgt, tp->query_hunted()) != -1)
    FAIL("You have lost the element of surprise!\n");

  if (!(tgt->query_is_limb(limb)))
    FAIL(tgt->query_subjective()+" does not have "+a_or_an(limb)+" "+limb+".\n");

  if (tp->query_sp() < 25)
    FAIL("You are too tired.\n");
  
  if (userp(tgt) && !interactive(tgt))
    FAIL("You may not attack link-dead players.\n");
  
  return 1;
}

int cmd_cripple(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  object wep;
  object *weps;
  string name, limb;
  int caught=0;

  if (!abil()) return 0;

  // both the limb name and the monster identifier can have spaces in them,
  // so start searching from the second-to-last word given for a monster
  // example: cripple stupid goblin 2 right leg
  // first looks for stupid goblin 2 right,
  // then stupid goblin 2 - bingo, found it.. so right leg is the limb
  if (str) {
    string *tmp = explode(str, " ");
    int i = sizeof(tmp);
    if (i == 1)
      tgt = present(str, env);
    else {
      for (i -= 2; i >= 0; i--) {
        if (tgt = present(implode(tmp[0..i], " "), env)) {
          limb = implode(tmp[i+1..<1], " ");
          break;
        }
      }
    }
  }

  weps = filter(tp->query_wielded(),
    (: member_array($1->query_type(), ({ "blunt", "knife" }) ) != -1 :)
  );
  if (sizeof(weps)) {
    weps = sort_array(weps, (: $1->query_wc() > $2->query_wc() ? -1 : 1 :) );
    wep = weps[0];
  }

  if (!can_cast(tp, tgt, wep, limb)) return 0;
  
  if (tgt->query_skill("perception") + tgt->query_stats("wisdom")/2 + tgt->query_stats("intelligence")/2 >
      tp->query_skill("stealth") + tp->query_stats("dexterity")*2/3) {
        message("combat", tp->query_cap_name()+" attempts to sneak behind "
                          "you unnoticed!", tgt);
        caught = tgt->query_skill("perception")-tp->query_skill("stealth");
        if (caught < 10) caught=10;
  }

  tp->set_paralyzed(4, "You are concentrating on crippling "+
                       tgt->query_cap_name()+"!");

  message("combat", "You "+COL+"sneak"+RES+" around "+COL+"behind"+RES+" "+
                    tgt->query_cap_name()+".", tp);

  tp->add_alignment(-5);
  tp->add_sp(-5);
  
  call_out("do_dmg", 2, ({tp, tgt, caught, limb, wep, env}) );

  return 1;

}

void do_dmg(mixed *args) {
  object tp=args[0];
  object tgt=args[1];
  int caught=args[2];
  string limb=args[3];
  object wep=args[4];
  object oldenv=args[5];
  object env;
  string skill;
  string mymsg, yourmsg, othermsg;
  int dmg, rank, mod;
  int bodydam;
  int wc;
  int dtype;
  mapping hits = ([
    "blunt" : ([
      ({ "head", "leg" }) : 6,
      ({ "foot", "hand", "wing", "paw" }) : 5,
      ({ "arm", "tail" }) : 4,
      ({ "torso", "body", "abdomen" }) : 3,
      ({ "horn", "teeth", "fang", "hoof", "claw" }) : 2,
    ]),
    "knife" : ([
      ({ "tail", "wing" }) : 6,
      ({ "torso", "body", "abdomen", "arm", "leg", "paw" }) : 5,
      ({ "hand" }) : 3,
      ({ "head", "foot" }) : 2,
      ({ "horn", "teeth", "fang", "hoof", "claw" }) : 1,
    ]),
    "melee" : ([
      ({ "arm", "leg", "hand" }) : 6,
      ({ "paw", "wing", "tail" }) : 5,
      ({ "head" }) : 4,
      ({ "torso", "body", "abdomen", "foot" }) : 3,
      ({ "horn", "teeth", "fang", "hoof", "claw" }) : 1,
    ]),
  ]);
      
  if (!tp) return;

  tp->set_paralyzed(0);
  
  env=environment(tp);

  if (oldenv != env) {
    message("info", "Your attack has been interrupted!", tp);
    return;
  }

  if (!tgt || environment(tgt) != env ||
      (userp(tgt) && !interactive(tgt))) {
        message("info", "Your target is not here.", tp);
        return;
  }
  
  if (!(tp->kill_ob(tgt))) {
    message("info", "You may not attack "+tgt->query_objective()+".",tp);
    return;
  }
  
  if (tgt->query_stats("dexterity")/2 + random(tgt->query_stats("dexterity")) >
      tp->query_stats("dexterity")+5-caught) {
        message("combat", "You fail to hit "+tgt->query_cap_name()+"!", tp);
        message("combat", tp->query_cap_name()+" misses a sneak attack "
                          "against you!", tgt);
        message("combat", tp->query_cap_name()+" misses a sneak attack "
                          "against "+tgt->query_cap_name()+"!", env, ({tp,tgt}) );
        return;
  }

  if (tp->query_level() >= 45)
    rank=4;
  else if (tp->query_level() >= 35)
    rank=3;
  else
    rank=2;

  if (wep) {
    dtype = wep->query_damage_type();
    skill = wep->query_type();
    wc = wep->query_wc();
  }
  else {
    dtype = tp->query_unarmed_damage_type();
    skill = "melee";
    wc = tp->query_skill("melee")/20;
  }

  foreach (string *limbs, int x in hits[skill])
    if (regexp(limb, implode(limbs, "|"))) mod = x;

  if (!mod) mod = 2;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
          ({"murder", "murder", skill, skill, "attack" }),
          ({"strength", "strength", "dexterity"}),
          ({"strength", "dexterity"}) );

  dmg -= caught*3;

  dmg += wc*14;

  dmg = dmg * 110 / 100;

  switch (skill) {
    case "melee":
    case "blunt":
      mymsg = "Your blow "+COL2+"smashes"+RES+" into "+tgt->query_cap_name()+"'s "+
              limb+"!";
      yourmsg = "A massive blow suddenly "+COL2+"smashes"+RES+
                " into your "+limb+"!";
    break;
    case "knife":
      mymsg = "Your knife "+COL2+"rips"+RES+" through "+tgt->query_cap_name()+"'s "+
              limb+"!";
      yourmsg = "A sharp blade suddenly "+COL2+"rips"+RES+
                " through your "+limb+"!";
    break;
  }

  message("combat", mymsg, tp);
  message("combat", yourmsg, tgt);
  if (othermsg)
    message("combat", othermsg, env, ({ tp, tgt }) );

  if (userp(tp) && userp(tgt)) {
    if (mod > 5) mod = 5;
  }
  else if (tgt->query_level() > tp->query_level()*0.82)
    mod -= 1+random((tgt->query_level() - (tp->query_level()-5))/3);

  mod += (tp->query_stats("strength")-20)/(tgt->query_stats("constitution"));

  if (tgt->query_reference(limb) == "FATAL") {
    mod -= 1;
    dmg *= 0.85;
  }
  
  //mod -= random(2);
  
  bodydam = tgt->query_max_dam(limb)*mod/7;
  if (mod >= 1) dmg = dmg * (100 + mod*15) / 100;
  
  tgt->do_damage(limb, bodydam, DAMAGE_PHYSICAL | dtype, DAMAGE_NO_HP | DAMAGE_NO_SEVER, tp);
  tgt->do_damage(limb, dmg, DAMAGE_PHYSICAL | dtype, 0, tp);

  tp->add_sp(-(10+BALANCE3_D->get_cost(dmg, rank, "sp") * 120 / 100));

  tp->add_skill_points("murder", dmg/50);
  tp->add_skill_points("attack", dmg/50);
  tp->add_skill_points(skill, dmg/50);
  
  if (tgt->query_hp() < 1)
    tgt->heart_beat();

}

