#include <bodypart.h>

inherit BODYPART;

void configure() {
  object leg, foot;

  BODYPART::configure();
  set_type("foreleg");
  set_name("leg");
  add_id(({"leg"}));
  add_position("lower",1);
  add_position("front",1);
  add_bodypart_connectors(({ BPC_ANKLE, BPC_SHOULDER }));

  add_bodypart(foot = clone_object(BODYPART_DIR"cattle/forehoof"));
  connect_bodyparts(foot,this_object(),BPC_ANKLE);
}

