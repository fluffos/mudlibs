// dance of a thousand nights
// rewritten by Nulvect 2006-08-17
#include <std.h>

#define COL "%^CYAN%^"
#define RES "%^RESET%^"
#define IMAGE "/cmds/dances/obj/nights_ghost_ob"
#define IMAGE_ID "nights_ghost_ob"

inherit SONG;

int dance() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "gypsy" &&
      tp->query_skill("entertainment") >= 5*18 &&
      tp->query_skill("clairvoyance") >= 6*18)
        return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <perform dance of a thousand nights>\n\n"
    "This dance calls forth assistance in the form of "
    "spiritual essences which can protect the gypsy.",
    this_player() );
}

void create() {
  ::create();
  set_dance_name("dance of a thousand nights");
  set_auto(0);
  set_type("other");
  set_target_required(0);
  set_max_rounds(3);
}

int check() {
  object tp=query_caster();

  if (!tp) return 0;

  if (tp->query_sp() < 50)
    return notify_fail("You are too tired for that.\n");

  if (tp->query_mp() < 70)
    return notify_fail("Your magical energy is too low for that.\n");

  if (present(IMAGE_ID, environment(tp)))
    return notify_fail("You are not ready for this dance again so soon.\n");

  return 1;
}

void performance(int round) {
  object tp=query_caster();
  object env=environment(tp);

  switch (round) {
    case 1:
      tp->set_disable(4);
      message("dance","You "+COL+"sway"+RES+" back and forth in a "+
        COL+"mystical"+RES+" dance.",tp);
      message("dance",tp->query_cap_name()+" "+COL+"sways"+RES+
        " back and forth in a "+COL+"mystical"+RES+" dance.", env, tp);
    break;
    case 2:
    case 3:
      message("info","You "+COL+"kick"+RES+" your legs and hop about "
        "as you dance "+COL+"wildly"+RES+"! ", tp);
      message("info",tp->query_cap_name()+" "+COL+"kicks"+RES+" "+
        tp->query_possessive()+" legs and hops about as "+tp->query_subjective()+
        " dances "+COL+"wildly"+RES+"!", env, tp);
    break;
  }
  tp->add_sp(-(20+(random(10))));
}

void finish() {
  int i, max;
  object ghost;
  object tp=query_caster();
  object env=environment(tp);

  message("dance","You throw your arms out to your sides as you "
    "finish your dance!",tp);
  message("dance",tp->query_cap_name()+" throws "+possessive(tp)+
    " arms out to "+possessive(tp)+" sides as "+nominative(tp)+
    " finishes the dance!", env, tp);
  max= 1+((tp->query_level()-18)/11);
  if (max > 5) max=5;
  for (i=0; i<max; i++) {
    ghost=new(IMAGE);
    ghost->set_property("no monster", 1);
    ghost->set_id(ghost->query_id()+({IMAGE_ID}));
    ghost->setup(tp, tp->query_level()/3);
    ghost->move(env);
    tp->add_mp(-(40+random(30)));
  }
  if (max == 1)
    message("info","%^BOLD%^%^WHITE%^A ghostly spirit materializes "
      "from nowhere!%^RESET%^", env);
  else
    message("info","%^BOLD%^%^WHITE%^Ghostly spirits materialize "
      "from nowhere!%^RESET%^", env);
}

