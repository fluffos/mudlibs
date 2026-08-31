
#include <std.h>

#define BAIL(s) return notify_fail(s);

inherit DAEMON;

int spell();

int cmd_cauterize(string str) {

  object tp=this_player();
  object ob;
  string limb;
  int py, intel;
  
  if (!spell()) return 0;
  if (tp->query_disable()) return 1;

  if (environment(tp)->query_property("no magic"))
    BAIL("You cannot cast that here.\n");
  
  if (str == "me") str=tp->query_name();
  if (!str || !(ob=present(str,environment(tp))))
    BAIL("You don't see that here.\n");

  if (!living(ob))
    BAIL("That is not alive.\n");

  py= tp->query_skill("pyromancy");
  intel= tp->query_stats("intelligence");

  if (tp->query_mp() < (py/3+intel/2))
    BAIL("You are too low on magic.\n");
  
  tp->add_mp(-(py/3+intel/2+random(20)));

  limb=ob->return_limb();
  ob->heal_limb(limb,-(ob->query_body_mapping()[limb]["max_dam"]*(tp->query_level()*(20+random(11))/30)/100));
  ob->add_hp(py*5/2+intel*5/2);

  if (tp == ob) {
    message("magic","%^YELLOW%^You burn your wounds closed.%^RESET%^",tp);
    message("magic","%^YELLOW%^"+tp->query_cap_name()+" burns "+
      tp->query_possessive()+" wounds closed.%^RESET%^",environment(tp),tp);
  }
  else {
    message("magic","%^YELLOW%^You burn "+ob->query_cap_name()+"'s wounds closed.%^RESET%^",tp);
    message("magic","%^YELLOW%^"+tp->query_cap_name()+" burns your wounds closed.%^RESET%^",ob);
    message("magic","%^YELLOW%^"+tp->query_cap_name()+" burns "+ob->query_cap_name()+
      "'s wounds closed.%^RESET%^", environment(tp), ({tp,ob}));
  }

  return 1;

}

int spell() {
  object tp=this_player();
  if (tp &&
      tp->query_level() >= 8 &&
      tp->query_subclass() == "pyromancer" &&
      tp->query_skill("pyromancy") >= 45)
    return 1;
  return 0;
}

void help() {
  object tp=this_player();
  message("help","\nSyntax: cauterize <living>\n"
    "A healing spell of sorts. It uses fire to seal your wounds, "
    "which helps you stay alive at the cost of damage to your body.",tp);
}

