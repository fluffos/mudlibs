#include <std.h>
#define FAIL(s) return notify_fail(s);
#define COL "%^BOLD%^%^CYAN%^"
#define RES "%^RESET%^"

inherit DAEMON;

object *cast=({});

int spell() {
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

  if (member_array(tp,cast) != -1)
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

  int intel, wis, faith, breath;
  int tdex, twis, tmd;
  int cost, dmg;

  if (!spell()) return 0;

  if (tp->query_disable()) return 1;

  if (!str) tgt=tp->query_current_attacker();
  else tgt=present(str,environment(tp));

  if (!ok_cast(tp,tgt)) return 0;
  
  intel=tp->query_stats("intelligence");
  wis=tp->query_stats("wisdom");
  faith=tp->query_skill("faith");
  breath=tp->query_skill("breath");
  
  tdex=tgt->query_stats("dexterity");
  twis=tgt->query_stats("wisdom");
  tmd=tgt->query_skill("magic defense");
  
  dmg=intel*2+wis+faith*2/3+breath*2;
  dmg-=tdex/2+twis/4+tmd/3;
  cost=dmg/8;
  
  if (tp->query_sp() < cost)
    FAIL("Too low on magic.\n");

  tp->set_disable(1);
  tp->add_sp(-cost);

  message("magic",COL+"You breath a blast of ice at "+tgt->query_cap_name()+"!"+RES,tp);
  message("magic",COL+tp->query_cap_name()+" breathes a blast of ice at you!"+RES,tgt);
  message("magic",COL+tp->query_cap_name()+" breathes a blast of ice at "
                  +tgt->query_cap_name()+"!"+RES, environment(tp),({tp,tgt}));

  tgt->do_damage(tgt->return_limb(),dmg);
  cast+=({tp});
  call_out("wait",30,({tp}));
  
  if (breath*3/4 > tdex) {
    message("magic",COL+"You are frozen solid!"+RES,tgt);
    message("magic",COL+tgt->query_cap_name()+" is frozen solid!"+RES,
                    environment(tgt),tgt);
    tgt->set_paralyzed(5,"You are frozen solid.","The ice breaks away around you.");
    call_out("frozen",2,({tgt,dmg,4}));
  }
  
  return 1;
}

void frozen(mixed *args) {
  object tgt=args[0];
  int dmg=args[1];
  int times=args[2];

  if (!tgt) return;

  tgt->damage(dmg/3);

  if (--times > 0) call_out("frozen",2,({tgt,dmg,times}));
}

void wait(mixed *args) {
  object tp=args[0];
  if (tp) cast-=({tp});
}

void help() {
  message("help","\n"
    "Syntax: <iceblast [living]>\n"
    "A blue dragon can concentrate his icy breath on a single foe, "
    "freezing him solid and doing significant damage.",
    this_player());
}

