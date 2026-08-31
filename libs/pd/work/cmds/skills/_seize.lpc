
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL RES+"%^BLUE%^"
#define COL2 "%^BOLD%^%^BLUE%^"

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "thief" &&
      tp->query_skill("stealing") >= 50*6 &&
      tp->query_skill("agility") >= 50*5 &&
      tp->query_skill("attack") >= 50*4 &&
      tp->query_skill("murder") >= 50*3)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <seize [weapon] from [whom]>\n\n"
    "The quickest of thieves can take your weapon right out of "
    "your hand and attack you with it in one smooth motion. "
    "A bit of fighting skill is required, and knowing how to "
    "use the weapon can increase the effectiveness.\n"
    "Unfortunately for the victims of this attack, there isn't "
    "much time to report it to the authorities, since they "
    "need to focus on fighting off an attacker!",
    this_player() );
}

int can_cast(object tp, object tgt, object wep, string wepname) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (environment(tp)->query_property("no steal"))
    FAIL("Some force prevents your mischief.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Shouldn't you worry about more pressing matters, like, oh, being DEAD??");

  if (!tgt)
    FAIL("Seize from whom?");

  if (!living(tgt))
    FAIL("That is not alive.");

  if (tgt == tp)
    FAIL("There are less stupid ways to off yourself.");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  if (tgt->query_property("no steal"))
    FAIL("You cannot steal from "+tgt->query_objective()+".");

  if (!wep)
      FAIL(capitalize(tgt->query_subjective())+
           (strlen(wepname) ? " does not have that!" :
           " does not have any weapons you can take!") );

  if (wep->query_property("no steal") || wep->drop())
    FAIL("You cannot steal "+
         indefinite_article(strip_color(wep->query_short()))+".");

  return 1;
}

int cmd_seize(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt, wep, tmp;
  object *allweps, *q;
  string *free;
  int steal, cost, dmg, rank, exp, hands, bonus, dtype;
  string wepname, tgtname, weptype, verb, youverb;
  
  if (!abil()) return 0;

  if (str) {
    if (sscanf(str, "%s from %s", wepname, tgtname) == 2 ||
        sscanf(str, "from %s", tgtname) == 1)
          tgt = present(tgtname, env);
    else
      wepname = str;
  }

  if (!tgt)
    tgt = tp->query_current_attacker();
  if (tgt) {
    q = filter(all_inventory(tgt),
      (: ($1->is_quiver() && $1->query_arrows()) :) );
    if (!sizeof(q))
      q = filter(all_inventory(tp),
        (: ($1->is_quiver() && $1->query_arrows()) :) );
    if (wepname)
      wep = present(wepname, tgt);
    else {
      allweps = tgt->query_wielded();
      // not wielding anything?? take whatever we can get...
      if (!sizeof(allweps))
        allweps = filter(all_inventory(tgt), (: $1->is_weapon() :) );
      // if there are no arrows anywhere, don't steal ranged weapons
      // note that we just steal an arrow from the target if possible
      allweps = filter(allweps, (:
        (!$1->query_property("no steal") &&
        (!$2 ? $1->query_type() != "ranged" : 1) )
      :), sizeof(q) );
      if (sizeof(allweps))
        wep = allweps[random(sizeof(allweps))];
    }
  }

  if (!can_cast(tp, tgt, wep, wepname)) return 0;

  rank = 4;

  steal = BALANCE3_D->get_steal(tp, tgt, rank,
    ({ "stealing", "stealing", "agility", "attack" }),
    ({ "dexterity", "dexterity", "charisma", "intelligence" }) );
  steal /= 4;

  message("info", "You "+COL+"leap"+RES+" at "+tgt->query_cap_name()+
    " and try to "+COL+"grab "+tgt->query_possessive()+RES+" "+
    wep->query_name()+"!", tp);
  message("info", tp->query_cap_name()+" "+COL+"leaps"+RES+" towards you!", tgt);
  message("info", tp->query_cap_name()+" "+COL+"leaps"+RES+" towards "+
    tgt->query_cap_name()+"!", env, ({ tp, tgt }) );

  tp->add_skill_points("agility", 35);
  tp->kill_ob(tgt);

  if (steal < 1) {
    message("info", capitalize(tp->query_subjective())+
      " sees your attempt and avoids you!", tp);
    message("info", "You avoid "+tp->query_cap_name()+"'s assault!", tgt);
    tp->add_stolen(tgt, 1);
    exp = tp->query_steal_exp(tp, tgt)/6;
  }
  else {
    weptype = wep->query_type();
    wepname = definite_article(strip_color(
        replace_string(wep->query_short(), " (wielded)", "")
    ));
    message("info", "You "+COL2+"swiftly slip"+RES+" "+wepname+
      " from "+tgt->query_possessive()+" grasp!", tp);
    wep->set_theft(1);
    wep->unequip();
    wep->set_theft(0);
    wep->move(tp);

    tp->add_stolen(tgt, 2);
    tp->add_skill_points("stealing", 50);
    exp = tp->query_steal_exp(tp, tgt)/4;

    if (tp->query_skill(weptype) >= wep->query("skill level")) {
      bonus = wep->query_wc()*(7+random(6));
      /* too much to mess with
      free = tp->query_limbs_wielded() - tp->query_wielding_limbs();
      hands = wep->query_hands();
      if (sizeof(free) < hands) {
        // reusing allweps here
        allweps = filter(tp->query_wielded(),
          (: $1->query_hands() >= $2 :), hands );
        // not sure how this could ever happen
        if (!sizeof(allweps))
          FAIL("An error occurred, please contact a staff member.");
        else {
          tmp = allweps[random(sizeof(allweps))];
          tmp->unequip();
          tp->force_me("wield "+wep->query_id()[0]);
        }
      }
      */
    }

    if (tp->query_skill("attack") < 55*4) rank--;

    dmg = BALANCE3_D->get_damage(tp, tgt, rank,
      ({ "agility", "agility", "agility", "attack", weptype }),
      ({ "dexterity", "dexterity", "dexterity", "strength" }),
      ({ "dexterity", "strength" }) );

    /*
    cost = 40 + dmg/15;
    */
    cost = BALANCE3_D->get_cost(dmg, rank, "sp") * 70 / 100 + 40;

    dmg += bonus;

    switch (weptype) {
      case "axe": verb = "hack"; break;
      case "blade": verb = "slash"; break;
      case "blunt": verb = "smash"; break;
      case "flail": verb = "lash"; break;
      case "knife": verb = "stab"; break;
      case "projectile": verb = "slice"; break;
      case "ranged": verb = "shoot"; q[0]->use_arrow(); break;
      default: verb = "strike";
    }

    message("combat", "You "+COL+"spin in the air"+RES+" and "+COL2+verb+RES+
      " "+tgt->query_objective()+" with "+wepname+"!", tp);
    message("combat", tp->query_cap_name()+" "+COL+"spins in the air"+RES+
      " and "+COL2+pluralize(verb)+RES+" you "
      "with "+indefinite_article(wepname)+"!", tgt);
    message("combat", tp->query_cap_name()+" "+COL+"spins in the air"+RES+
      " and "+COL2+pluralize(verb)+RES+" "+tgt->query_cap_name()+
      " with "+indefinite_article(wepname)+"!", env, ({ tp, tgt }) );

    tgt->do_damage("target", dmg, DAMAGE_PHYSICAL | (wep->query_damage_type()), 0 | (wep->query_damage_flags()), tp);
  }

  tp->set_disable(1);
  tp->add_sp(-(cost+random(10)));
  tp->add_exp(exp);

  return 1;
}

