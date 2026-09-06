// This reaction has been updated by Allaryin (May 21, 2003)
// Added speed practice by Zarylse (Jan 30, 2004)

#include <battle.h>

int query_readiness_requirement() {
  return 500;
}

int query_readiness_cost() {
  return 50;
}

mixed on_attack( object actor, object weapon, mapping wc, object target,
                 int speed, int flag ) {
  string buf, name;
  int value, amt_avoided;

  if (flag & ATT_NO_DODGE)
    return;

  target->add_readiness(-query_readiness_cost());
  this_player()->add_endurance(-1);

  amt_avoided = target->skill_check("combat.dodge", speed * 5, speed * 10, speed * 20);
  amt_avoided *= 3;

  // practices speed, regardless of whether the dodge itself succeeds
  target->practice_stat("spd");

  if ( amt_avoided ) {
    foreach (name, value : wc) {
      if (amt_avoided <= 0)
        break;
      if (value >= amt_avoided)
        wc[name] -= amt_avoided;
      else if (value)
        wc[name] = 0;
      amt_avoided -= value;
    }
    if (amt_avoided > 0)
      buf = "~Subt easily ~vertsidestep ~poss attack!";
    else
      buf = "~Subt ~vertstumble as ~npos attack grazes ~objt.";
  } else
    buf = "~Subt ~vertstagger as ~prot ~vertfail to dodge!";
  return ({"dodge",
           wc,
           buf});
}
