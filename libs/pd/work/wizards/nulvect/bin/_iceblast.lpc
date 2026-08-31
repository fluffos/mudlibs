#include <std.h>
#include <daemons.h>
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

  int cost, dmg;

  if (!abil()) return 0;

  if (tp->query_disable()) return 1;

  if (!str) tgt=tp->query_current_attacker();
  else tgt=present(str,environment(tp));

  if (!ok_cast(tp,tgt)) return 0;
  
  if (tp->query_level() >= 40)
    dmg=BALANCE_D->get_damage(tp, tgt, 3,
          ({"faith","faith","breath","breath","breath"}),
          ({"intelligence", "intelligence", "wisdom"}),
          ({"intelligence", "wisdom"}) );
  else
    dmg=BALANCE_D->get_damage(tp, tgt, 2,
          ({"faith","faith","breath","breath","breath"}),
          ({"intelligence", "intelligence", "wisdom"}) );

  dmg=dmg*5/4;
  
  cost=dmg/15;
  
  if (tp->query_sp() < cost)
    FAIL("Not enough stamina.\n");
  if (tp->query_mp() < cost*2)
    FAIL("Not enough magic.\n");

  tp->set_disable(1);
  tp->add_sp(-(cost+random(cost/15)));
  tp->add_mp(-(cost*2+random(cost/15)));

  message("magic",COL+"You breath a strong blast of ice at "+tgt->query_cap_name()+"!"+RES,tp);
  message("magic",COL+tp->query_cap_name()+" breathes a strong blast of ice at you!"+RES,tgt);
  message("magic",COL+tp->query_cap_name()+" breathes a strong blast of ice at "
                  +tgt->query_cap_name()+"!"+RES, environment(tp),({tp,tgt}));

  tgt->do_damage(tgt->return_limb(),dmg);

  tp->set("iceblast_spell_wait",1);

  call_out("wait",30,({tp}));
  
  if (tp->query_skill("breath")*3/4 > tgt->query_stats("dexterity")) {
    message("magic",COL+"You are frozen solid!"+RES,tgt);
    message("magic",COL+tgt->query_cap_name()+" is frozen solid!"+RES,
                    environment(tgt),tgt);
    tgt->set_paralyzed(6,"You are frozen solid.","The ice breaks away around you.");
    call_out("frozen",2,({tgt,dmg,2}));
  }
  
  return 1;
}

void frozen(mixed *args) {
  object tgt=args[0];
  int dmg=args[1];
  int times=args[2];

  if (!tgt) return;
  
  if (environment(tgt)->query_property("no magic") ||
      environment(tgt)->query_property("no attack"))
        return;
    
  message("magic",COL+"The ice saps away your vitality..."+RES,tgt);
  message("magic",COL+"The ice saps away "+
                      tgt->query_cap_name()+"'s vitality..."+RES,
                      environment(tgt), tgt);

  tgt->damage(dmg/3);

  if (--times > 0) call_out("frozen",2,({tgt,dmg,times}));
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

