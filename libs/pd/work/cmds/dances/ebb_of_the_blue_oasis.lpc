// blue oasis dance rewritten by Nulvect 2006-08-17

#include <std.h>

#define COL "%^CYAN%^"
#define RES "%^RESET%^"

inherit SONG;

int dance() {
  object tp=this_player();
  if (tp->query_subclass() == "gypsy" &&
      tp->query_skill("entertainment") >= 5*15)
        return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <perform ebb of the blue oasis>\n\n"
    "A dance which serves to heal you and your party.\n"
    "Extremely evil people find it impossible to perform to the benefit others.",
    this_player() );
}

void create() {
  ::create();
  set_dance_name("ebb of the blue oasis");
  set_type("beneficial");
  set_max_rounds(4);
}

int check() {
  object tp=this_object()->query_caster();

  if (!tp) return 0;

  if (tp->query_sp() < 40)
    return notify_fail("You are too tired for that.\n");
  
  if (tp->query_mp() < 100)
    return notify_fail("Your magical energy is too low for that.\n");

  tp->clean_up_attackers();
  if (tp->query_current_attacker())
    return notify_fail("You are too busy fighting.\n");
    
  return 1;
}

void performance(int round) {
  object tp=this_object()->query_caster();
  object env=environment(tp);

  switch (round) {
    case 1:
      tp->set_disable(4);
      message("dance","You begin a slow, "+COL+"flowing"+RES+" dance.",tp);
      message("dance",tp->query_cap_name()+" begins a slow, "+
        COL+"flowing"+RES+" dance.", env, tp);
    break;
    case 2:
      message("dance","You step carefully in a "+COL+"circle"+RES+
        ", stretching your body and arms "+COL+"outward"+RES+" as you dance.",tp);
      message("dance",tp->query_cap_name()+" dances slowly in a "+COL+"circle"+RES+
        ", stretching "+possessive(tp)+" body and arms "+COL+"outward"+RES+".",
        env, tp);
    break;
    case 3:
      message("dance","You swing your arms "+COL+"around"+RES+
        " slowly and "+COL+"wrap"+RES+" them around your waist as you "+
        COL+"turn"+RES+".",tp);
      message("dance",tp->query_cap_name()+" swings "+possessive(tp)+
        " arms "+COL+"around"+RES+" slowly and "+COL+"wraps"+RES+
        " them around "+possessive(tp)+" waist as "+nominative(tp)+" "+
        COL+"turns"+RES+".", env, tp);
    break;
  }
  tp->add_sp(-(random(10)+10));
}

void finish() {
  object tp=query_caster();
  object env=environment(tp);
  object *ai;
  int heal;

  message("dance","You "+COL+"raise"+RES+" your arms to the sky as you "+
    COL+"slowly"+RES+" bring your dance to an end.",tp);
  message("dance",tp->query_cap_name()+" "+COL+"raises"+RES+" "+
    possessive(tp)+" arms to the sky as "+nominative(tp)+" "+
    COL+"slowly"+RES+" finishes the dance.", env, tp);

  heal= tp->query_skill("entertainment")*5/3;
  heal+= tp->query_stats("wisdom")*2;
  heal+= random(tp->query_level());
  
  if (tp->query_alignment() < 1350) {
  if (userp(tp))
    ai=filter(all_inventory(env), (: userp($1) :) );
  else
    ai=filter(all_inventory(env), (: !userp($1) :) );
  foreach (object who in ai-({tp}))
    who->add_hp(heal);
  message("dance",COL+"You feel a little better."+RES, env);
  }
  else
    message("dance", COL+"You feel a little better."+RES, tp);
    
  tp->add_hp(heal*3/4);


  tp->add_mp(-(10+random(heal/3)));
}

