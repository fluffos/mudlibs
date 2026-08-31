
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define FAIL(s) return notify_fail(s);

#define COL "%^YELLOW%^"
#define COL2 "%^BOLD%^%^WHITE%^"
#define RES "%^RESET%^"

inherit DAEMON;

int is_undead(object who);

int spell() {
  object tp=this_player();
  if (tp && member_array(tp->query_subclass(), ({"cleric", "paladin"}) ) != -1 &&
      tp->query_skill("faith") >= 6*10)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <turn [whom]>\n\n"
    "This is a prayer against the undead. There is a small chance "
    "that the undead being will turn to dust.",
    this_player() );
}

int can_cast(object tp, object tgt) {
  object env;

  if (!tp) return 0;

  env=environment(tp);

  if (env->query_property("no attack") || env->query_property("no magic"))
    FAIL("You cannot cast that here.\n");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");

  if (!alignment_ok(tp))
    FAIL("You have betrayed the source of your powers.\n");

  if (tp->query_ghost())
    FAIL("You cannot cast spells while dead.\n");

  if (!tgt)
    FAIL("Turn whom?\n");

  if (!living(tgt))
    FAIL("That is not alive.\n");

  if (tp == tgt)
    FAIL("That would be stupid.\n");

  if (!is_undead(tgt))
    FAIL(capitalize(tgt->query_cap_name())+" is not undead!\n");

  if (userp(tgt) && !interactive(tgt))
    FAIL("You may not attack link-dead players.\n");

  if (!(tp->kill_ob(tgt)))
    FAIL("You may not attack "+tgt->query_cap_name()+".\n");
  
  return 1;
}

int cmd_turn(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  int dmg, cost, rank;

  if (!spell()) return 0;
  
  if (str && str != "")
    tgt=present(str, env);
  else
    tgt=tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  rank = 2+(tp->query_skill("faith")/(20*5));
  if (rank > 4) rank=4;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
          ({"faith"}),
          ({"wisdom", "wisdom", "intelligence"}),
          ({"faith"}) );
  dmg = dmg*1.3;
  cost = BALANCE3_D->get_cost(dmg, rank, "mp") * 60 / 100;

  if (tp->query_mp() < cost)
    FAIL("You do not have enough magic.\n");

  tp->add_mp(-(cost+random(cost/8)));

  message("magic", "You pray to the gods.", tp);
  message("magic", tp->query_cap_name()+" prays to the gods.", env, tp);

  message("magic", COL+"A shining "+COL2+"light"+RES+COL+" envelops "+
                   tgt->query_cap_name()+"!"+RES, env, tgt);
  message("magic", COL+"A shining "+COL2+"light"+RES+COL+" envelops you!"+RES, tgt);

  if (tgt->query_hp() <= tgt->query_max_hp()/5 || random(500) == 17) {
    message("magic", COL+tgt->query_cap_name()+" turns to "+
                     COL2+"dust"+RES+COL+"!"+RES, env, tgt);
    message("magic", COL+"The light "+COL2+"burns"+RES+COL+
                     " your body away!"+RES, tgt);
    tp->add_mp(-(cost/15));
    dmg = tgt->query_hp()*3;
  }

  tgt->do_damage("all", dmg, DAMAGE_FAITH | DAMAGE_HOLY | DAMAGE_FIRE, DAMAGE_BYPASS_ARMOUR, tp);
  tp->set_magic_round();

  return 1;
}

int is_undead(object who) {
  if (!who) return 0;
  if (who->query_undead() || member_array(who->query_race(),
      ({"undead","vampire","lich","ghoul","zombie","corpse","walking dead",
      "ghost","ghast","wight","spirit","skeleton","spectre"})) != -1)
        return 1;
  return 0;
}
