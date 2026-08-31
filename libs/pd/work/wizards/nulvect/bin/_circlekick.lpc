
#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL RES+"%^WHITE%^"
#define COL2 "%^ORANGE%^"
#define COLC COL+"%^B_RED%^"

int abil() {
  object tp = this_player();
  if (tp->query_subclass() == "monk" && tp->query_skill("melee") >= 14*6)
    return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <circlekick [who]>\n\n"
    "A moderately difficult attack where the user spins in a circle "
    "to add more power to his kick. More advanced martial artists can "
    "sometimes continue around to hit multiple opponents.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your legs are immaterial.");

  if (!tgt)
    FAIL("Circlekick who?");

  if (!tgt->is_living())
    FAIL("You kick it.");

  if (tgt == tp)
    FAIL("You try very hard to kick yourself, but you fail.");

  if (!tp->query_mobile())
    FAIL("Your body is hurt too badly to use kicking attacks!");

  if (tp->query_rest_type())
    FAIL("You must stand up first!");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  if (tp->query_sp() < 50)
    FAIL("You are too tired.");

  return 1;
}

int cmd_circlekick(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  object *atkrs;
  int dmg, rank, cost, perc, i;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  if (tp->query_level() >= 30)
    rank = 3;
  else
    rank = 2;

  if (tp->query_level() >= 22) {
    atkrs = tp->query_attackers() - ({ tgt });
    atkrs = ({ tgt }) + atkrs;
  }
  else
    atkrs = ({ tgt });

  i = 0;

  message("combat", COL+"You bring your leg around in a "+
    COL2+"circle kick"+COL+"!"+RES, tp);
  message("combat", COL+tp->query_cap_name()+" brings "+tp->query_possessive()+
    "leg around in a "+COL2+"circle kick"+COL+"!"+RES, env, tp);

  foreach (object atk in atkrs) {

    int hit, dodge;

    if (!tp->ok_to_kill(atk)) {
      atkrs -= ({ atk });
      continue;
    }

    dmg = BALANCE3_D->get_damage(tp, atk, rank,
      ({ "attack", "melee", "melee", "melee" }),
      ({ "strength", "dexterity" }),
      ({ "strength", "dexterity" }) );

    for (int j = 0; j < i; j++)
      dmg = dmg*2/3;

    cost = dmg * (13 - i) / 100;

    if (tp->query_sp() < cost) {
      if (i == 0)
        FAIL("You are too tired.");
      else {
        message("info", "You are too tired to continue your circle kick.", tp);
        return 1;
      }
    }

    tp->add_sp(-cost);
    tp->set_disable(1);
    tp->kill_ob(atk);

    hit = tp->query_stats("dexterity");
    hit += tp->query_skill("attack")/3;
    hit += 15;

    dodge = atk->query_stats("dexterity");
    dodge += atk->query_skill("defense")/3;
    if (atk->query_class() == "rogue")
      dodge += atk->query_skill("agility")/4;

    if (dodge > hit + random(25) - random(25)) {
      message("combat", atk->query_cap_name()+" dodges your circle kick!", tp);
      message("combat", "You deftly dodge the circle kick!", atk);
      message("combat", atk->query_cap_name()+" dodges "+
        tp->query_cap_name()+"'s circle kick!", env, ({ tp, atk }) );
    }
    else {
      if (!perc) {
        perc = COMBAT_D->combo(tp, "circlekick");
        dmg = dmg * perc / 100;
      }
      
      message("combat", COL+"Your kick "+COL2+"smashes"+COL+" into "+
        atk->query_cap_name()+"!"+RES, tp);
      message("combat", COL+tp->query_cap_name()+"'s kick "+COL2+"smashes"+COL+
        " into you!"+RES, atk);
      message("combat", COL+tp->query_cap_name()+"'s kick "+COL2+"smashes"+COL+
        " into "+atk->query_cap_name()+"!"+RES, env, ({ tp, atk }) );

      atk->do_damage(atk->return_limb(), dmg);
    }

    i++;
  }

  // extra hit if doing a combo, always hits all attackers
  if (perc > 100) {

    if (sizeof(atkrs) < sizeof(tp->query_attackers()))
      atkrs = tp->query_attackers();

    foreach (object atk in atkrs) {

      if (!tp->ok_to_kill(atk)) continue;

      dmg = BALANCE3_D->get_damage(tp, atk, rank,
        ({ "melee" }),
        ({ "strength" }),
        ({ "dexterity" }) );
      
      dmg = dmg * 25 / 100;
      
      atk->do_damage(atk->return_limb(), dmg);
    }

    message("combat", COL+"As you finish your kick, you "+
      COLC+"spin"+COL+", "+COLC+"spring"+COL+" off the ground, "
      "and "+COL2+"cleave"+COL+" through your opponents "
      "with another circle kick!"+RES, tp);

    message("combat", COL+"As "+tp->query_cap_name()+" finishes "+
      tp->query_possessive()+" kick, "+tp->query_subjective()+" "+
      COLC+"spins"+COL+", "+COLC+"springs"+COL+" off the ground, "
      "and "+COL2+"cleaves"+COL+" through "+tp->query_possessive()+
      " opponents with another circle kick!"+RES, env, atkrs + ({ tp }) );

    message("combat", COL+tp->query_cap_name()+
      COLC+"spins"+COL+", "+COLC+"springs"+COL+" off the ground, "
      "and "+COL2+"cleaves"+COL+" through you with "
      "another circle kick!"+RES, atkrs);

  }

  return 1;
}

