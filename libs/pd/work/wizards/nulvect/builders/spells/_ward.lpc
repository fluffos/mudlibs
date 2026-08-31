#include <std.h>

#define BAIL(s) return notify_fail(s);

inherit DAEMON;

int spell();

int cmd_ward(string str) {
  object tp=this_player();
  object ob;
  int wiz, md, intel;
  
  if (!spell()) return 0;
  if (tp->query_disable()) return 1;

  if (environment(tp)->query_property("no magic"))
    BAIL("You cannot cast that here.\n");
  
  if (str == "me") str=tp->query_name();
  if (!str || !(ob=present(str,environment(tp))))
    BAIL("You don't see that here.\n");
  
  if (!living(ob)) 
    BAIL("That is not alive.\n");
  
  if (ob->query_magic_protection())
    BAIL(ob->query_subjective()+" already has a teeming magical aura.\n");

  wiz=tp->query_skill("wizardry");
  md=tp->query_skill("magic defense");
  intel=(tp->query_stats("intelligence")+tp->query_stats("wisdom"))/2;
  
  if (tp->query_mp() < (wiz+md)/2)
    BAIL("Too low on magic power.\n");
  
  tp->add_mp(-((wiz+md)/2 +random(15)));

  ob->add_skill_bonus("defense", ((wiz+md)/2)/2, wiz/2+intel*4/3);
  //tp->add_skill_bonus("magic defense", -((wiz+md)/2)/2, wiz/2+intel*4/3);

  message("magic","You focus your powers.", tp);
  message("magic","%^BOLD%^%^BLUE%^Magical energies flow into your body.%^RESET%^", ob);
  message("magic","%^BOLD%^%^BLUE%^Magical energies flow into "+ob->query_cap_name()+".",
    environment(ob), ob);

  tp->add_skill_points("magic defense",md/30);

  return 1;
}


int spell() {
  object tp=this_player();
  if (tp->query_subclass() == "wizard" &&
      tp->query_skill("wizardry") >= 175 &&
      tp->query_skill("magic defense") >= 150) return 1;
  return 0;
}

