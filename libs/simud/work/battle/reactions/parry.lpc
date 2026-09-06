// This reaction has been updated by Allaryin (May 21, 2003)
// Added speed practice by Zarylse (Jan 30, 2004)

#include <battle.h>

int query_readiness_requirement() {
  return 500;
}

int query_readiness_cost() {
  return 150;
}

void damage_weapons(object aw, object dw, string wc_type, int wc_amt) {
  int adam = 3, ddam = 3;

  if (aw->query_is_living()) {
    debug("attacker is unarmed, not damaging weapons.","combat");
    return;
  }

  switch (aw->query_material()) {
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

  switch (dw->query_material()) {
    case "wood":
      adam -= 2;
      if (wc_type == "edged" && dw->query_material() != "wood")
        ddam++;
      break;
    case "copper":
    case "silver":
    case "gold":
      adam -= 1;
      break;
    case "stone":
    case "steel":
      if (wc_type == "edged" && dw->query_material() != "diamond")
        ddam++;
      adam += 1;
      break;
    case "diamond":
      if (wc_type == "edged" && dw->query_material() != "diamond")
        ddam++;
      adam += 2;
      break;
  }

  if (wc_type == "piercing") {
    adam -= 2;
    ddam -= 2;
  }

  adam = (adam < 0 ? 0 : -adam * wc_amt);
  ddam = (ddam < 0 ? 0 : -ddam * wc_amt);

  debug("attacker's weapon takes "+adam+" damage","combat");
  debug("defender's weapon takes "+ddam+" damage","combat");

  aw->add_condition(adam);
  dw->add_condition(ddam);
}

mixed on_attack( object actor, object weapon, mapping wc, object target,
                 int speed, int flag ) {
  string buf, name, hname = "blunt";
  int value, amt_avoided;
  int wdam = 0, hamt = 0;
  object dweapon, *weapons;

  target->add_readiness(-query_readiness_cost());
  if (flag & ATT_NO_PARRY)
    return;

  weapons = BATTLE_DAEMON->query_wielded_weapons(target);
  if (!weapons)
    return;
  dweapon = weapons[random(sizeof(weapons))];

  amt_avoided = target->skill_check("combat.technique.parry", speed * 3, speed * 12, speed * 20);
  amt_avoided *= 2;

  // practices speed, regardless of whether the parry itself succeeds
  target->practice_stat("spd");

  if ( amt_avoided ) {
    debug("attempting to parry...","combat");
    foreach (name, value : wc) {
      if (amt_avoided <= 0)
        break;
      if (wc[name] > hamt) {
        hamt = wc[name];
        hname = name;
      }
      if (value >= amt_avoided) {
        wdam += amt_avoided;
        wc[name] -= amt_avoided;
      } else if (value) {
        wdam += wc[name];
        wc[name] = 0;
      }
      amt_avoided -= value;
    }

    damage_weapons(weapon, dweapon, hname, wdam);

    if (amt_avoided > 5)
      buf = "~Targ neatly ~vertparry ~npos attack with ~post "+dweapon->query_name()+"!";
    else if (amt_avoided > 0)
      buf = "~Targ ~vertparry ~npos attack with ~post "+dweapon->query_name()+"!";
    else
      buf = "~Targ barely ~vertmanage to parry any of ~npos attack.";
  } else {
    debug("parry failed","combat");
    buf = "~Targ ~vertstagger as ~prot ~vertfail to parry!";
  }
  return ({"dodge",
           wc,
           buf});
}
