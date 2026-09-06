// This reaction has been updated by Allaryin (May 21, 2003)

#include <battle.h>

int query_readiness_requirement() {
  return 500;
}

int query_readiness_cost() {
  return 50;
}

void damage_weapons(object weapon, object shield, string wc_type, int wc_amt) {
  int adam = 3, ddam = 1;

  if (weapon->query_is_living()) return;

  switch (weapon->query_material()) {
    case "wood":
      ddam -= 2;
      break;
    case "copper":
    case "silver":
    case "gold":
      ddam -= 1;
      break;
    case "stone":
    case "steel":
      ddam += 1;
      break;
    case "diamond":
      ddam += 2;
      break;
  }

  switch (shield->query_material()) {
    case "wood":
      adam -= 2;
      if ( (wc_type == "edged" || wc_type == "piercing") && shield->query_material() != "wood")
        ddam++;
      break;
    case "copper":
    case "silver":
    case "gold":
      adam -= 1;
      break;
    case "stone":
    case "steel":
      adam += 1;
      break;
    case "diamond":
      adam += 2;
      break;
  }

  adam = (adam < 0 ? 0 : -adam * wc_amt / 3);
  ddam = (ddam < 0 ? 0 : -ddam * wc_amt / 3);

  debug("attacker's weapon takes "+adam+" damage");
  debug("defender's shield takes "+ddam+" damage");

  weapon->add_condition(adam);
  shield->add_condition(ddam);
}

mixed on_attack( object actor, object weapon, mapping wc, object target,
                 int speed, int flag ) {
  string buf, name, hname = "blunt";
  int value, amt_avoided;
  int wdam = 0, hamt = 0;
  object shield;

  if (flag & ATT_NO_BLOCK)
    return;

  foreach ( shield : all_inventory(this_player()) )
      if (shield->query_shield() && shield->query_held())
         break;
  if (!shield || !shield->query_shield() || !shield->query_held())
    return;

  // be nice with reactions and don't charge if they don't happen
  target->add_readiness(-query_readiness_cost());

  // need to clean the math up on this...
  amt_avoided = target->skill_check("combat.armour.shield", speed * 2, speed * 10, speed * 25);
  amt_avoided *= 3;

  if ( amt_avoided ) {
    foreach (name, value : wc) {
      if (amt_avoided <= 0)
        break;
      if (wc[name] > hamt) {
        hamt = wc[name];
        hname = name;
      }
      if (value >= amt_avoided + shield->query_ac(name)) {
        wdam += amt_avoided;
        wc[name] -= amt_avoided + shield->query_ac(name);
      } else if (value) {
        wdam += wc[name];
        wc[name] = 0;
      }
      amt_avoided -= value - shield->query_ac(name);
    }

    damage_weapons(weapon, shield, hname, wdam);

    if (amt_avoided > 5)
      buf = "~Targ neatly ~vert ~npos attack with ~post shield!";
    else if (amt_avoided > 0)
      buf = "~Targ ~vertblock ~npos attack with ~post shield!";
    else
      buf = "~Targ barely ~vertmanage to block any of ~npos attack.";
  } else {
    debug("block failed","combat");
    buf = "~Targ ~vertstagger as ~prot ~vertfail to block!";
  }
  return ({"block",
           wc,
           buf});
}
