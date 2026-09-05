#include <bodypart.h>

inherit BODYPART;

void configure() {
  object upper_torso, lower_torso;

  BODYPART::configure();

  set_type("torso");
  set_name("torso");
  add_id(({"torso"}));
  add_position("middle");
  add_position("upper");
  add_bodypart_connectors(({ BPC_FRONT, BPC_SHOULDER, BPC_REAR_HIP,
                             BPC_BEHIND}));

  add_bodypart(upper_torso = clone_object(BPS_FRONT));
  add_bodypart(lower_torso = clone_object(BPS_REAR));
  connect_bodyparts(lower_torso, upper_torso, BPC_MIDDLE);
}

