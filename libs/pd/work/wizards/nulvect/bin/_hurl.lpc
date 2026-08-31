
#include <std.h>
#include <daemons.h>
#include <rest.h>

#define RES "%^RESET%^"
#define COL "%^MAGENTA%^"

#define FAIL(s) return notify_fail(s+"\n")

int abil() {
  object tp=this_player();
  if (tp &&
      member_array(tp->query_subclass(), ({"berserker", "thug"}) ) != -1 &&
      tp->query_skill("melee") >= 6*45)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <hurl [who] [(at) [whom]]>\n\n"
    "You grab someone weaker than you and hurl him through the air. "
    "If you manage to hit someone else too, they'll both "
    "end up on the ground. It's much easier to grab an "
    "opponent who's already hurt.",
    this_player() );
}

int can_cast(object tp, object tgt, object othertgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You seem to be just a little...uh...dead.");

  if (sizeof(tp->query_wielding_limbs()) - sizeof(tp->query_limbs_wielded()) < 1)
    FAIL("You need at least one hand free!");

  if (tp->query_rest_type())
    FAIL("You need to stand up first.");

  if (tp->query_riding() || tp->query_mounting())
    FAIL("You need to dismount first.");
  
  if (!tgt)
    FAIL("Hurl who?");

  if (!living(tgt))
    FAIL(capitalize(tgt->query_short())+" is not alive.");

  if (tgt == tp)
    FAIL("That's impossible.");
  
  if (othertgt) {
    if (!living(othertgt))
      FAIL(capitalize(othertgt->query_short())+" is not alive.");
    if (othertgt == tp || othertgt == tgt)
      FAIL("That's impossible.");
  }

  if (!tp->kill_ob(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");
  
  return 1;
}

int cmd_hurl(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt, othertgt;
  int cost;
  int dodge, hit;
  int toobig, pickup;
  string name, othername;

  if (!abil()) return 0;

  if (str) {
    if (sscanf(str, "%s at %s", name, othername) == 2) {
      tgt = present(name, env);
      othertgt = present(othername, env);
    }
    else
      tgt = present(str, env);
  }
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt, othertgt)) return 0;

  cost = 25+random(6);

  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  tp->add_sp(-cost);
  tp->set_disable();
  
  dodge = tgt->query_stats("dexterity");
  dodge += tgt->query_skill("defense")/3;
  dodge += tgt->query_skill("agility")/6;
  dodge += tgt->query_level();
  dodge += to_int(1.4*percent(tgt->query_hp(), tgt->query_max_hp()));

  hit = tp->query_stats("dexterity")/2;
  hit += tp->query_stats("strength")/2;
  hit += tp->query_skill("attack")/4;
  hit += tp->query_skill("agility")/3;
  hit += tp->query_level();

  if (dodge > hit+random(15)) {
    message("combat", "You try to grab "+tgt->query_cap_name()+", but "+
                      tgt->query_subjective()+" slips out of your grasp!", tp);
    message("combat", tp->query_cap_name()+" tries to grab you, but you "
                      "slip out of "+tp->query_possessive()+" grasp.", tgt);
    message("combat", tp->query_cap_name()+" tries to grab "+tgt->query_cap_name()+
                      ", but fails.", env, ({ tp, tgt }) );
    return 1;
  }

  toobig = tgt->query_stats("constitution");
  toobig += tgt->query_level()*1.5;

  pickup = tp->query_stats("strength");
  pickup += tp->query_level();

  if (toobig > pickup) {
    message("combat", "You grab "+tgt->query_cap_name()+", but you are "
                      "not strong enough to lift "+tgt->query_objective()+"!", tp);
    message("combat", tp->query_cap_name()+" grabs you and tries to lift you, "
                      "but "+tp->query_subjective()+" is too weak.", tgt);
    message("combat", tp->query_cap_name()+" grabs "+tgt->query_cap_name()+
                      " and tries to lift "+tgt->query_objective()+
                      ", but fails.", env, ({ tp, tgt }) );
    return 1;
  }

  message("combat", "You gra"+COL+"b"+RES+" "+tgt->query_cap_name()+
                    " a"+COL+"n"+RES+"d h"+COL+"ol"+RES+"d "+
                    tgt->query_objective()+" off the ground!", tp);
  message("combat", tp->query_cap_name()+" gra"+COL+"b"+RES+"s you "
                    " a"+COL+"n"+RES+"d h"+COL+"ol"+RES+"ds you "
                    "off the ground!", tgt);
  message("combat", tp->query_cap_name()+" gra"+COL+"b"+RES+"s "+
                    tgt->query_cap_name()+
                    " a"+COL+"n"+RES+"d h"+COL+"ol"+RES+"ds "+
                    tgt->query_objective()+
                    "off the ground!", env, ({ tp, tgt }) );
  
  tgt->set_paralyzed(2, "You're being held in the air!");
  tp->set_paralyzed(4, "You are busy hurling someone.");
  tp->add_skill_bonus("defense", -(tp->query_base_skill("defense")*4/5), 4);

  call_out("do_hurl", 2, ({tp, tgt, othertgt}) );
  
  return 1;
}

void do_hurl(mixed *args) {
  object tp=args[0];
  object tgt=args[1];
  object othertgt=args[2];
  int dmg, otherdmg, cost;
  int dodge, hit;
  object env;
  string crash;

  if (!tp) return;

  if (!tgt) {
    message("info", "Your victim is gone!", tp);
    return;
  }

  env = environment(tp);

  dmg = BALANCE3_D->get_damage(tp, tgt, 4,
    ({ "attack", "melee", "melee" }),
    ({ "strength", "strength", "dexterity" }),
    ({ "strength", "dexterity" }) );
  dmg *= 1.3;
  
  cost = dmg/12 - 30;
  if (cost < 20) cost=20;

  if (tp->query_sp() < cost) {
    message("combat", "Your arms give out due to fatigue, and you drop "+
                      tgt->query_cap_name()+".", tp);
    message("combat", tp->query_cap_name()+" suddenly drops you.", tgt);
    message("combat", tp->query_cap_name()+" suddenly drops "+
                      tgt->query_cap_name()+".", env, ({tp, tgt}) );
    tgt->do_damage(tgt->return_limb(), 10+random(25));
    return;
  }
  
  tp->set_disable();
  tp->add_sp(-cost);
  
  message("combat", "You "+COL+"HU"+RES+"R"+COL+"L"+RES+" "+
                    tgt->query_cap_name()+" through the air!", tp);
  message("combat", tp->query_cap_name()+" "+COL+"HU"+RES+"R"+COL+"L"+RES+"S "
                    "you through the air!", tgt);
  message("combat", tp->query_cap_name()+" "+COL+"HU"+RES+"R"+COL+"L"+RES+"S "+
                    tgt->query_cap_name()+" through the air!", env, ({ tp, tgt }) );

  if (othertgt) {
    
    dodge = othertgt->query_stats("dexterity");
    dodge += othertgt->query_skill("defense")/3;
    dodge += othertgt->query_skill("agility")/6;
    
    hit = tp->query_stats("strength")*3/4;
    hit += tp->query_stats("dexterity")/3;
    hit += tp->query_skill("attack")/2.5;

    if (tp->kill_ob(othertgt)) {
      if (dodge > hit+random(20))
        crash = "the ground near "+tgt->query_cap_name();
      else {
        crash = othertgt->query_cap_name();
        otherdmg = BALANCE3_D->get_damage(tp, tgt, 3,
          ({ "attack", "melee" }),
          ({ "strength", "strength", "dexterity" }),
          ({ "strength", "dexterity" }) );
      }
    }
  }
  
  if (!strlen(crash))
    crash = "the ground";

  message("combat", "You fly "
                    "th"+COL+"r"+RES+"ou"+COL+"g"+RES+"h the air and "
                    "c"+COL+"r"+RES+"ash into "+crash+"!", tgt );
  message("combat", tgt->query_cap_name()+" flies "
                    "th"+COL+"r"+RES+"ou"+COL+"g"+RES+"h the air and "
                    "c"+COL+"r"+RES+"ashes into "+crash+"!",
                    env, ({ tgt, othertgt }) );

  if (otherdmg) {
    message("combat", tgt->query_cap_name()+" flies "
                      "th"+COL+"r"+RES+"ou"+COL+"g"+RES+"h the air and "
                      "c"+COL+"r"+RES+"ashes into you!", othertgt );
    othertgt->do_damage(othertgt->return_limb(), otherdmg);
    othertgt->set_rest_type(LAY);
  }
  
  tgt->do_damage(tgt->return_limb(), dmg);
  tgt->set_rest_type(LAY);
  
  tp->add_skill_points("melee", 40);
}

