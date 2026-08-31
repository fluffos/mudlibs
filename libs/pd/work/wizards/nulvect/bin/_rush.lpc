
#include <std.h>
#include <daemons.h>

#define COL2 "%^BOLD%^%^BLUE%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n")

#define RUSH_PROP "rush_abil_time"
// delay is in rounds
#define RUSH_DELAY 5

inherit DAEMON;

mapping colors = ([
  "axe" : "%^BOLD%^%^RED%^",
  "blade" : "%^BOLD%^%^WHITE%^",
  "blunt" : "%^ORANGE%^",
  "flail" : "%^MAGENTA%^",
  "knife" : "%^RED%^",
  "projectile" : "%^YELLOW%^",
  "melee" : "%^WHITE%^",
]);

mapping races = ([
  "centaur" : 
  ([ "charging" : 1,
     "limbs" : ({"left fore hoof", "right fore hoof",
                   "left rear hoof", "right rear hoof",
                   "left foreleg", "right foreleg",
                   "left rear leg", "right rear leg"}) ]),
  "raknid" :
  ([ "charging" : 1,
     "limbs" : ({"left foreleg", "right foreleg",
                   "left rear leg", "right rear leg"}) ]),
  "weimic" :
  ([ "charging" : 1,
     "limbs" : ({"left front claw", "right front claw",
                   "left rear claw", "right rear claw",
                   "left foreleg", "right foreleg",
                   "left rear leg", "right rear leg"}) ]),
  "bastet" : 
  ([ "charging" : 0,
     "limbs" : ({"left rear paw", "right rear paw",
                 "left leg", "right leg"}) ]),
  "minotaur" : 
  ([ "charging" : 0,
     "limbs" : ({"left hoof", "right hoof",
                 "left leg", "right leg"}) ]),
  "default" : 
  ([ "charging" : 0,
     "limbs" : ({"left foot", "right foot",
                 "left leg", "right leg"}) ]),
]);

int abil() {
  object tp=this_player();
  if (member_array(tp->query_subclass(),
      ({"warrior","berserker","paladin","antipaladin"}) ) != -1 &&
      tp->query_skill("attack") >= 12*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <rush [whom]>\n\n"
    "This attack lets the combatant rush down his opponent "
    "and use his momentum to strike a very strong blow. "
    "Most fighters learn it.",
    this_player() );
}

int can_cast(object tp, object tgt, string *limbs) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("You may not attack here.");
  
  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your immaterial form would pass right through.");

  if (!tgt)
    FAIL("Rush at whom?");

  if (!living(tgt))
    FAIL("You rush at it, but it doesn't flinch.");

  if (tgt == tp)
    FAIL("You really just had to try, didn't you?");

  if (tp->query_rest_type())
    FAIL("You must stand up first!");

  if (tp->query_riding())
    FAIL("You can't rush while riding something!");

  foreach (string l in limbs)
    if (member_array(l, tp->query_severed_limbs()) != -1)
      FAIL("You would need your "+l+" to rush!");
  
  if (tp->query(RUSH_PROP)+RUSH_DELAY*2 > time()) {
    if (tp->query_current_attacker())
      FAIL("You don't yet have enough room to rush again.");
    else
      FAIL("You need to rest a minute before rushing again.");
  }
  
  if (!tp->kill_ob(tgt))
    FAIL("You cannot attack "+tgt->query_subjective()+".");
  
  return 1;
}

int cmd_rush(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  int rank, dmg, cost, wc, miss;
  string *weps;
  string type;
  mapping raceinfo;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (member_array(tp->query_race(), keys(races)) != -1)
    raceinfo = races[tp->query_race()];
  else
    raceinfo = races["default"];

  if (!can_cast(tp, tgt, raceinfo["limbs"])) return 0;

  weps = filter(tp->query_wielded(), (: $1->query_type() != "ranged" :) );
  if (sizeof(weps)) {
    weps = sort_array(weps,
      function (object a, object b) {
        int awc = a->query_wc();
        int bwc = b->query_wc();
        if (awc > bwc) return -1;
        else if (bwc > awc) return 1;
        else return 0;
      }
    );
    type = weps[0]->query_type();
    wc = weps[0]->query_wc();
  }
  else {
    type = "melee";
    wc = 5+tp->query_skill("melee")/30;
  }

  if (tp->query_level() >= 25)
    rank = 3;
  else
    rank = 2;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({ "attack", type }),
    ({ "strength", "dexterity" }),
    ({ "strength", "strength", "dexterity" }) );

  dmg *= 2.5;

  if (raceinfo["charging"])
    dmg += (dmg/5.8)*(tp->query_skill("charging")/(5*tp->query_level()));

  dmg += wc*8;

  cost = dmg/10.5;

  if (tp->query_sp() < cost/2)
    FAIL("You are too tired.");

  if (tgt->query_stats("dexterity")*1.2 > tp->query_stats("dexterity"))
    miss=1;

  message("combat", "You "+COL2+"rush"+RES+" towards "+
                    tgt->query_cap_name()+"!", tp);
  message("combat", tp->query_cap_name()+" "+COL2+"rushes"+RES+
                    " towards you!", tgt);
  message("combat", tp->query_cap_name()+" "+COL2+"rushes"+RES+
                    " towards "+tgt->query_cap_name()+"!", env, ({ tp, tgt }) );

  tp->set_disable();
  tp->add_sp(-(cost/2));

  call_out("rush_hit", 1, ({ tp, tgt, type, miss, dmg, cost }) );

  return 1;
}

void rush_hit(mixed *args) {
  object tp=args[0];
  object tgt=args[1];
  string type=args[2];
  int miss=args[3];
  int dmg=args[4];
  int cost=args[5];
  
  object env;
  string col, verb, what;

  if (!tp) return;

  env = environment(tp);
  
  if (!tgt || environment(tgt) != env) {
    message("combat", "Your opponent is gone!", tp);
    return;
  }
  
  col=colors[type];
  if (type == "melee")
    what = "body";
  else
    what = "weapon";
  switch (type) {
    case "melee":
    case "blunt":
      verb = "slams"; break;
    case "axe":
    case "blade":
      verb = "cleaves"; break;
    case "knife":
    case "projectile":
      verb = "tears"; break;
    case "flail":
      verb = "cuts"; break;
  }

  if (miss) {  
    message("combat", "You just miss your attack!", tp);
    message("combat", tp->query_cap_name()+" just misses "+
                      tp->query_possessive()+" attack!", env, tp);
  }
  else {
    message("combat", "Your "+what+" "+col+verb+RES+" "
                      "s"+COL2+"a"+RES+"v"+col+"a"+RES+"g"+COL2+"e"+RES+"l"+COL2+"y"+RES+
                      " into "+tgt->query_cap_name()+"!", tp);
    message("combat", tp->query_cap_name()+"'s "+what+" "+col+verb+RES+" "
                      "s"+COL2+"a"+RES+"v"+col+"a"+RES+"g"+COL2+"e"+RES+"l"+COL2+"y"+RES+
                      " into you!", tgt);
    message("combat", tp->query_cap_name()+"'s "+what+" "+col+verb+RES+" "
                      "s"+COL2+"a"+RES+"v"+col+"a"+RES+"g"+COL2+"e"+RES+"l"+COL2+"y"+RES+
                      " into "+tgt->query_cap_name()+"!", env, ({tp, tgt}) );
    tgt->do_damage(tgt->return_target_limb(), dmg);
    tp->add_sp(-(cost/2));
  }

  tp->set_disable();
  tp->set(RUSH_PROP, time());
  
}

