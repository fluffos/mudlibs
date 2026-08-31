
#include <std.h>
#include <daemons.h>
#include <effect_cl.h>
#include <damage.h>
#include <damage_types.h>

#define COL "%^BOLD%^%^MAGENTA%^"
#define COL2 "%^BOLD%^%^BLUE%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n");
#define MINDSHOCK_OB DIR_CLASS_CMDS+"/obj/command"
#define MINDSHOCK_ID "mindshock_ob"
#define MINDSHOCK_PROP "mindshock_spell_time"
#define MINDSHOCK_TIME 30

inherit DAEMON;

void do_hit(mixed *args);
void end_mindshock(class Effect ms);
int mindshock_catch(string str);

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "sorceror" &&
      tp->query_skill("psionics") >= 18*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <mindshock [who]>\n\n"
    "This spell affects the mind of its target, causing his "
    "thoughts to become jumbled. "
    "As a consequence, he will have trouble performing most "
    "actions, though bodily instincts will remain intact. "
    "It takes a strong mind to use this power effectively.",
    this_player() );
}

int can_cast(object tp, object tgt) {
  object env;

  if (!tp) return 0;

  env=environment(tp);

  if (env->query_property("no attack") || env->query_property("no magic"))
    FAIL("You cannot use this here.");

  if (tp->query_ghost())
    FAIL("You cannot harness your psionic powers in this state.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (!tgt)
    FAIL("Mindshock whom?");

  if (!living(tgt))
    FAIL("That doesn't have a mind.");

  if (tgt->query_effect("mindshock"))
    FAIL(capitalize(tgt->query_subjective())+" is already affected by that.");

  if (tp == tgt)
    FAIL("Zap.");
  
  if (!(tp->kill_ob(tgt)))
    FAIL("You may not attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_mindshock(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  int dmg, cost, time;

  if (!spell()) return 0;

  if (str && str != "")
    tgt=present(str, env);
  else
    tgt=tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  dmg = BALANCE3_D->get_damage(tp, tgt, 1,
    ({"psionics"}),
    ({"intelligence"}) );

  dmg /= 2;

  // time is in heartbeats/rounds, not seconds
  time = 1+tp->query_stats("intelligence")/13;
  time += tp->query_skill("psionics")/100;
  time += random(2);
  time -= tgt->query_stats("wisdom")/4;
  time -= tgt->query_skill("magic defense")/80;
  if (time > 3) time=3+(time-3)/4;
  if (time < 1) time=1;
  if (time > 6) time=6;

  cost = BALANCE3_D->get_cost(dmg, 1, "mp");
  cost += time*5;
  if (tgt->query(MINDSHOCK_PROP)+MINDSHOCK_TIME > time()) {
    cost *= 5;
    if (time > 2) time = 2;
  }

  if (tp->query_mp() < cost)
    FAIL("You need more magic to cast that.");

  tp->add_mp(-(cost/2));
  tp->set_magic_round(2);

  message("magic", COL+"You concentrate your psionic energy."+RES, tp);

  call_out("do_hit", 2, ({ tp, tgt, dmg, time, cost/2 }) );

  return 1;
}

void do_hit(mixed *args) {
  object tp = args[0];
  object tgt = args[1];
  int dmg = args[2];
  int time = args[3];
  int cost = args[4];
  object cmdob;
  class Effect ms;

  if (!tp) return;

  if (!tgt || environment(tgt) != environment(tp)) {
    message("info", "Your target is not here!", tp);
    return;
  }

  if (member_array(tgt, tp->query_attackers()) == -1)
    return;

  if (!(cmdob=new(MINDSHOCK_OB))) {
    message("info", "An error occurred. Please contact a staff member.", tp);
    return;
  }
  
  cmdob->set_catchall(1);
  cmdob->set_function(this_object(), "mindshock_catch");

  ms = new(class Effect);
  ms->name = "mindshock";
  ms->caster = tp;
  ms->castername = tp->query_name();
  ms->target = tgt;
  ms->desc = "Your mind has been shocked.";
  ms->endtime = time()+(time*2);
  ms->endfunc = (: end_mindshock :);
  ms->endmessages = ({
    "You regain control of your mind.",
    tgt->query_cap_name()+" regains control of "+
      tgt->query_possessive()+" mind.",
  });
  ms->misc = ({ cmdob });

  cmdob->move(tgt);
  tgt->add_effect(ms);

  tp->add_mp(-cost);
  tp->set_magic_round(1);

  message("magic", COL+"You send a "+COL2+"jolt"+COL+" of "
                   "en"+COL2+"er"+COL+"gy right into "+
                   tgt->query_cap_name()+"'s mind!"+RES, tp);

  message("magic", COL+tp->query_cap_name()+" stares at you, and suddenly a "+
                   COL2+"jolt"+COL+" of en"+COL2+"er"+COL+"gy slams into your "
                   "mind!", tgt);

  message("magic", COL+tp->query_cap_name()+" stares at "+tgt->query_cap_name()+
                   ", and suddenly "+tgt->query_cap_name()+
                   " "+COL2+"reels"+COL+" and seems "
                   "con"+COL2+"fu"+COL+"sed!", environment(tp), ({tp, tgt}) );
  
  tgt->do_damage("none", dmg, DAMAGE_MAGIC | DAMAGE_PSYCHIC, DAMAGE_HP_ONLY | DAMAGE_BYPASS_ARMOUR, tp);
  tgt->set(MINDSHOCK_PROP, time());

}

int mindshock_catch(string str) {
  message("info", "Your mind has been shocked.", this_player());
  return 1;
}

void end_mindshock(class Effect ms) {
  mixed *arr = ms->misc;
  object cmd = arr[0];

  if (cmd) cmd->remove();
}

