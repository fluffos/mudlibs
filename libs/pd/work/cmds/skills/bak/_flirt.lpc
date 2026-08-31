// flirt, a gypsy ability that raises charisma
// Kaknal 4-16-02
#include <daemons.h>
inherit DAEMON;
int abil();
void flirt1(object tp, int ppl);
void stop_flirt(object tp);
int cmd_flirt(string str) {
  int i, ppl;
  object *inv;
  object tp=this_player();
  if (!abil()) {
    return 0;
  }
  
  if (tp->query_current_attacker()) {
    message("info","You cannot take the time while in battle!",tp);
    return 1;
  }
  
  if (environment(tp)->query_property("no magic")) {
    message("info","You can't flirt here.",tp);
    return 1;
  }
  if (tp->query("flirt")) {
    message("info","You are already flirting.",tp);
    return 1;
  }
  if (tp->query_mp() < 50) {
    message("info","You don't have the energy to flirt right now.",tp);
    return 1;
  }
  
  if (tp->query_stats("charisma") < 9+random(3)) {
    message("info","You do not have enough natural attraction to flirt.",
      tp);
    return 1;
  }
  
  inv=all_inventory(environment(tp));
  for (i=0,ppl=0; i<sizeof(inv); i++) {
    if (living(inv[i]) && inv[i] != tp) ppl++;
  }
  if (ppl == 0) {
    message("info","There is nobody here to flirt with!",tp);
    return 1;
  }
  message("info","You begin to flirt with those around you.",tp);
  tp->add_mp(-(35+random(5)));
  tp->set_disable();
  call_out("flirt1", 2+random(3), tp, ppl);
  
  return 1;
}
void flirt1(object tp, int ppl) {
  int chr=tp->query_stats("charisma");
  int intel=tp->query_stats("intelligence");
  int level=tp->query_level();
  int x;
  
  if (ppl*8 > ((chr/3)+(intel/5)+random(9))) {
    message("info","You suddenly feel uncomfortable and stop flirting.",tp);
    return;
  }
  x= tp->query_stats("charisma")*level/100;
  x+= ppl*3/2;
  tp->add_stat_bonus("charisma",x);
  tp->set("flirt",tp->query_stat_bonus("charisma"));
  tp->add_mp(-(10+random(4)));
  call_out("stop_flirt", chr/2+35, tp);
  
}
void stop_flirt(object tp) {
  tp->add_stat_bonus("charisma",- tp->query("flirt"));
  tp->set("flirt",- tp->query_property("flirt"));
  message("info","You calm down and stop flirting with everyone.",tp);
  
}
int abil() {
  object tp=this_player();
  
  if (tp &&
      tp->query_level() >= 7 &&
      tp->query_subclass() == "gypsy") return 1;
  
  return 0;
}
void help() {
  message("help","<flirt>\n\n Gypsies have an almost magical charm "
    "about them that allows them to flirt with just about anyone.",
    this_player());
}
