#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
#define FAIL(s) return notify_fail(s);
#define COL "%^BOLD%^%^CYAN%^"
#define RES "%^RESET%^"

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp->query_subclass() == "blue" &&
      tp->query_skill("breath") >= to_int(20*4.5))
    return 1;
  return 0;
}

string type() { return "attack"; }

int ok_cast(object tp, object tgt) {
  if (environment(tp)->query_property("no magic") ||
      environment(tp)->query_property("no attack"))
    FAIL("You cannot do that here.\n");

  if (tp->query("iceblast_spell_wait"))
    FAIL("You need more time to ready yourself for that.\n");
  
  if (!tgt)
    FAIL("You don't see that here.\n");

  if (!living(tgt))
    FAIL("That is not alive.\n");

  if (tp == tgt)
    FAIL("Brrrr.\n");

  if (!tp->kill_ob(tgt))
    FAIL("That cannot be attacked by you yet.\n");

  return 1;
}

int cmd_iceblast(string str) {
  object tp=this_player();
  object tgt;
  int rounds=0;
  int mp_cost, sp_cost, dmg;

  if (!abil()) return 0;

  if (tp->query_busy()) return notify_fail("You are busy.\n");

  if (!str) tgt=tp->query_current_attacker();
  else tgt=present(str,environment(tp));

  if (!ok_cast(tp,tgt)) return 0;
  
  if (tp->query_level() >= 40)
    dmg=BALANCE3_D->get_damage(tp, tgt, 3,
          ({"conjuring","faith","faith","breath","breath","breath"}),
          ({"intelligence", "intelligence", "wisdom"}),
          ({"faith", "breath"}) );
  else
    dmg=BALANCE3_D->get_damage(tp, tgt, 2,
          ({"conjuring","faith","faith","breath","breath","breath"}),
          ({"intelligence", "intelligence", "wisdom"}) );

  dmg=dmg/2;
  
  mp_cost = BALANCE3_D->get_cost(dmg, 3, "mp")*2;
  sp_cost = BALANCE3_D->get_cost(dmg, 2, "sp");
  
  if (tp->query_sp() < sp_cost)
    FAIL("Not enough stamina.\n");
  if (tp->query_mp() < mp_cost)
    FAIL("Not enough magic.\n");

  tp->set_disable(1);
  tp->add_sp(-(sp_cost+random(sp_cost/15)));
  tp->add_mp(-(mp_cost+random(mp_cost/15)));

  message("magic",COL+"You breath a strong blast of ice at "+tgt->query_cap_name()+"!"+RES,tp);
  message("magic",COL+tp->query_cap_name()+" breathes a strong blast of ice at you!"+RES,tgt);
  message("magic",COL+tp->query_cap_name()+" breathes a strong blast of ice at "
                  +tgt->query_cap_name()+"!"+RES, environment(tp),({tp,tgt}));

  tgt->do_damage("random", dmg, DAMAGE_PHYSICAL | DAMAGE_ICE, DAMAGE_NO_SEVER, tp);

  tp->set("iceblast_spell_wait",1);
  
  if (tp->query_skill("breath")*(3+random(3))/5 > tgt->query_stats("dexterity")+tgt->query_resistance(DAMAGE_ICE)) {
    message("magic",COL+"You are frozen solid!"+RES,tgt);
    message("magic",COL+tgt->query_cap_name()+" is frozen solid!"+RES,
                    environment(tgt),tgt);
    rounds = 6+to_int(tp->query_skill("conjuring")/80);
    rounds -= tgt->query_stats("constitution")/80;
    if (rounds < 2) rounds=2;
    tgt->set_paralyzed(rounds,"You are frozen solid.","The ice breaks away around you.");
    call_out("frozen",2,({tgt,dmg,2,tp}));
  }
  
  call_out("wait",20+rounds,({tp}));
  return 1;
}

void frozen(mixed *args) {
  object tgt=args[0];
  int dmg=args[1];
  int times=args[2];
  object tp=args[3];

  if (!tgt) return;
  
  if (environment(tgt)->query_property("no magic") ||
      environment(tgt)->query_property("no attack"))
        return;
    
  message("magic",COL+"The ice saps away your vitality..."+RES,tgt);
  message("magic",COL+"The ice saps away "+
                      tgt->query_cap_name()+"'s vitality..."+RES,
                      environment(tgt), tgt);

  tgt->do_damage("random", dmg/3, DAMAGE_PHYSICAL | DAMAGE_ICE, DAMAGE_NO_SEVER, tp);

  if (--times > 0) call_out("frozen",2,({tgt,dmg,times,tp}));
}

void wait(mixed *args) {
  object tp=args[0];
  if (tp) tp->set("iceblast_spell_wait",0);
}

void help() {
  message("help","\n"
    "Syntax: <iceblast [living]>\n"
    "A blue dragon can concentrate his icy breath on a single foe, "
    "freezing him solid and doing significant damage. This requires "
    "a lot of energy, so it can only be used periodically.",
    this_player());
}

