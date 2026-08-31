
#include <std.h>

#define BAIL(s) return notify_fail(s);
#define FLAMEWALL "/cmds/skills/obj/flamewall_ob"

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp &&
      tp->query_subclass() == "pyromancer" &&
      tp->query_skill("pyromancy") >= 17*6)
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  object tp=this_player();
  message("help","Syntax: <flamewall>\n\n"
    "This spell causes flames to spring up around the caster. "
    "The flames burn anything that tries to harm the caster."
    "\nA pyromancer can extinguish his own flamewall to reclaim "
    "a bit of the energy left in it.",
    tp);
}

int cmd_flamewall(string str) {

  object tp=this_player();
  object env=environment(tp);
  object fw;
  int py, md, intel;
  
  if (!spell()) return 0;
  if (tp->query_busy()) return notify_fail("You are busy.\n");;

  if (env->query_property("no attack") ||
      env->query_property("no magic"))
    BAIL("You cannot cast that here.\n");

  if (present("flamewallobj",env))
    BAIL("There is already a flamewall here!\n");

  py= tp->query_skill("pyromancy");
  md= tp->query_skill("magic defense");
  intel= tp->query_stats("intelligence");

  if (tp->query_mp() < (py+md+intel)/5)
    BAIL("You are too low on magic.\n");
  
  tp->add_mp(-(py+md+intel)/5+random(50));

  message("info","%^BOLD%^You wave your hand in a circle and "
    "a %^RED%^ring of flame%^RESET%^%^BOLD%^ shoots up around you!",tp);
  message("info","%^BOLD%^"+tp->query_cap_name()+" waves "+
    tp->query_possessive()+" hand around and a %^RED%^ring of flame"
    "%^RESET%^%^BOLD%^ shoots up around "+tp->query_objective()+"!",
    env, tp);
  
  tp->add_skill_points("pyromancy",md/20);
  tp->add_skill_points("magic defense",py/30);  
//  tp->set_magic_round(1);

  fw=new(FLAMEWALL);
  fw->move(env);
  fw->setup(tp);

  return 1;

}
