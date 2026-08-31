#include <std.h>
#include <daemons.h>

#define RES "%^RESET%^"
#define COL "%^WHITE%^"

#define FAIL(s) return notify_fail(s+"\n")

#define SMASH_AREAS ([\
  "indoors" : "a nearby wall",\
  "town" : "a nearby wall",\
  "forest" : "a tree",\
  "mountain" : "a nearby cliff face",\
])

inherit DAEMON;

int abil() {
    object o = this_player();
    if (o && o->query_subclass() == "thug" &&
        o->query_skill("melee") >= 120)
          return 1;
    return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <smash [victim]>\n\n"
    "The thug will grab an opponent by the head and throw him into "
    "the nearest solid object. If no solid object is around, "
    "the attack will fail.",
    this_player() );
}

int can_cast(object tp, object tgt, string where) {
  object env;
  
  if (!tp) return 0;

  env = environment(tp);
  
  if (env->query_property("no attack"))
    FAIL("Some force prevents your violence.");
  
  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");
  
  if (tp->query_ghost())
      FAIL("You appear to be dead.");

  if (!tgt)
    FAIL("Smash who?");

  if (!living(tgt))
    FAIL("Don't waste your time.");
  
  if (tgt == tp)
    FAIL("You run around in circles.");
  
  if (tp->query_rest_type())
    FAIL("You cannot do that while on the ground!");

  if (!strlen(where))
    FAIL("There is nothing around to smash "+
         tgt->query_objective()+" into!");

  if (sizeof(tp->query_wielded()))
    FAIL("Your weapons make it impossible to grab anyone!");
  
  if(!tp->kill_ob(tgt))
     FAIL("You may not attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_mysmash(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int dmg, cost, rank;
  string where, head, what, limb;
   
  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();
   
  foreach (string type in keys(SMASH_AREAS))
    if (env->query_property(type)) {
      where = type;
      break;
    }
   
  if (!can_cast(tp, tgt, where)) return 0;
   
  if (tp->query_level() < 30)
    rank = 2;
  else if (tp->query_level() < 50)
    rank = 3;
  else
    rank = 4;

  dmg = BALANCE3_D->get_damage( tp, tgt, rank,
    ({ "attack", "melee", "melee"}),
    ({ "strength", "strength", "dexterity" }),
    ({ "strength", "dexterity" }) );
  
  //dmg *= 0.9; 
  
  cost = 2.2*log(pow(dmg, 6)) - 30;
   
  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  tp->add_sp(-(cost+random(cost/15)));
  tp->set_disable();

  if (dmg < 30) {
    message("combat", "You fail to grab "+tgt->query_cap_name()+".", tp);
    message("combat", tp->query_cap_name()+" fails to grab you.", tgt);
    message("combat", tp->query_cap_name()+" fails to grab "+
                      tgt->query_cap_name()+".", env, ({ tp, tgt }) );
  }
  else {
    if (tgt->query_is_limb("head")) {
      limb = "head";
      head = " by the head";
    }
    else {
      limb = tgt->return_target_limb();
      head = "";
    }
    
    what = SMASH_AREAS[where];
    
    message("combat", "You grab "+tgt->query_cap_name()+head+
                      " and slam "+tgt->query_objective()+" into "+what+"!", tp);
    message("combat", tp->query_cap_name()+" grabs you"+head+
                      " and slams you into "+what+"!", tgt);
    message("combat", tp->query_cap_name()+" grabs "+tgt->query_cap_name()+head+
                      " and slams "+tgt->query_objective()+" into "+what+"!",
                      env, ({ tp, tgt }) );

    tgt->do_damage(limb, dmg);

    if (strlen(head) && !tgt->query_stupor() && random(100) < 18+tp->query_stats("strength")/35) {
      int st;
      st = 2+random(3);
      st -= tgt->query_stats("constitution")/35;
      if (st < 1) st = 1;
      message("info", "A %^BOLD%^%^WHITE%^sharp pain%^RESET%^ "
                        "fills your head!", tgt);
      tgt->set_stupor(1);
      DELAY_D->add_delay(2 * st, this_object(), "wear_off_stupor", tgt);
    }
  }

  return 1;
}

void wear_off_stupor(object tgt) {
  if (tgt) {
    tgt->set_stupor(0);
    message("info", "The pain in your head fades.", tgt);
  }
}


