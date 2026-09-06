// This reaction has been updated by Allaryin (May 21, 2003)

#include <battle.h>

int query_readiness_requirement() {
  return 500;
}

int query_readiness_cost() {
  return 500;
}

mixed on_attack( object actor, object weapon, mapping wc, object target,
                 int speed, int flag ) {
  int check, bonus, iwc;
  string verb;

  // argh, it's annoying, but actor and target are kind of switched for
  // counters, eh?

  if (flag & ATT_NO_COUNTER)
    return;

  target->add_readiness(-query_readiness_cost());
  target->add_endurance(-1);

  verb = random(2) ? "claw" : "bite";
  iwc = target->query_wc("edged");

  check = target->skill_check("combat.technique.counter",speed * 5, speed * 10, speed * 20);
  switch (check) {
    case 1:  return ({"counter",
                      (["edged":iwc]),
                      "~Targ barely ~vertcounter ~npos attack with a "+verb+"."});
             break;
    case 2:  return ({"counter",
                      (["edged":iwc + target->query_str_wc()]),
                      "~Targ ~vertcounter ~npos attack "+verb+"!"});
             break;
    case 3:  return ({"counter",
                      (["edged":iwc + target->query_str_wc() + 1]),
                      "~Targ deftly ~vertcounter ~npos attack with a "+verb+" of ~post own!"});
             break;
    default: return ({"counter",
                      (["edged":0]),
                      "~Targ "+verb+" at ~name, but misses!"});
  }
}
