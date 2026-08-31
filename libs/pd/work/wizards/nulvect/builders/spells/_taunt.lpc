#include <std.h>

#define BAIL(s) return notify_fail(s);
#define PLACE "/wizards/rull/spells/"

inherit DAEMON;

int abil();

int cmd_taunt(string str) {
  object tp=this_player();
  object ob, tauntob;
  int chr, level, wis;

  if (!abil()) return 0;
  if (tp->query_disable()) return 1;

  if (sizeof(tp->query_attackers()))
    BAIL("You can't do that while fighting!\n");

  if (!ob=present(str,environment(tp)))
    BAIL("You don't see that here.\n");

  if (tp==ob) 
    BAIL("Neener neener neener.\n");

  if (!(tp->kill_ob(ob) || ob->kill_ob(tp)))
    BAIL("You can't start fighting with that.\n");

  chr=tp->query_stats("charisma");
  level=tp->query_level();
  wis=ob->query_stats("wisdom");

  if (tp->query_sp() < 50)
    BAIL("You're too tired to do that right now.\n");

  ob->add_skill_bonus("defense",-(chr*2/3+level-wis*2/3),level*4/3);
  ob->add_skill_bonus("attack",(chr*2/3+level)/2,level*4/3);
  tauntob=new(PLACE"tauntob");
  tauntob->move(ob);
  tauntob->set_owner(tp);
  tauntob->heart_beat();

  tp->set_disable(2);
  tp->add_sp(-(chr/3+wis/3+level/3));

  message("info","You run around "+ob->query_cap_name()+", shouting and making obscene gestures!",tp);
  message("info",tp->query_cap_name()+" runs around you, shouting and making obscene gestures.\n"
    "%^RED%^You feel the need to hurt "+tp->query_objective()+" badly!%^RESET%^",ob);
  message("info",tp->query_cap_name()+" runs around "+ob->query_cap_name()+", shouting and making obscene "
    "gestures!", environment(tp), ({tp, ob}));

  return 1;
}

int abil() {
  object tp=this_player();
  if (tp->query_subclass() == "jester" &&
      tp->query_level() >= 10) return 1;
  return 0;
}

void help() {
  object tp=this_player();
  message("help","\nSyntax: <taunt living>\nA good entertainer can annoy his audience too, "
    "making them drop their guard a bit while they go after him.",tp);
}

