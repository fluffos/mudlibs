#include <bodypart.h>

inherit BODYPART;

void
configure()
{
  object leg, foot;

  BODYPART::configure();

  set_type("forelimb");
  set_name("limb");
  add_id(({"limb"}));
  add_position("lower",1);
  add_position("front",1);
  add_bodypart_connectors(({BPC_SHOULDER}));

  add_bodypart(leg = clone_object(BP_HORSE_FORELEG));
  add_bodypart(foot = clone_object(BP_HORSE_FOREHOOF));
  connect_bodyparts(foot,leg,BPC_ANKLE);
}
