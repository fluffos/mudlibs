#include <combat.h>
#include <action.h>
#include <event.h>

inherit BODYPART;

void
configure()
{
  BODYPART::configure();

  set_type("lower limb");
  set_name("limb");
  add_id(({"limb"}));
  add_position("lower",1);
  add_bodypart_connectors(({BPC_HIP}));
}

void
set_race(string r)
{
  object leg, foot;

  if (query_race())
    return;

  BODYPART::set_race(r);

  add_bodypart(leg = clone_object(BP_LEG(""+r+"")));
  add_bodypart(foot = clone_object(BP_FOOT(""+r+"")));
  connect_bodyparts(foot,leg,BPC_ANKLE);
}

status query_unreachable(object by) {
  // we can't be reached by our own bodyparts
  if (BODYPART::query_unreachable(by))
    return 1;
  if (member(get_bodyparts(),by) >= 0)
    return 1;
}
