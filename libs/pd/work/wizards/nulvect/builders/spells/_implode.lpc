#include <std.h>
inherit DAEMON;

int spell();

int cmd_implode(string str) {
  object tp=this_player();
  int wiz, ma, intel, wisdom, md, damage;
  
  if (!spell()) {
    message("info","What?",tp);
    return 1;
  }
  if (tp->query_disable()) return 1;
  if (environment(tp)->query_property("no magic") ||
      environment(tp)->query_property("no attack")) {
    message("info","You cannot cast that here.",tp);
    return 1; 
  }
  if (!str) ob=tp->query_current_attacker();
  if (!ob && !ob=present(str,environment(tp))) {
    message("info","You don't see that here.",tp);
    return 1;
  if (!living(ob)) {
    message("info","That is not alive.",tp);
    return 1;
  }
  if (!tp->kill_ob(ob)) {
    message("info","That cannot be attacked by you yet.",tp);
    return 1;
  }
  if (tp == ob) {
    message("info","Boom, you're dead.",tp);
    return 1;
  }

  wiz=tp->query_skill("wizardry");
  ma=tp->query_skill("magic defense");
  intel=tp->query_stats("intelligence");
  
  wisdom=ob->query_stats("wisdom");
  md=ob->query_skill("magic defense");

  damage=(ma+wiz)*5/6+intel*3/2;

  if (tp->query_mp() < damage) {
    message("info","Too low on magic power.", tp);
    return 1;
  }
  tp->add_mp(-(damage+random(60)));

  message("info","%^BOLD%^A huge sphere of %^YELLOW%^pure magic%^RESET%^%^BOLD%^ "
    "constricts around you!%^RESET%^", ob);
  message("info","%^BOLD%^A huge sphere of %^YELLOW%^pure magic%^RESET%^%^BOLD%^ "
    "constricts tightly around "+ob->query_cap_name()+"!%^RESET%^",environment(ob),ob);

  tp->set_paralyzed(2+random(3), "You feel drained.");
  tp->set_casting(damage - (wisdom/3+md/3) + random(tp->query_level()));
  tp->add_skill_points("magic attack",damage/25);
  return 1;
}


int spell() {
  object tp=this_player();
  if (tp->query_subclass() == "wizard" &&
      tp->query_level() >= 50 &&
      tp->query_skill("wizardry") >= 290) return 1;
  return 0;
}

