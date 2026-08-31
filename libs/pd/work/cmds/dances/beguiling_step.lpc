#include <std.h>
#include <daemons.h>

#define COL "%^CYAN%^"
#define RES "%^RESET%^"

inherit SONG;

string heshe;

int dance() {
  object tp=this_player();
  if (tp->query_subclass() == "gypsy" &&
      tp->query_skill("entertainment") >= 5*8 &&
      tp->query_skill("clairvoyance") >= 6*8)
        return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <perform beguiling step for whom>\n\n"
    "The beguiling step combines a gypsy's dancing ability with his "
    "powers of foresight. The result is a dance which causes its target "
    "to become quite charmed by the dancer. The target will try to be "
    "much more agreeable towards the gypsy.",
    this_player() );
}

void create() {
  ::create();
  set_dance_name("beguiling step");
  set_auto(0);
  set_type("detrimental");
  set_target_required(1);
  set_max_rounds(3);
}

int check() {
  object tp=this_object()->query_caster();

  if (!tp) return 0;

  tp->clean_up_attackers();

  if (sizeof(tp->query_attackers()))
    return notify_fail("You are too busy with combat.\n");

  if (tp->query_sp() < 25)
    return notify_fail("You are too tired.\n");

  if (tp->query_mp() < 40)
    return notify_fail("You are too low on magic.\n");

  heshe = query_target()->query_subjective();
  
  return 1;
}

void performance(int round) {
  object tp=this_object()->query_caster();
  object env=environment(tp);

  switch (round) {
    case 1:
      message("dance", "You move your feet in a "+
                       COL+"rhythmic"+RES+" dance.", tp);
      message("dance", tp->query_cap_name()+" moves "+tp->query_possessive()+
                       " feet in a "+COL+"rhythmic"+RES+" dance.", env, tp);
      tp->set_disable(3);
    break;
    case 2:
      message("dance", "You "+COL+"throw"+RES+" your arms over your head "
                       "and "+COL+"kick"+RES+" your feet out!", tp);
      message("dance", tp->query_cap_name()+" "+COL+"throws"+RES+" "+
                       tp->query_possessive()+" arms over "+tp->query_possessive()+
                       " head and "+COL+"kicks"+RES+" "+tp->query_possessive()+
                       " feet out!", env, tp);
    break;
  }
}

void finish() {
  object tp=this_object()->query_caster();
  object tgt=this_object()->query_target();
  object env=environment(tp);
  int amt;
  string m;
  string n;
  string o;

  m = "You pull your heels "+COL+"together"+RES+" in finale";
  o = tp->query_cap_name()+" pulls "+tp->query_possessive()+" heels "+
      COL+"together"+RES+" in finale";
  
  if (!tgt || environment(tgt) != environment(tp)) {
    m += ", but "+heshe+" seems to be gone.";
    o += ".";
  }
  else {
    m += " and present yourself to "+tgt->query_cap_name()+".\n"+
         capitalize(heshe)+" seems affected by your guile.";
    o += " and presents "+tp->query_objective()+"self to "+
         tgt->query_cap_name()+".\n"+
         tgt->query_cap_name()+" seems affected somehow.";
    n = tp->query_cap_name()+" pulls "+tp->query_possessive()+" heels "+
        COL+"together"+RES+" in finale and presents "+tp->query_objective()+
        "self to you.\n"
        "You feel drawn to "+tp->query_cap_name()+".";

    amt = tp->query_skill("entertainment")/15;
    amt += tp->query_skill("clairvoyance")/20;
    amt += tp->query_skill("perception")/22;
    amt += tp->query_skill("charisma")*2/3;
    if (tgt->query_skill_bonus("bargaining") >= 0)
      tgt->add_skill_bonus("bargaining", -amt*2, amt*2);
    if (tgt->query_skill_bonus("perception") >= 0)
      tgt->add_skill_bonus("perception", -amt*2, amt*2);
    if (tgt->query_skill_bonus("attack") >= 0)
      tgt->add_skill_bonus("attack", -amt*5/3, amt*2);
    if (tgt->query_stat_bonus("charisma") >= 0)
      tgt->add_stat_bonus("charisma", -amt*3/4, amt*2);
    if (tgt->query_stat_bonus("intelligence") >= 0)
      tgt->add_stat_bonus("intelligence", -amt*3/4, amt*2);
  }

  tp->add_sp(-(10+amt/4+random(amt/10)));
  tp->add_mp(-(20+amt/3+random(amt/10)));

  message("dance", m, tp);
  if (sizeof(n)) {
    message("dance", n, tgt);
    message("dance", o, env, ({tp, tgt}) );
  }
  else
    message("dance", o, env, ({tp}) );

}


