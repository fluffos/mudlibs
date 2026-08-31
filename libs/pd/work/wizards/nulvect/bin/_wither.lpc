
#include <std.h>
#include <daemons.h>
#include <effect_cl.h>

#define COL "%^BOLD%^%^BLUE%^"
#define COL2 "%^BOLD%^%^BLACK%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

void end_wither(class Effect wither);

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "antipaladin" &&
      tp->query_level() >= 9)
        return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <wither [victim]>\n\n"
    "This attack channels an antipaladin's dark energy into a blow that saps "
    "his opponent's strength and stamina.",
    this_player() );
}

string type() { return "attack"; }

int can_cast(object tp, object tgt, object *weps) {
  
  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You have no physical form with which to strike.");

  if (!sizeof(weps))
    FAIL("You must use a weapon to deal the blow.");

  if (!tgt)
    FAIL("Attack who?");

  if (!tgt->is_living())
    FAIL("That is not alive.");

  if (tp == tgt)
    FAIL("That would be unwise.");

  if (tp->query_mp() < 50)
    FAIL("Your magic power is too low.");

  if (!tp->kill_ob(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_wither(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt, wep;
  object *weps;
  string wepname;
  int rank, cost_sp, cost_mp, dmg, time, debuff_str, dmg_sp;
  class Effect wither;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  weps = tp->query_wielded();

  if (!can_cast(tp, tgt, weps)) return 0;

  switch (tp->query_level()) {
    case 1..18: rank = 1; break;

    case 19..36: rank = 2; break;
    default: rank = 3;
  }

  time = 10;
  time += tp->query_stats("wisdom")/4;
  if (time > 20)
    time = 20 + (time-20)/2;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({ "attack", "magic attack" }),
    ({ "strength" }),
    ({ "strength", "dexterity", "wisdom" }) );

  // 85% at rank 1, 90% at rank 2, 95% at rank 3
  dmg = dmg * (80 + ( rank*5 ) ) / 100;

  // simplified form of this:
  // (dmg * 100 / tgt->query_max_hp()) * tgt->query_max_sp() / 100;
  // basically, damage sp by the same percentage we damage hp
  dmg_sp = dmg * tgt->query_max_sp() / tgt->query_max_hp();
  
  // 15% at rank 1, 25% at rank 2, 35% at rank 3
  debuff_str = tgt->query_stats("strength") * (5 + ( rank*10 ) ) / 100;
  if (debuff_str < 5)
    debuff_str = 5;

  cost_sp = BALANCE3_D->get_cost(dmg, rank, "sp") * 12 / 10;
  cost_mp = BALANCE3_D->get_cost(dmg, rank, "mp") * 7 / 10;

  if (tp->query_sp() < cost_sp)
    FAIL("You are too tired.");
  if (tp->query_mp() < cost_mp)
    FAIL("Not enough magic.");
  
  if (!tgt->query_effect("wither")) {
    wither = new(class Effect);
    wither->name = "wither";
    wither->caster = tp;
    wither->target = tgt;
    wither->castername = tp->query_name();
    wither->desc = "Your strength has been sapped by a withering blow.";
    wither->endtime = time() + time;
    wither->endfunc = (: end_wither :);
    wither->endmessages = ({
      COL+"You feel your sapped strength slowly return."+RES,
    });
    wither->misc = ({ debuff_str });

    tgt->add_stat_bonus("strength", -debuff_str);
    tgt->add_effect(wither);
  }

  weps = sort_array(weps, (: $1->query_wc() > $2->query_wc() ? -1 : 1 :) );
  wep = weps[0];
  wepname = remove_article(strip_color(replace_string(wep->query_short(), " (wielded)", "")));

  message("combat", "You "+COL2+"channel"+RES+" power into your "+wepname+", "
                    "and "+COL+"strike"+RES+" "+tgt->query_cap_name()+" with "
                    "a "+COL2+"withering"+RES+" blow!", tp);
  message("combat", tp->query_cap_name()+" "+COL2+"channels"+RES+" power into "
                    +tp->query_possessive()+" "+wepname+", "
                    "and "+COL+"strikes"+RES+" you with "
                    "a "+COL2+"withering"+RES+" blow!", tgt);
  message("combat", tp->query_cap_name()+" "+COL2+"channels"+RES+" power into "
                    +tp->query_possessive()+" "+wepname+", "
                    "and "+COL+"strikes"+RES+" "+tgt->query_cap_name()+" with "
                    "a "+COL2+"withering"+RES+" blow!", env, ({ tp, tgt }) );

  tp->add_sp(-cost_sp);
  tp->add_mp(-cost_mp);
  tp->set_disable(1);
  tp->add_skill_points("attack", debuff_str);
  tp->add_skill_points("magic attack", debuff_str);

  tgt->do_damage(tgt->return_limb(), dmg);
  tgt->add_sp(-dmg_sp);

  return 1;
}

void end_wither(class Effect wither) {
  object who = wither->target;
  int *info = wither->misc;
  int debuff_str = info[0];

  who->add_stat_bonus("strength", debuff_str);
}

