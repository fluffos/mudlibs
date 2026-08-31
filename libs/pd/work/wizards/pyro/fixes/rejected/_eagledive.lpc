
#include <std.h>
#include <rooms.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n")
#define RETFAIL(s) return message("info", s, tp)

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^GREEN%^"
#define COL2 "%^BOLD%^%^BLUE%^"

inherit DAEMON;

mapping weapons = ([
  "knife" : ([
    "color" : "%^RED%^",
    "wcmod" : 3,
  ]),
  "ranged" : ([
    "color" : "%^GREEN%^",
    "wcmod" : 20,
  ]),
]);

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "scout" &&
      tp->query_skill("agility") >= 9*5)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <eagledive [who] [direction]>\n\n"
    "A quick scout who is aware of his surroundings can leap "
    "at an enemy from another area, landing a deadly attack "
    "if timed correctly.",
    this_player() );
}

int can_cast(object tp, object tgt, string dir, string from) {

  object env;
  string tmp;

  if (!tp) return 0;

  env = environment(tp);

  if (env->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your body is too insubstantial.");

  // note that I'm not checking to make sure the other room exists because
  // if it didn't, we wouldn't have tgt set here so it would fail anyway
  if (!tgt)
    FAIL("Eagledive at whom?");

  if (!living(tgt))
    FAIL("That isn't alive.");

  if (tgt == tp)
    FAIL("Completely impossible.");

  if (environment(tgt)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_rest_type())
    FAIL("You need to stand up before you can run.");

  if (tp->query_riding())
    FAIL("You must dismount first.");

  if (!strlen(dir))
    FAIL("Eagledive in which direction?");

  if (dir == "up" || dir == "down")
    FAIL("That would be far too dangerous.");

  if (!strlen(from))
    FAIL("You can't run in that direction.");

  if (tp->clean_up_attackers())
    FAIL("You are too busy fighting!");

  if (userp(tgt) && !interactive(tgt))
    FAIL("You cannot attack a link-dead player.");

  if (!tp->ok_to_kill(tgt))
    FAIL("You may not attack "+tgt->query_cap_name()+".");

  if (tp->query_sp() < 50)
    FAIL("You are too tired.");

  /*
  if (strlen(tmp = env->query_door(dir)) && !env->query_open(tmp))
    FAIL("Your way is blocked by the closed "+tmp+".");
  */

  if (strlen(tmp = env->query_door(dir)))
    FAIL("It would be far too dangerous to leap through the "+tmp+".");

  if (!env->perform_pre_exits(dir))
    return 0;

  return 1;
}

int cmd_eagledive(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt, tgtenv;
  string tgtname, dir = "";
  mixed tmp;

  if (!abil()) return 0;

  // last word is the exit name, exits cannot contain spaces
  if (str && (tmp = strsrch(str, " ", -1)) != -1) {
    tgtname = str[0..tmp-1];
    dir = str[tmp+1..<1];
  }

  if(strlen(dir) && strlen(tmp = env->query_exit(dir))) {
    load_object(tmp);
    if(tmp != ROOM_VOID && objectp(tgtenv = find_object(tmp)) && strlen(tgtname))
        tgt = present(tgtname, tgtenv);
  }

  switch (dir) {
    case "east": tmp = "west"; break;
    case "west": tmp = "east"; break;
    case "north": tmp = "south"; break;
    case "south": tmp = "north"; break;
    case "northeast": tmp = "southwest"; break;
    case "northwest": tmp = "southeast"; break;
    case "southwest": tmp = "northeast"; break;
    case "southeast": tmp = "northwest"; break;
    default: tmp = "";
  }

  if (!can_cast(tp, tgt, dir, tmp)) return 0;

  message("combat", "You start "+COL+"running"+RES+" to the "+dir+".", tp);
  message("combat", tp->query_cap_name()+" sprints to the "+dir+".",
      env, tp);
  tp->add_sp(-5);
  tp->set_paralyzed(6, "You are running!");
  call_out("do_jump", 1, ({ tp, tgt, env, tgtenv, dir, (string)tmp }) );

  return 1;
}

void do_jump(mixed *args) {
  object tp = args[0];
  object oldenv = args[2];
  object newenv = args[3];
  string dir = args[4];

  if (!tp) return;

  if (!newenv || environment(tp) != oldenv) {
    tp->remove_paralyzed();
    RETFAIL("Your attack was interrupted.");
  }

  message("combat", "You "+COL+"leap"+RES+" off the ground and "+COL+"fly"+RES+
      " to the "+dir+"!", tp);
  message("combat", tp->query_cap_name()+" "+COL+"leaps"+RES+" off the ground and "+
      COL+"flies"+RES+" to the "+dir+"!", oldenv, tp);

  tp->add_sp(-5);
  call_out("do_hit", 1, args);
}

void do_hit(mixed *args) {
  object tp = args[0];
  object tgt = args[1];
  object oldenv = args[2];
  object newenv = args[3];
  string dir = args[4];
  string from = args[5];
  object *weps = ({}), *quivers;
  string *skills, *limbs;
  string limb;
  int rank, dmg, cost, hit, miss=0, tmp;

  if (!tp) return;

  tp->remove_paralyzed();

  if (!newenv || environment(tp) != oldenv)
    RETFAIL("Ack!");

  if (tp->move(newenv))
    RETFAIL("Can't move!");

  oldenv->add_tracks(dir, tp);
  oldenv->perform_post_exits(dir);

  message("info", tp->query_cap_name()+" comes "+COL+"flying"+RES+" in from "
      "the "+from+"!", newenv, tp);

  if (!tgt || !present(tgt, newenv))
    RETFAIL("Your target has eluded you!");
  
  // do this before kill_ob, since kill_ob puts him on our attacker list
  if (member_array(tgt, tp->query_attackers()) != -1 ||
      member_array(tgt, tp->query_hunted()) != -1 ||
      tgt->query_stats("dexterity")/2 + random(tgt->query_stats("dexterity")/2) >
      tp->query_stats("dexterity")+5)
        miss = 1000;

  if (!tp->kill_ob(tgt))
    RETFAIL("You cannot attack "+tgt->query_cap_name()+".");

  switch (tp->query_level()) {
    case 1..20: rank = 2; break;
    case 21..40: rank = 3; break;
    default: rank = 4;
  }

  if (tp->query_skill("knife") >= 25*6)
    weps += filter(tp->query_wielded(), (: $1->query_type() == "knife" :) );
  if (tp->query_skill("ranged") >= 25*4)
    weps += filter(tp->query_wielded(), (: $1->query_type() == "ranged" :) );

  // if wielding any bows, check for arrows needed...
  // for each arrow we're short, remove a bow from the weapons list
  // this move will hit without weapons so we don't RETFAIL here
  // done this way to take into account races with > 2 hands
  tmp = sizeof(filter(weps, (: $1->query_type() == "ranged" :) ));
  if (tmp) {
    quivers = filter(all_inventory(tp),
        (: ($1->is_quiver() && $1->query_arrows()) :)
    );
    foreach (object q in quivers)
      tmp -= q->query_arrows();
    for (; tmp > 0; tmp--)
      weps = weps[0..<1];
  }

  hit = tp->query_skill("perception");
  hit += tp->query_skill("agility")*3/4;
  hit += tp->query_stats("dexterity")*2;
  
  miss += tgt->query_skill("agility");
  miss += tgt->query_skill("defense")/2;
  miss += tgt->query_stats("dexterity")*2;

  if (miss+random(miss/6) > hit+random(hit/6)) {
    message("combat", "You miss your attack on "+tgt->query_cap_name()+"!", tp);
    message("combat", tp->query_cap_name()+" misses "+tp->query_possessive()+
      "attack on you!", tgt);
    message("combat", tp->query_cap_name()+" misses an attack on "+
      tgt->query_cap_name()+"!", newenv, ({ tp, tgt }) );
    return;
  }

  skills = ({ "perception", "agility" });
  if (sizeof(weps))
    skills += weps->query_type();
  else
    skills += ({ "attack" });

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    skills,
    ({ "dexterity", "dexterity", "strength" }),
    ({ "dexterity" }) );

  dmg *= 1.8;

  cost = log(pow(dmg, 4))*5/(6-rank) - 10;
  tp->add_sp(-cost);

  limbs = regexp(tgt->query_limbs(), "torso|body|head|arm");
  limb = limbs[random(sizeof(limbs))];

  message("combat", "You land a "+COL2+"kick"+RES+" to "+
    tgt->query_cap_name()+"'s "+limb+"!", tp);
  message("combat", tp->query_cap_name()+" lands a "+COL2+"kick"+RES+
    " to your "+limb+"!", tgt);
  message("combat", tp->query_cap_name()+" lands a "+COL2+"kick"+RES+" to "+
    tgt->query_cap_name()+"'s "+limb+"!", newenv, ({ tp, tgt }) );
  
  foreach (object w in weps) {
    string type = w->query_type();
    string color = weapons[type]["color"];
    dmg += w->query_wc()*weapons[type]["wcmod"];
    switch (type) {
      case "knife":
        message("combat", "You "+color+"plunge"+RES+" your "+w->query_name()+
          " into "+tgt->query_objective()+"!", tp);
        message("combat", tp->query_cap_name()+" "+color+"plunges"+RES+
          " "+tp->query_possessive()+" "+w->query_name()+" into you!", tgt);
        message("combat", tp->query_cap_name()+" "+color+"plunges"+RES+
          " "+tp->query_possessive()+" "+w->query_name()+
          " into "+tgt->query_objective()+"!", newenv, ({ tp, tgt }) );
      break;
      case "ranged":
        message("combat", "You "+color+"loose"+RES+" an arrow into "+
          tgt->query_objective()+"!",tp);
        message("combat", tp->query_cap_name()+" "+color+"looses"+RES+
          " an arrow into you!", tgt);
        message("combat", tp->query_cap_name()+" "+color+"looses"+RES+
          " an arrow into "+tgt->query_objective()+"!", newenv, ({ tp, tgt }) );
        foreach (object q in quivers)
          if (q->use_arrow())
            break;
      break;
    }
    tp->add_skill_points(type, dmg/30);
  }

  tp->add_skill_points("agility", dmg/20);
  tp->add_skill_points("perception", dmg/20);

  tgt->do_damage(limb, dmg);
  if (tgt->query_hp() < 1)
    tgt->heart_beat();

}
