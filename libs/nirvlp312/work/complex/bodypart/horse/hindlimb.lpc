#include <bodypart.h>

inherit BODYPART;

void
configure()
{
  object leg, foot;

  BODYPART::configure();

  set_type("hindlimb");
  set_name("limb");
  add_id(({"limb"}));
  add_position("rear",1);
  add_position("lower",1);
  add_bodypart_connectors(({BPC_SHOULDER}));

  add_bodypart(leg = clone_object(BP_HORSE_HINDLEG));
  add_bodypart(foot = clone_object(BP_HORSE_HINDHOOF));
  connect_bodyparts(foot,leg,BPC_ANKLE);
}
