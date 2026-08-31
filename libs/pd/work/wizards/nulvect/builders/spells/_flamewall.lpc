
#include <std.h>

#define BAIL(s) return notify_fail(s);
#define PLACE "/wizards/rull/spells/"

inherit DAEMON;

int spell();

int cmd_flamewall(string str) {

  object tp=this_player();
  object env=environment(tp);
  object fw;
  int py, md, intel;
  
  if (!spell()) return 0;
  if (tp->query_disable()) return 1;

  if (env->query_property("no attack") ||
      env->query_property("no magic"))
    BAIL("You cannot cast that here.\n");

  if (present("flamewallobj",env))
    BAIL("There is already a flamewall here!\n");

  py= tp->query_skill("pyromancy");
  md= tp->query_skill("magic defense");
  intel= tp->query_stats("intelligence");

  if (tp->query_mp() < (py+md+intel)*2/5)
    BAIL("You are too low on magic.\n");
  
  tp->add_mp(-(py+md+intel)*2/5+random(50));

  message("info","%^BOLD%^You wave your hand in a circle and "
    "a %^RED%^ring of flame%^RESET%^%^BOLD%^ shoots up around you!",tp);
  message("info","%^BOLD%^"+tp->query_cap_name()+" waves "+
    tp->query_possessive()+" hand around and a %^RED%^ring of flame"
    "%^RESET%^%^BOLD%^ shoots up around "+tp->query_objective()+"!",
    env, tp);
  
  tp->add_skill_points("pyromancy",md/20);
  tp->add_skill_points("magic defense",py/30);  

  fw=new(PLACE"flamewallobj");
  fw->set_owner(tp);
  fw->set_strength(py/3+md/4+intel*3/2);
  fw->set_time(py/30+md/25+3+random(3));
  fw->move(env);
  fw->heart_beat();

  return 1;

}

int spell() {
  object tp=this_player();
  if (tp &&
      tp->query_level() >= 16 &&
      tp->query_subclass() == "pyromancer" &&
      tp->query_skill("pyromancy") >= 95)
    return 1;
  return 0;
}

void help() {
  object tp=this_player();
  message("help","\nSyntax: <flamewall>\n"
    "This spell causes flames to spring up around the caster. "
    "The flames burn anything that tries to harm the caster.",tp);
}

