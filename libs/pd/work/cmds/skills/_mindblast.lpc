
#include <std.h>
#include <daemons.h>
#include <damage.h>
#include <damage_types.h>
#include <effect_cl.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^BOLD%^%^MAGENTA%^"
#define COL2 "%^YELLOW%^"
#define COL3 "%^BOLD%^%^RED%^"
#define RES "%^RESET%^"

inherit DAEMON;

void do_hit(class Effect mb);
void restore_resistance(object tgt, int type, int amt);

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "sorceror" &&
      tp->query_skill("psionics") >= 6*60 &&
      tp->query_skill("magic attack") >= 6*60)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <mindblast>\n\n"
    "Casts a huge amount of psionic power into the surrounding area, "
    "causing incredible mental damage and causing unpredictable but "
    "debilitating effects.",
    this_player() );
}

int can_cast(object tp) {
  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You can't manage your powers while dead.");

  if (tp->query_mp() < 200)
    FAIL("Your magic is too low.");

  return 1;
}

int can_target(object tp, object tgt) {
  if (!tgt->is_living())
    FAIL(tgt->query_cap_name()+" is not alive.");

  if (tgt == tp)
    FAIL("You cannot attack yourself.");

  if (!tp->kill_ob(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_mindblast(string str) {
  object tp = this_player();
  object env = environment(tp);
  object *ai, *tgts;
  int dmg, cost;
  class Effect mb;

  if (!spell()) return 0;

  if (!can_cast(tp)) return 0;

  ai = filter(all_inventory(env), (: can_target($2, $1) :), tp);
  tgts = ai - query_allies(tp);

  tp->add_mp(-(70+random(120)));
  tp->set_magic_round(3);

  message("magic", COL+"You gather your psionic energy."+RES, tp);

  mb = new(class Effect);
  mb->hide = 1;
  mb->name = "mindblast";
  mb->caster = tp;
  mb->castername = tp->query_name();
  mb->target = tp;
  mb->desc = "You are gathering energy for a mindblast.";
  mb->func = (: do_hit :);
  mb->endfunc = (: do_hit :);
  mb->maxhits = 2;
  mb->interval = 1;
  mb->startroom = file_name(env);
  mb->misc = ({ tgts });

  tp->add_effect(mb);

  return 1;
}

void do_hit(class Effect mb) {
  object tp = mb->caster;
  mixed *info = mb->misc;
  object *tgts = info[0];
  string start_room = mb->startroom;
  int round = mb->numhits;
  object env;
  int dmg;
  int cost;
  int i;
  int *used;
  string msg;

  if (!tp || !(env = environment(tp))) return;

  if (file_name(env) != start_room) {
    message("info", "Your spell is interrupted!", tp);
    mb->endfunc = 0;
    tp->remove_effect(mb);
    return;
  }

  if (round == 1) {
    message("magic", COL2+"A pulsing cloud of energy envelopes you!"+RES, tp);
    message("magic", COL2+"A pulsing cloud of energy envelopes "+
                     tp->query_cap_name()+"!"+RES, env, tp);
    return;
  }

  tgts = filter(tgts, (: $1 && environment($1) && file_name(environment($1)) == $2 :), start_room);
  if (!sizeof(tgts)) {
    message("info", "There is no one here to attack!", tp);
    mb->endfunc = 0;
    tp->remove_effect(mb);
    return;
  }

  foreach (object tgt in tgts) {

    if (!tp->kill_ob(tgt)) continue;

    dmg = BALANCE3_D->get_damage(tp, tgt, 4,
      ({ "psionics", "psionics", "magic attack" }),
      ({ "intelligence", "intelligence", "wisdom" }),
      ({ "intelligence" })
    );

    dmg = dmg * 180 / 100;

    cost = BALANCE3_D->get_cost(dmg, 4, "mp") * 3;

    tp->add_mp(-cost);

    message("magic", COL+"A wave of power "+COL2+"blasts"+COL+" through "+
                     tgt->query_cap_name()+"'s "+COL3+"mind"+COL+"!"+RES,
                     env, tgt);
    message("magic", COL+"A wave of power "+COL2+"blasts"+COL+" through "+
                     "your "+COL3+"mind"+COL+"!"+RES, tgt);

    tgt->do_damage("none", dmg, DAMAGE_MAGIC | DAMAGE_PSYCHIC,
      DAMAGE_HP_ONLY | DAMAGE_BYPASS_ARMOUR, tp);

    tp->set_magic_round(1);

    // apply 1-3 random negative effects, all short-term
    i = 1+random(3);
    used = ({});
    msg = "";

    do {

      int r;
      do {
        r = random(11);
      } while (member_array(r, used) != -1);

      used |= ({ r });

      switch (r) {
        case 0:
          tgt->add_mp(-(dmg/2));
          msg += "Your magic drains away.\n";
        break;
        case 1:
          tgt->add_sp(-(dmg/3));
          msg += "Your stamina drains away.\n";
        break;
        case 2:
          tgt->set_stupor(3);
          msg += "You can't think clearly.\n";
        break;
        case 3:
          tgt->set_crippled(tgt->return_limb(), 4);
          tgt->set_crippled(tgt->return_limb(), 4);
          msg += "Some of your limbs refuse to move.\n";
        break;
        case 4:
          tgt->set_blind(4);
          msg += "You suddenly go blind.\n";
        break;
        case 5:
          tgt->set_paralyzed(4, "You are reeling from the blast.");
          msg += "You are sent reeling from the blast.\n";
        break;
        case 6:
          tgt->add_combat_round_bonus(-2, 5);
          msg += "Your whole body feels sluggish.\n";
        break;
        case 7:
          tgt->add_stat_bonus("intelligence",
            -(tgt->query_stats("intelligence")*6/10), 8);
          msg += "Your thoughts become slow and mired.\n";
        break;
        case 8:
          tgt->add_stat_bonus("dexterity",
            -(tgt->query_stats("dexterity")*6/10), 8);
          msg += "Your movements become stilted and graceless.\n";
        break;
        case 9:
          tgt->add_resistance_bonus(DAMAGE_MAGIC, 30);
          DELAY_D->add_delay(8, this_object(), "restore_resistance",
            ({ tgt, DAMAGE_MAGIC, 30 }) );
          msg += "You feel much more vulnerable to magic.\n";
        break;
        case 10:
          tgt->add_resistance_bonus(DAMAGE_PSYCHIC, 40);
          DELAY_D->add_delay(8, this_object(), "restore_resistance",
            ({ tgt, DAMAGE_PSYCHIC, 40 }) );
          msg += "Your mind feels more susceptible to attack.\n";
        break;

      }
    } while (--i);

    message("info", msg, tgt);

    if (tp->query_mp() < 200) {
      message("info", "Your spell falters from lack of magic.", tp);
      mb->endfunc = 0;
      tp->remove_effect(mb);
      break;
    }
  }

  // end of do_hit
}

void restore_resistance(object tgt, int type, int amt) {
  if (tgt)
    tgt->add_resistance_bonus(type, -amt);
}

