
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define COL "%^BOLD%^%^BLACK%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n");

#define DEMON_ALIGN -800

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp && tp->query_race() == "demon" && tp->query_level() >= 25)
    return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <gore [whom]>\n\n"
    "Demons can use their horns to puncture the flesh of their victims.\n"
    "The stronger the demon and the closer he is to Asmodeus, the "
    "more he can focus his fury.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (member_array("horns",tp->query_severed_limbs()) != -1)
    FAIL("Your horns are missing!");

  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot attack here.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your horns aren't solid enough to hurt anything.");

  if (tp->query_rest_type())
    FAIL("You have to stand up first.");

  if (!tgt)
    FAIL("Gore whom?");

  if (!living(tgt))
    FAIL("You gore it furiously, but it doesn't respond.");

  if (tgt == tp)
    FAIL("That is impossible and stupid.");

  if (!tp->kill_ob(tgt))
    FAIL("You can't attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_gore(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  int dmg, cost, rank;
  int level, align, alignok;
  int mult;

  if (!abil()) return 0;

  if (str)
    tgt=present(str, env);
  else
    tgt=tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  align=tp->query_alignment();
  level=tp->query_level();
  
  if (align <= DEMON_ALIGN) alignok=1;
  else alignok=0;
  
  if (level >= 45) rank=3;
  else if (level >= 35) rank=2;
  else rank=1;

  if (alignok) rank++;
    
  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({"none"}),
    ({"strength", "strength", "strength", "dexterity"}),
  );

  mult = 100;

  // every 20 alignment points below -1400 gives +1% damage, max +5% this way
  if (align <= -1400)
    mult += (-1400 - align)/20;

  // +1% every 5 levels
  mult += (level-25)/5;

  dmg = dmg * mult / 100;
  
  cost = BALANCE3_D->get_cost(dmg, rank, "sp");

  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  if (tgt->query_stats("dexterity") > tp->query_stats("dexterity")+random(30)) {
    cost=cost*3/4;
    message("combat", "You try to gore "+
                      tgt->query_cap_name()+", but miss.", tp);
    message("combat", tp->query_cap_name()+" tries to gore you, but misses.", tgt);
    message("combat", tp->query_cap_name()+" tries to gore "+
                      tgt->query_cap_name()+", but misses.", env, ({tp,tgt}) );
  }
  else {
    message("combat", "You "+COL+"gore"+RES+" "+tgt->query_cap_name()+
                      " with your horns!", tp);
    message("combat", tp->query_cap_name()+" "+COL+"gores"+RES+" you with "+
                      tp->query_possessive()+" horns!", tgt);
    message("combat", tp->query_cap_name()+" "+COL+"gores"+RES+" "+
                      tgt->query_cap_name()+" with "+
                      tp->query_possessive()+" horns!", env, ({tp, tgt}) );
    if (align == -1500 && tgt->query_race() == "archangel")
      dmg = dmg * 120 / 100;
    tgt->do_damage("target", dmg, DAMAGE_PHYSICAL | DAMAGE_UNARMED | DAMAGE_PIERCE, 0, tp);
  }
  
  tp->add_sp(-(cost+random(cost/9)));
  tp->set_disable();

  return 1;
}

