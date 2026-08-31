#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define COL "%^MAGENTA%^"
#define RES "%^RESET%^"

inherit SONG;

void finish();
object use_this;

int dance() {
  object tp=this_player();
  if (tp->query_subclass() == "gypsy" &&
      tp->query_skill("entertainment") >= 28*5)
        return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <perform twining of nine tails>\n\n"
    "An intricate dance that involves twisting a flail around "
    "your body and striking your opponent with it several times "
    "while in combat.",
    this_player() );
}

void create() {
  ::create();
  set_dance_name("twining of nine tails");
  set_auto(0);
  set_type("attack");
  set_target_required(0);
  set_max_rounds(3);
  use_this=0;
}

int check() {
  object tp=this_object()->query_caster();
  object what;

  if (!tp) return 0;

  foreach (object thing in all_inventory(tp)) {
    if (thing->is_weapon() && thing->query_wielded() &&
        thing->query_type() == "flail") {
          what=thing;
          break;
    }
  }

  if (!objectp(what))
    return notify_fail("You must hold a flail to perform this dance!\n");

  if (tp->query_sp() < 50)
    return notify_fail("You are too tired.\n");

  use_this = what;

  return 1;
}

void performance(int round) {
  object tp=this_object()->query_caster();
  object env=environment(tp);
  object tgt;
  int dmg;
  int s;
  int dtype, dflags;
  
  if (round == 1) {
    int r;
    r = tp->query_stats("dexterity")/4;
    r += tp->query_stats("constitution")/12;
    r += tp->query_skill("entertainment")/20;
    r += 4;
    if (r > 20) r = 20 + tp->query_level()/14;
    set_max_rounds(r);
    message("dance","You "+COL+"twine"+RES+" your "+use_this->query_name()+
      " around your "+COL+"body"+RES+".",tp);
    message("dance", tp->query_cap_name()+" "+COL+"twines"+RES+" "+
      possessive(tp)+" "+use_this->query_name()+" around "+possessive(tp)+
      " "+COL+"body"+RES+".", env, tp);
    return;
  }
  
  if (environment(use_this) != tp || tp->query_sp() < 50) {
    finish();
    remove();
    return;
  }

  tp->clean_up_attackers();
  
  if (s=sizeof(tp->query_attackers()))
    tgt = tp->query_attackers()[random(s)];

  if (objectp(tgt) && round % 2 && !(env->query_property("no attack"))) {
    message("dance","You "+COL+"spin"+RES+" and "+COL+"pelt"+RES+" "+
      tgt->query_cap_name()+" repeatedly with your whip!",tp);
    message("dance",tp->query_cap_name()+" "+COL+"spins"+RES+
      " and "+COL+"pelts"+RES+" you repeatedly with "+
      possessive(tp)+" whip!", tgt);
    message("dance",tp->query_cap_name()+" "+COL+"spins"+RES+
      " and "+COL+"pelts"+RES+" "+tgt->query_cap_name()+" repeatedly with "+
      possessive(tp)+" whip!", env, ({tp, tgt}) );

    dtype = use_this->query_damage_type();
    dflags = use_this->query_damage_flags();
    dmg = BALANCE3_D->get_damage(tp, tgt, 3,
      ({"entertainment", "entertainment", "attack", "flail"}),
      ({"dexterity"}),
      ({"dexterity"}) );
    dmg = dmg*2/3;
    tp->add_sp(-(BALANCE3_D->get_cost(dmg, 3, "sp")*3/4));
    tgt->do_damage("target", dmg, DAMAGE_PHYSICAL | DAMAGE_DANCE | dtype, dflags, tp);
  }
  else if (!random(2)) {
    string part=({"shoulder","body","leg","arm"})[random(4)];
    message("dance","You twirl and "+COL+"coil"+RES+" your whip around "
      "your "+part+".%^RESET%^",tp);
    message("dance",tp->query_cap_name()+" twirls and "+COL+"coils"+RES+
      " "+possessive(tp)+" whip around "+possessive(tp)+" "+part+".", env, tp);
    tp->add_sp(-4);
  }
}

void finish() {
  object tp=this_object()->query_caster();
  message("dance", "You uncoil your whip and step lightly "
    "out of your dance.", tp);
  message("dance",tp->query_cap_name()+" uncoils "+possessive(tp)+
    " whip and steps lightly out of "+possessive(tp)+" dance.",
    environment(tp), tp);
}

