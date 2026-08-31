#include <std.h>
#include <daemons.h>
#include <limb_status.h>
#include <damage.h>
#include <damage_types.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^MAGENTA%^"
#define COL2 "%^BOLD%^%^BLUE%^"

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "sorceror" &&
      tp->query_skill("psionics") >= 35*6 &&
      tp->query_skill("magic attack") >= 35*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <dissever [who]>\n\n"
    "A spell that sorcerors have created to begin combat. "
    "The caster tries to cut off his opponent's control of his limbs, "
    "causing them to become crippled.",
    this_player() );
}

int can_cast(object tp, object tgt) {
  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You cannot harness your powers in this state.");

  if (!tgt)
    FAIL("Cast it at whom?");

  if (!tgt->is_living())
    FAIL("That has no mind.");

  if (tgt == tp)
    FAIL("That would be pointless.");

  if (sizeof(tp->query_attackers()) ||
      member_array(tgt, tp->query_hunters()) != -1)
        FAIL("You are too busy fighting to concentrate on that spell!");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  if (tp->query_mp() < 200)
    FAIL("Too low on magic.");

  return 1;
}

int cmd_dissever(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int rank, dmg, cost;

  if (!spell()) return 0;

  if (str)
    tgt = present(str, env);

  if (!can_cast(tp, tgt)) return 0;

  if (tp->query_level() >= 60)
    rank = 4;
  else
    rank = 3;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({ "psionics", "psionics", "psionics", "magic attack" }),
    ({ "intelligence", "intelligence", "intelligence", "wisdom" }),
    ({ "intelligence", "wisdom" }) );

  dmg = dmg * 175 / 100;

  cost = BALANCE3_D->get_cost(dmg, rank, "mp");

  if (tp->query_mp() < cost)
    FAIL("Too low on magic.");

  cost = cost / 2;
  tp->add_mp(-cost);
  tp->set_magic_round(2);

  message("magic", COL+"You gather your psionic energy."+RES, tp);

  call_out("do_hit", 2, ({ tp, env, tgt, dmg, cost }) );

  return 1;
}

void do_hit(mixed *args) {
  object tp = args[0];
  object env = args[1];
  object tgt = args[2];
  int dmg = args[3];
  int cost = args[4];
  int time, chance;
  string *limbs;

  if (!tp || !env) return;

  if (env != environment(tp)) {
    message("info", "Your spell has been interrupted!", tp);
    return;
  }

  if (!tgt || environment(tgt) != env) {
    message("info", "Your target is not here!", tp);
    return;
  }

  if (!tp->kill_ob(tgt)) {
    message("info", "You cannot attack "+tgt->query_cap_name()+".", tp);
    return;
  }

  tp->add_mp(-cost);

  time = 2 + tp->query_stats("wisdom") / 10;
  if (time > 6)
    time = 6 + (time-6) / 2;

  limbs = ({});
  chance = 15;
  chance += tp->query_stats("intelligence") / 7;
  chance -= tgt->query_stats("wisdom") / 7;
  if (chance > 40)
    chance = 40 + (chance-40) / 3;
  if (chance > 70)
    chance = 70;
  if (chance < 10)
    chance = 10;

  foreach (string limb in tgt->query_limbs()) {
    int rand = random(100);
    int stat = tgt->query_limb_status(limb);
    if (stat & LIMB_CRIPPLED)
      continue;
    if (stat & LIMB_WIELDABLE)
      rand -= 10;
    if (rand < chance) {
      tgt->set_crippled(limb, time*2);
      limbs += ({ limb });
    }
  }

  message("magic", COL2+"Bl"+COL+"a"+COL2+"de"+COL+"s of psionic "+
                   COL2+"po"+COL+"w"+COL2+"er"+COL+" cleave through "
                   "your mind!"+RES, tgt);
  message("magic", COL2+"Bl"+COL+"a"+COL2+"de"+COL+"s of psionic "+
                   COL2+"po"+COL+"w"+COL2+"er"+COL+" cleave through "+
                   tgt->query_cap_name()+"'s mind!"+RES, env, tgt);

  switch (sizeof(limbs)) {
    case 0:
    break;

    case 1:
    case 2:
    case 3:
      message("magic", COL+"You lose control of your "+list(limbs)+"!"+RES, tgt);
      message("magic", COL+tgt->query_cap_name()+" loses control of "+
        tgt->query_possessive()+" limbs!"+RES, env, tgt);
    break;

    default:
      message("magic", COL+"You lose control of your body!"+RES, tgt);
      message("magic", COL+tgt->query_cap_name()+" loses control of "+
                       tgt->query_possessive()+" body!", env, tgt);
      // using "time" var for paralyze time was too overpowered here
      tgt->set_paralyzed(4, "Your mind has been cleaved by psionic powers!");
  }

  tgt->do_damage("none", dmg, DAMAGE_MAGIC | DAMAGE_PSYCHIC, DAMAGE_HP_ONLY | DAMAGE_BYPASS_ARMOUR, tp);

}
