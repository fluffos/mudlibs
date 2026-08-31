
#include <std.h>
#include <daemons.h>
#include <rest.h>

#define COL "%^YELLOW%^"
#define COL2 "%^BOLD%^%^BLACK%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n");

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "kataan" &&
      tp->query_skill("faith") >= 6*5 &&
      tp->query_skill("summoning") >= 6*5)
        return 1;
  return 0;
}

string type() { return "faith"; }

void help() {
  message("help",
    "Syntax: <fear [whom]>\n\n"
    "This spell fills the target with a deep fear, "
    "causing him to run away or be unable to move. "
    "Kataans learn this as they begin to summon "
    "the powers of hell.",
    this_player() );
}

int can_cast(object tp, object tgt) {
  object env;

  if (!tp) return 0;

  env=environment(tp);

  if (env->query_property("no attack") || env->query_property("no magic"))
    FAIL("You cannot cast that here.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You cannot cast spells while dead.");

  if (!tgt)
    FAIL("Instill fear in whom?");

  if (!living(tgt))
    FAIL("That's an object. It's not afraid.");
  
  if (tp == tgt)
    FAIL("You're not afraid of yourself.");

  if (userp(tgt) && !interactive(tgt))
    FAIL("You may not attack link-dead players.");
  
  if (tgt->query_race() == "lich")
    FAIL("The lich is not affected!");

  if (!tp->kill_ob(tgt))
    FAIL("You cannot attack "+tgt->query_objective()+".");
  
  return 1;
}

int cmd_fear(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  int dmg, cost;
  
  if (!spell()) return 0;

  tp->clean_up_attackers();
  
  if (str && str != "") tgt=present(str, env);
  else tgt=tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  dmg = BALANCE3_D->get_damage(tp, tgt, 1,
    ({"faith", "summoning"}),
    ({"intelligence", "wisdom"}) );

  dmg = dmg*2/3;

  cost = dmg/7;

  if (tp->query_mp() < cost)
    FAIL("You need more magic.");

  if (userp(tgt))
    dmg -= tgt->query_skill("valor")/3;

  tp->set_magic_round(1);
  tp->add_mp(-(cost+random(cost/10)));

  if (tgt->query_paralyzed())
    FAIL(tgt->query_subjective()+" is too immobile to scare.");

  // paralyze
  if (dmg > tgt->query_hp()/4) {
    message("magic", COL+"You "+COL2+"fill"+COL+" "+tgt->query_cap_name()+
                     " with a "+COL2+"deep, paralyzing fear"+COL+"!"+RES, tp);
    message("magic", COL+tp->query_cap_name()+" "+COL2+"strikes fear"+COL+
                     " into your "+COL2+"heart"+COL+"!"+RES, tgt);
    message("magic", COL+tp->query_cap_name()+" "+COL2+"strikes fear"+COL+
                     " into "+tgt->query_cap_name()+"!"+RES, env, ({tp, tgt}) );
    tgt->set_paralyzed(6, "You are far too scared to do anything.");
  }
  
  // run away
  else if (dmg > tgt->query_hp()/8) {
    string *ex;
    message("magic", COL+"You "+COL2+"fill"+COL+" "+tgt->query_cap_name()+
                     " with a "+COL2+"deep fear"+COL+"!"+RES, tp);
    message("magic", COL+tp->query_cap_name()+" "+COL2+"strikes fear"+COL+
                     " into your "+COL2+"heart"+COL+"!"+RES, tgt);
    message("magic", COL+tp->query_cap_name()+" "+COL2+"strikes fear"+COL+
                     " into "+tgt->query_cap_name()+"!"+RES, env, ({tp, tgt}) );
    // there are exits, pick one
    if (sizeof(ex=env->query_exits())) {
      string dest=env->query_exit(ex[random(sizeof(ex))]);
      message("magic", "You run away!", tgt);
      message("mout", tgt->query_cap_name()+" runs away!", env, tgt);
      // something prevents you from going that way, fall down and paralyze
      if (tgt->move(dest)) {
        message("magic", "Some force knocks you over!", tgt);
        message("magic", tgt->query_cap_name()+" is knocked over by "
                         "an unseen force!", env, tgt);
        tgt->set_rest_type(LAY);
        tgt->set_paralyzed(4, "You are far too scared to do anything.");
      }
      // successfully moved
      else {
        message("min", tgt->query_cap_name()+" runs in.", dest, tgt);
        if (!userp(tgt)) call_out("fear_return", 30, ({tgt, env}) );
      }
    }
    // no exits, so paralyze
    else {
      message("magic", "You can't find anywhere to run!", tgt);
      message("magic", tgt->query_cap_name()+" has nowhere to run!", env, tgt);
      tgt->set_paralyzed(6, "You are far too scared to do anything.");
    }
  }

  // failure
  else {
    message("magic", "You try to strike fear into "+tgt->query_cap_name()+
                     ", but "+tgt->query_subjective()+" is not afraid.", tp);
    message("magic", tp->query_cap_name()+" tries to scare you, and fails.", tgt);
    message("magic", tp->query_cap_name()+" tries to scare "+
                     tgt->query_cap_name()+".", env, ({tp, tgt}) );
  }

  tp->add_skill_points("faith", 10);
  tp->add_skill_points("summoning", 10);
  
  return 1;
}

void fear_return(mixed *args) {
  object tgt=args[0];
  object env=args[1];
  object here;

  if (!tgt || !env) return;

  here=environment(tgt);

  if (!tgt->move(env)) {
    message("mout", tgt->query_cap_name()+" leaves timidly.", here, tgt);
    message("min", tgt->query_cap_name()+" enters timidly.", env, tgt);
  }
}


