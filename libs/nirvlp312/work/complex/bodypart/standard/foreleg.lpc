#include <bodypart.h>

inherit BODYPART;

void
configure()
{
  object leg, foot;

  BODYPART::configure();

  set_type("foreleg");
  set_name("leg");
  add_id(({"leg"}));
  add_position("front",1);
  add_position("lower");
  add_bodypart_connectors(({BPC_ANKLE,BPC_SHOULDER}));
}
