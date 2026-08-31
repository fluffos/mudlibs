
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^BOLD%^%^WHITE%^"
#define COL2 "%^BOLD%^%^CYAN%^"
#define COL3 "%^BOLD%^%^RED%^"
#define RES "%^RESET%^"

inherit DAEMON;

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "swashbuckler" &&
      tp->query_skill("blade") >= 50*6 &&
      tp->query_skill("attack") >= to_int(50*4.5) &&
      tp->query_skill("entertainment") >= 50*3 &&
      tp->query_skill("perception") >= 50*4)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <coupedegrace [opponent]>\n\n"
    "A masterful finishing strike that only the best swashbucklers can learn.",
    this_player() );
}

int can_cast(object tp, object tgt, object *weps) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You have no body!");

  if (!tgt)
    FAIL("Finish who?");

  if (!tgt->is_living())
    FAIL("That is not alive.");

  if (!sizeof(weps))
    FAIL("You must use a blade.");

  if (tp->query_rest_type())
    FAIL("You must stand up first!");

  if (tgt == tp)
    FAIL("Fall upon your own blade?");

  if (!tgt->query_is_limb("torso"))
    FAIL("That seems to have no heart to aim for.");

  if (tp->query_sp() < 150)
    FAIL("You are too tired.");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_coupedegrace(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  object *weps;
  int rank, dmg, cost, hit, dodge;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  weps = filter(tp->query_wielded(), (: $1->query_type() == "blade" :) );

  if (!can_cast(tp, tgt, weps)) return 0;

  rank = 4;
  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({ "attack", "blade" }),
    ({ "strength", "dexterity" }),
    ({ "dexterity" }) );

  cost = BALANCE3_D->get_cost(dmg, rank, "sp") * 130 / 100;

  dmg = dmg*185/100;

  dmg += weps[random(sizeof(weps))]->query_wc()*30;

  if (cost > tp->query_sp())
    FAIL("You are too tired.");

  tp->kill_ob(tgt);

  hit = tp->query_stats("dexterity")*3;
  hit += tp->query_stats("charisma");
  hit += tp->query_skill("entertainment");
  hit += tp->query_skill("perception");

  dodge = tgt->query_stats("dexterity")*2;
  dodge += tgt->query_skill("perception")/2;
  dodge += tgt->query_skill("defense");
  dodge += tgt->query_skill("agility")/2;

  if (tgt->query_hp() > tgt->query_max_hp()*45/100 || dmg < tgt->query_hp() ||
      hit < dodge+random(dodge/5)) {
        message("combat", "As you try to finish off "+tgt->query_cap_name()+
          ", "+tgt->query_subjective()+" jumps back just out of reach!\n"+
          COL3+"You are thrown off balance!"+RES, tp);
        message("combat", "As "+tp->query_cap_name()+" tries to pierce your "
          "heart, you jump back just out of "+tp->query_possessive()+
          " reach!", tgt);
        message("combat", "As "+tp->query_cap_name()+" tries to pierce "+
          tgt->query_cap_name()+"'s heart, "+tgt->query_cap_name()+
          " jumps back just out of reach!", env, ({ tp, tgt }) );
        tp->set_disable(2+random(2));
        tp->add_sp(-(cost/2));
        return 1;
  }

  message("combat", "With a "+
    COL+"pr"+COL2+"eci"+COL+"se l"+COL2+"u"+COL+"nge"+RES+", "
    "you "+COL2+"drive"+RES+" your "+COL+"blade"+RES+" through "+
    tgt->query_cap_name()+"'s "+COL3+"heart"+RES+"!", tp);
  message("combat", tp->query_cap_name()+" "+COL+"l"+COL2+"u"+COL+"nges "
    "at you and "+COL2+"drives"+RES+" "+tp->query_possessive()+" "+
    COL+"blade"+RES+" through your "+COL3+"heart"+RES+"!", tgt);
  message("combat", "With a "+
    COL+"pr"+COL2+"eci"+COL+"se l"+COL2+"u"+COL+"nge"+RES+", "+
    tp->query_cap_name()+" "+COL2+"drives"+RES+" "+
    tp->query_possessive()+" "+COL+"blade"+RES+" through "+
    tgt->query_cap_name()+"'s "+COL3+"heart"+RES+"!",
    env, ({ tp, tgt }) );

  tp->set_disable(1);
  tp->add_sp(-cost);
  tgt->do_damage("torso", dmg*2, DAMAGE_PHYSICAL | DAMAGE_PIERCE, 0, tp);

  return 1;
}

