#include <battle.h>

int query_readiness_requirement() {
  return 0;
}

int query_readiness_cost() {
  return 100;
}

mixed on_attack( object actor, object weapon, mapping wc, object target,
                 int speed, int flag ) {
  string buf;
  int wdam;

  // unbreakable weapons bypass hide
  if ( weapon && weapon->query_unbreakable() )
    return ({ "block", wc, 0 });

  // otherwise, blunt wc is reduced to zero, edged is reduced by half, and
  // piercing is reduced by one... and the weapon is damaged severely

  wdam = speed + wc["blunt"] + wc["edged"] + wc["piercing"] / 2;
  if (weapon)
     weapon->add_condition(-wdam);

  wc -= (["blunt"]);
  wc -= (["fire"]);
  if (wc["edged"])
    wc["edged"] /= 2;
  if (wc["piercing"])
    wc["piercing"]--;

  buf = "~Post thick hide absorbs most of the damage.";
  return ({"block", wc, buf});
}
