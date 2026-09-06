// This reaction has been updated by Allaryin (May 21, 2003)

#include <battle.h>

int query_readiness_requirement() {
  return 500;
}

int query_readiness_cost() {
  return 150;
}

mixed on_miss( object actor, object weapon, mapping wc, object target,
               int speed, int flag ) {
  int check;

  if (flag & ATT_NO_COUNTER)
    return;

  target->add_endurance(-1);
  target->add_readiness(-query_readiness_cost());
  target->set_stance( ST_LYING );

  check = target->skill_check("combat.technique.counter", speed * 5);
  if( !check )
    return ({"counter",(["blunt":0]),"~Targ ~vertfail ~post attempt at throwing ~name."});

  actor->add_readiness(-50 - check * (2 +
    target->skill_check("combat.grappling", speed * 10, speed * 20, speed * 30)));

  // TODO: actually chuck the enemy a square or ten ;)

  // possible overkill on damage here...
  actor->set_stance( ST_LYING );
  return ({"counter",
           (["blunt":target->query_str_wc() + check / 5]),
           "~Targ ~vertgrab as ~pron ~verbmiss ~poss attack and ~vertthrow ~obje to the ground!"});
}
