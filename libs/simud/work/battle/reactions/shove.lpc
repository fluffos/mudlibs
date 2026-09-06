// This reaction has been updated by Allaryin (May 21, 2003)

#include <battle.h>

int query_readiness_requirement() {
  return 500;
}

int query_readiness_cost() {
  return 100;
}

mixed on_attack( object actor, object weapon, mapping wc, object target,
                 int speed, int flag ) {
  int check;

  if (flag & ATT_NO_COUNTER)
    return;

  target->add_endurance(-1);
  target->add_readiness(-query_readiness_cost());

  check = target->skill_check("combat.technique.counter", speed, speed * 15, speed * 30);

  if (check) {
    check += target->skill_check("combat.weapon.unarmed", speed * 10, speed * 20);
    actor->set_stance( ST_LYING );
    return ({"counter",
             (["blunt":target->query_str_wc() + check]),
             "~Targ ~vertshove ~name backwards!"});
  } else
    return ({"counter",
             (["blunt":0]),
             "~Targ ~vertshove ~name, but ~pron ~vertdon't budge!"});
}
