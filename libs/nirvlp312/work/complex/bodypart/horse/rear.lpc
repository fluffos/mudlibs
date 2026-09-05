#include <bodypart.h>

inherit BODYPART;

void
configure()
{
  BODYPART::configure();

  set_type("rear");
  set_name("rear");
  add_id(({"rear","rear torso"}));
  add_position("rear");
  add_position("middle");
  add_position("upper");
  add_bodypart_connectors(({BPC_REAR_HIP,BPC_BEHIND,BPC_MIDDLE}));
}
