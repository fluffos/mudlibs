#include <bodypart.h>

inherit BODYPART;

void
configure()
{
  BODYPART::configure();

  set_type("abdomen");
  set_name("abdomen");
  add_id(({"abdomen","lower torso"}));
  add_position("middle");
  add_position("lower");
  add_bodypart_connectors(({BPC_WAIST,BPC_BEHIND,BPC_HIP}));
}
