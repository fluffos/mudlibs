// fire dance rewritten by Nulvect 2006-08-17
#include <std.h>
#include <daemons.h>

#define COL "%^CYAN%^"
#define RES "%^RESET%^"

inherit SONG;

object use_this;
int noatt;

int dance() {
  object tp=this_player();
  if (tp->query_subclass() == "gypsy" &&
      tp->query_skill("entertainment") < 6*10)
        return 1;
  return 0;
}

void create() {
  ::create();
  set_dance_name("fire dance");
  set_auto(0);
  set_type("attack");
  set_target_required(0);
  set_max_rounds(3);
  use_this=0;
  noatt=0;
}

int no_drop(string str) {
  object tp=this_player();
  string tmp, what;

  switch (query_verb()) {
    case "drop": what=str; break;
    case "give": if (sscanf(str, "%s to %s", what, tmp) != 2) return 0; break;
    case "put": if (sscanf(str, "%s in %s", what, tmp) != 2) return 0; break;
  }

  if (tp == this_object()->query_caster() && present(what, tp) == use_this) {
    message("dance", "You can't drop your fire while you're dancing!", tp);
    return 1;
  }

  return 0;
}

void init() {
  ::init();
  add_action("no_drop","",1);
}

int check() {
  object tp=this_object()->query_caster();
  object fire;

  if (!tp) return 0;

  foreach (object thing in all_inventory(tp)) {
    if (thing->query_lit()) {
      fire=thing;
      break;
    }
  }

  if (!objectp(fire))
    return notify_fail("You cannot perform the fire dance without fire!\n");

  use_this = fire;

  return 1;
}

void performance(int round) {
  object tp=this_object()->query_caster();
  object env=environment(tp);
  object tgt;
  int dmg;
  int s;

  if (round == 1) {
    int r;
    r = tp->query_stats("dexterity")/5;
    r += tp->query_stats("constitution")/15;
    r += tp->query_skill("entertainment")/25;
    if (r > 15) r = 15 + tp->query_level()/20;
    set_max_rounds(r);
    message("dance","You begin to twirl your "+use_this->query_name()+
      " around you.",tp);
    message("dance",tp->query_cap_name()+" begins to twirl "+
      tp->query_possessive()+" "+use_this->query_name()+" around "+
      tp->query_possessive()+"self.", env, tp);
    return;
  }

  tp->clean_up_attackers();

  if (s=sizeof(tp->query_attackers()))
    tgt=tp->query_attackers()[random(s)];

  if (objectp(tgt) && round % 2) {
    message("dance", "You "+COL+"spin"+RES+" the flame quickly around "
      "your body and "+COL+"burn"+RES+" "+tgt->query_cap_name()+"!", tp);
    message("dance", tp->query_cap_name()+" "+COL+"spins"+RES+" "+
      tp->query_possessive()+" flame around and "+COL+"burns"+RES+" you!", tgt);
    message("dance", tp->query_cap_name()+" "+COL+"spins"+RES+" "+
      tp->query_possessive()+" flame around and "+COL+"burns"+RES+" "+
      tgt->query_cap_name()+"!", env, ({tp, tgt}) );
    
    dmg = BALANCE3_D->get_damage(tp, tgt, 1,
      ({"entertainment", "entertainment", "attack"}),
      ({"dexterity"}) );
    tgt->do_damage(tgt->return_target_limb(), dmg);
    tp->add_sp(dmg/10);
  }

  else if (!random(3)) {
    string part=({"torso","arm","leg"})[random(3)];
    message("combat","You twist your body, spinning the flame "
      "deftly around your "+part+".",tp);
    message("other_combat",tp->query_cap_name()+" twists "+
      tp->query_possessive()+" body, spinning a flame deftly around "+
      tp->query_possessive()+" "+part+".", env, tp);
    tp->add_sp(-2);
  }
}

void finish() {
  object tp=this_object()->query_caster();
  message("dance", "You bring the fire dance to an end.",tp);
  message("dance",tp->query_cap_name()+" brings "+tp->query_possessive()+
    " fire dance to an end.", environment(tp), tp);
}


