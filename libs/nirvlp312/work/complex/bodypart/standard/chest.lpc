#include <bodypart.h>

inherit BODYPART;

void
configure()
{
  BODYPART::configure();

  set_type("chest");
  set_name("chest");
  add_id(({"chest","upper torso"}));
  add_position("upper");
  add_position("middle");
  add_bodypart_connectors(({BPC_WAIST,BPC_RIGHT_SHOULDER,BPC_LEFT_SHOULDER,
                            BPC_RIGHT_SHOULDERBLADE,BPC_LEFT_SHOULDERBLADE,
                            BPC_NECK}));
}
