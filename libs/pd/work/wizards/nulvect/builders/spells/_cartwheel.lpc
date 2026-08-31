
#include <std.h>

#define BAIL(s) return notify_fail(s);

inherit DAEMON;

int abil();

int cmd_cartwheel(string str) {

  object tp=this_player();
  object *tgts;
  int i, amt, def;
  
  if (!abil()) return 0;
  if (tp->query_disable()) return 1;

  if (!(tp->query_current_attacker()) && !(sizeof(tp->query_attackers())))
    BAIL("You are not fighting.\n");

  amt= tp->query_skill("attack")*2/3;
  amt+= tp->query_skill("entertainment")*2/3;
  amt+= tp->query_stats("dexterity");
  amt= amt*2/3 + random(amt/2);

  for (i=0, tgts=tp->query_attackers(); i<sizeof(tgts); i++) {
    if (!(tgts[i])) continue;
    def= tgts[i]->query_skill("defense")/3;
    def+= tgts[i]->query_stats("dexterity")/2;
    def= def/2 + random(def/4);

    if (tp->query_sp() < 40+random(25)) {
      message("info","You fall over from lack of stamina.",tp);
      tp->set_rest_type("sit");
      return 1;
    }
    if (!random(5+(def/8))) {
      tgts[i]->set_rest_type("sit");
      tgts[i]->set_paralyzed(3, "You're still sprawling from that hit.");
      message("info", "%^YELLOW%^You cartwheel at "+tgts[i]->query_cap_name()+
        " and knock "+tgts[i]->query_objective()+" over!%^RESET%^", tp);
      message("info", "%^YELLOW%^"+tp->query_cap_name()+" cartwheels "
        "straight at you and knocks you over!%^RESET%^", tgts[i]);
      message("info", "%^YELLOW%^"+tp->query_cap_name()+" cartwheels "
        "towards "+tgts[i]->query_cap_name()+" and knocks "+
        tgts[i]->query_objective()+" over!%^RESET%^",
        environment(tp), ({tp, tgts[i]}) );
    }
    else {
      message("info", "%^ORANGE%^You cartwheel at "+tgts[i]->query_cap_name()+
        " and slam into "+tgts[i]->query_objective()+"!%^RESET%^", tp);
      message("info", "%^ORANGE%^"+tp->query_cap_name()+" cartwheels "
        "at you and slams into you!%^RESET%^", tgts[i]);
      message("info", "%^ORANGE%^"+tp->query_cap_name()+" cartwheels "
        "towards "+tgts[i]->query_cap_name()+" and slams into "+tgts[i]->query_objective()+
        "!%^RESET%^", environment(tp), ({tp, tgts[i]}) );
    }
    tgts[i]->add_hp(-(amt-def+random(tp->query_level()/2)));
    tp->add_sp(-(amt/5));
  }

  return 1;
}


int abil() {
  object tp=this_player();
  if (tp &&
      tp->query_level() >= 8 &&
      tp->query_subclass() == "jester" &&
      tp->query_skill("entertainment") >= 45) return 1;
  return 0;
}

void help() {
  object tp=this_player();
  message("help","\nSyntax: <cartwheel>\n"
                 "Jesters can do cartwheels during combat to try and knock "
                 "their enemies over.",tp);
}
