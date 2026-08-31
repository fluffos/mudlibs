// fire dance rewritten by Nulvect 2006-08-17
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define COL "%^CYAN%^"
#define RES "%^RESET%^"

inherit SONG;

void finish();
object use_this;

int dance() {
  object tp=this_player();
  if (tp->query_subclass() == "gypsy" &&
      tp->query_skill("entertainment") >= 2*5)
        return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <perform fire dance>\n\n"
    "One of the gypsy's first dances, the fire dance involves "
    "twirling a lit torch all around one's body and using it to "
    "inflict damage upon one's enemies.",
    this_player() );
}

void create() {
  ::create();
  set_dance_name("fire dance");
  set_auto(0);
  set_type("attack");
  set_target_required(0);
  set_max_rounds(3);
  use_this=0;
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

  if (tp->query_sp() < 30)
    return notify_fail("You are too tired.\n");

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
    r += tp->query_stats("constitution")/7;
    r += tp->query_skill("entertainment")/10;
    r += 3;
    if (r > 15) r = 15 + tp->query_level()/10;
    set_max_rounds(r);
    message("dance","You begin to twirl your "+use_this->query_name()+
      " around you.",tp);
    message("dance",tp->query_cap_name()+" begins to twirl "+
      tp->query_possessive()+" "+use_this->query_name()+" around "+
      tp->query_possessive()+"self.", env, tp);
    return;
  }

  if (environment(use_this) != tp || tp->query_sp() < 30) {
    finish();
    remove();
    return;
  }

  tp->clean_up_attackers();

  if (s=sizeof(tp->query_attackers()))
    tgt=tp->query_attackers()[random(s)];

  if (objectp(tgt) && round % 2 && !(env->query_property("no attack"))) {
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
    dmg /= 2;
    tgt->do_damage("target", dmg, DAMAGE_PHYSICAL | DAMAGE_DANCE | DAMAGE_FIRE, DAMAGE_NO_SEVER, tp);
    tp->add_sp(-(dmg/10));
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


