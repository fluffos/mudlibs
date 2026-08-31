#include <std.h>

#define BAIL(s) return notify_fail(s);
#define PLACE "/wizards/rull/spells/"

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp->query_subclass() == "druid" &&
      tp->query_level() >= 26 &&
      tp->query_skill("nature") >= 155) return 1;
  return 0;
}

int cmd_drown(string str) {
  object tp=this_player();
  object ob, drownob;
  int wis, ma, nat, wisdom, md, rounds, damage;
  
  if (!spell()) return 0;
  
  if (tp->query_disable()) return 1;

  if (environment(tp)->query_property("no magic") ||
      environment(tp)->query_property("no attack"))
    BAIL("You cannot cast that here.\n");

  if (!str) ob=tp->query_current_attacker();
  else ob=present(str,environment(tp));

  if (!ob)
    BAIL("You don't see that here.\n");

  if (!living(ob))
    BAIL("That is not alive.\n");

  if (tp == ob)
    BAIL("Gurgle gurgle.\n");

  if (!tp->kill_ob(ob))
    BAIL("That cannot be attacked by you yet.\n");


  wis=tp->query_stats("wisdom");
  ma=tp->query_skill("magic attack");
  nat=tp->query_skill("nature");
  
  wisdom=ob->query_stats("wisdom");
  md=ob->query_skill("magic defense");

  damage=nat/3+ma/3+wis;
  damage-=(wisdom/2+md/3);
  if (damage < 5) damage=5;

  rounds=(nat-155)/60+wis/25+2;

  if (tp->query_mp() < damage/5)
    BAIL("Too low on magic power.\n");

  tp->add_mp(-(damage/5+random(20)));

  message("info","%^BOLD%^%^CYAN%^You create a sphere of water around "+ob->query_cap_name()+".%^RESET%^", tp);
  message("info","%^BOLD%^%^CYAN%^"+tp->query_cap_name()+" creates a sphere of water around you!%^RESET%^", ob);
  message("info","%^BOLD%^%^CYAN%^"+tp->query_cap_name()+" creates a sphere of water around "+
    ob->query_cap_name()+"!%^RESET%^", environment(tp), ({tp,ob}) );
  drownob=new(PLACE"drownob");
  drownob->move(ob);
  drownob->setup(tp,damage,rounds);
  drownob->heart_beat();
  
  tp->set_disable(rounds+1);
  return 1;
}

