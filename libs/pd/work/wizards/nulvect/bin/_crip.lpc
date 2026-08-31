
#include <std.h>
#include <daemons.h>

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
    "even their fists.\n"
    "This can only be done when you're not in combat.",
    this_player() );
}

string type() { return "attack"; }

int can_cast(object tp, object tgt, object wep, string limb) {

  if (!tp) return 0;

  if (tp->query_ghost())
    FAIL("You can't do that as a ghost.\n");

  if (environment(tp)->query_property("no attack"))
    FAIL("You may not attack here.\n");

  if (tp->query_rest_type())
    FAIL("You must be standing to do that.\n");

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

  if (userp(tgt) && !interactive(tgt))
    FAIL("You may not attack link-dead players.\n");
  
  return 1;
}

int cmd_crip(string str) {
  object tp=this_player();
  object tgt;
  object wep;
  object *weps;
  string name, limb;
  int caught=0;

  if (!abil()) return 0;

  if (str && sscanf(str, "%s %s", name, limb) != 2)
    name = str;

  if (name)
    tgt = present(name, environment(tp));

  weps = filter(tp->query_wielded(),
    (: member_array($1->query_type(), ({ "blunt", "knife" }) ) != -1 :)
  );
  if (sizeof(weps)) {
    weps = sort_array(weps, (: $1->query_wc() > $2->query_wc() ? -1 : 1 :) );
    wep = weps[0];
  }

  if (!can_cast(tp, tgt, wep, limb)) return 0;
  
  if (tgt->query_skill("perception") + tgt->query_stats("wisdom") >
      tp->query_skill("stealth") + tp->query_stats("dexterity")/3) {
        message("combat", tp->query_cap_name()+" attempts to sneak behind "
                          "you unnoticed!", tgt);
        caught = tgt->query_skill("perception")-tp->query_skill("stealth");
        if (caught < 10) caught=10;
  }

  tp->set_paralyzed(1, "You are concentrating on crippling "+
                       tgt->query_cap_name()+"!");

  message("combat", "You "+COL+"sneak"+RES+" around "+COL+"behind"+RES+" "+
                    tgt->query_cap_name()+".", tp);

  tp->add_alignment(-5);
  
  call_out("do_dmg", 2, ({tp, tgt, caught, limb, wep}) );

  return 1;

}

void do_dmg(mixed *args) {
  object tp=args[0];
  object tgt=args[1];
  int caught=args[2];
  string limb=args[3];
  object wep=args[4];
  object env;
  string skill;
  string mymsg, yourmsg, othermsg;
  int dmg, rank, mod;
  int bodydam;
  int dex;
  mapping hits = ([
    "blunt" : ([
      ({ "head", "leg" }) : 6,
      ({ "foot", "hand", "wing", "paw" }) : 5,
      ({ "arm", "tail" }) : 4,
      ({ "torso", "abdomen" }) : 3,
      ({ "horn", "teeth", "fang", "hoof", "claw" }) : 2,
    ]),
    "knife" : ([
      ({ "torso", "abdomen", "tail", "wing" }) : 6,
      ({ "arm", "leg", "paw" }) : 5,
      ({ "hand" }) : 3,
      ({ "head", "foot" }) : 2,
      ({ "horn", "teeth", "fang", "hoof", "claw" }) : 1,
    ]),
    "melee" : ([
      ({ "arm", "leg", "hand" }) : 6,
      ({ "paw", "wing", "tail" }) : 5,
      ({ "head" }) : 4,
      ({ "torso", "abdomen", "foot" }) : 3,
      ({ "horn", "teeth", "fang", "hoof", "claw" }) : 1,
    ]),
  ]);
      
  if (!tp) return;
  
  env=environment(tp);

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

  if (wep) skill = wep->query_type();
  else skill = "melee";

  foreach (string *limbs, int x in hits[skill])
    if (regexp(limb, implode(limbs, "|"))) mod = x;

  if (!mod) mod = 2;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
          ({"murder", skill, skill, "attack" }),
          ({"strength", "strength", "dexterity"}),
          ({"strength", "dexterity"}) );

  dmg -= caught*3;

  switch (skill) {
    default:
      mymsg = "Your blow "+COL+"smashes"+RES+" into "+tgt->query_cap_name()+"'s "+
              limb+"!";
      yourmsg = tp->query_cap_name()+" "+COL+"smashes"+RES+" into your "+limb+
              " with "+tp->query_possessive()+" fist!";
    case "melee":
    break;
    case "blunt":
    break;
    case "knife":
    break;
  }

  message("combat", mymsg, tp);
  message("combat", yourmsg, tgt);
  if (othermsg)
    message("combat", othermsg, env, ({ tp, tgt }) );

  if (userp(tp) && userp(tgt)) {
    if (mod > 5) mod = 5;
  }
  else if (tgt->query_level() > tp->query_level()-5)
    mod -= 1+random((tgt->query_level() - (tp->query_level()-5))/3);

  mod += (tp->query_stats("strength")-20)/(tgt->query_stats("constitution"));

  if (tgt->query_reference(limb) == "FATAL")
    mod -= 1;
  
  mod -= random(2);
  
  bodydam = tgt->query_max_dam(limb)*mod/7;
  
  tgt->heal_limb(limb, -bodydam);
  tgt->do_damage(limb, dmg);

  tp->add_sp(-(dmg/20));

  tp->add_skill_points("murder", dmg/50);
  tp->add_skill_points("attack", dmg/50);
  tp->add_skill_points(skill, dmg/50);
  
  if (tgt->query_hp() < 1)
    tgt->heart_beat();

}

