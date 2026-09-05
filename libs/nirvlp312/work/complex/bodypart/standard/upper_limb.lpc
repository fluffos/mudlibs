#include <combat.h>

inherit BODYPART;

void
configure()
{
  BODYPART::configure();

  set_type("upper limb");
  set_name("limb");
  add_id(({"limb"}));
  add_position("upper",1);
  add_position("middle");
  add_bodypart_connectors(({BPC_SHOULDER}));
}

void
set_race(string r)
{
  object arm, hand;

  if (query_race())
    return;

  BODYPART::set_race(r);

  add_bodypart(arm = clone_object(BP_ARM(""+r+"")));
  add_bodypart(hand = clone_object(BP_HAND(""+r+"")));
  connect_bodyparts(hand,arm,BPC_WRIST);
}

status query_unreachable(object by) {
  if (BODYPART::query_unreachable(by))
    return 1;
  // we can't be reached by our own bodyparts
  if (member(get_bodyparts(),by) >= 0)
    return 1;
}
