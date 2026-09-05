#include <bodypart.h>

inherit BODYPART;

void
configure()
{
  BODYPART::configure();

  set_type("torso");
  set_name("torso");
  add_id(({"torso"}));
  add_position("upper");
  add_position("middle");
  add_bodypart_connectors(({BPC_NECK,BPC_HIP,
                            BPC_RIGHT_SHOULDER, BPC_LEFT_SHOULDER,
                            BPC_RIGHT_SHOULDERBLADE,BPC_LEFT_SHOULDERBLADE}));
}

void
set_race(string r)
{
  object upper_torso, lower_torso;

  if (query_race())
    return;

  BODYPART::set_race(r);

  add_bodypart(upper_torso = clone_object(BP_CHEST(""+r+"")));
  add_bodypart(lower_torso = clone_object(BP_ABDOMEN(""+r+"")));
  connect_bodyparts(lower_torso,upper_torso,BPC_WAIST);
}
