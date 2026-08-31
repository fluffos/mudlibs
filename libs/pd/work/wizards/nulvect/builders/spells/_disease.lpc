#include <std.h>

#define BAIL(s) return notify_fail(s);
#define PLACE "/wizards/rull/spells/"

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp->query_subclass() == "necromancer" &&
      tp->query_level() >= 40 &&
      tp->query_skill("necromancy") >= 240) return 1;
  return 0;
}

int cmd_disease(string str) {
  object tp=this_player();
  object ob, dis;
  int wis, intel, ma, necro, twis, tmd, rounds, damage;
  
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
    BAIL("You cannot infect yourself.\n");

  if (present("diseaseob",ob))
    BAIL(capitalize(ob->query_subjective())+" is already infected!\n");

  intel=tp->query_stats("intelligence");
  wis=tp->query_stats("wisdom");
  ma=tp->query_skill("magic attack");
  necro=tp->query_skill("necromancy");
  
  twis=ob->query_stats("wisdom");
  tmd=ob->query_skill("magic defense");

  damage=necro/3+ma/3+intel;
  rounds=(necro-240)/40+wis/25+4;

  if (ob->query_hp() < damage+20)
    BAIL(capitalize(ob->query_possessive())+" body is too ravaged to infect.\n");

  if (tp->query_mp() < damage*3/2)
    BAIL("Too low on magic power.\n");

  if (!tp->kill_ob(ob))
    BAIL("That cannot be attacked by you yet.\n");

  tp->add_mp(-(damage*3/2+random(20)));

  message("info","%^MAGENTA%^Sores and wounds begin to appear on "+ob->query_cap_name()+"!%^RESET%^",
    environment(tp), ob);
  message("info","%^MAGENTA%^Sores and wounds begin to open all over your body!%^RESET%^", ob);

  dis=new(PLACE"diseaseob");
  dis->move(ob);
  dis->setup(tp,damage-(twis+tmd/2),rounds);
  dis->heart_beat();
  
  tp->set_disable();
  return 1;
}

