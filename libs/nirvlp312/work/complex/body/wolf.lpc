#include <bodypart.h>

inherit BODY;

void configure() {
  object torso, head, limb;

  BODY::configure();

  set_race("wolf");
  set_name("wolf body");
  set_id(({"body","wolf body"}));

  add_bodypart(head = clone_object(BP_HORSE_HEAD));

  add_bodypart(torso = clone_object(BP_HORSE_TORSO));
  connect_bodyparts(torso,head,BPC_FRONT,BPC_NECK);

  add_bodypart(limb = clone_object(BP_HORSE_FORELIMB));
  limb->add_position("left",1);
  connect_bodyparts(limb,torso,BPC_SHOULDER);

  add_bodypart(limb = clone_object(BP_HORSE_FORELIMB));
  limb->add_position("right",1);
  connect_bodyparts(limb,torso,BPC_SHOULDER);

  add_bodypart(limb = clone_object(BP_HORSE_HINDLIMB));
  limb->add_position("left",1);
  connect_bodyparts(limb,torso,BPC_HIP);

  add_bodypart(limb = clone_object(BP_HORSE_HINDLIMB));
  limb->add_position("right",1);
  connect_bodyparts(limb,torso,BPC_HIP);

  add_bodypart(limb = clone_object(BP_HORSE_TAIL));
  connect_bodyparts(limb,torso,BPC_TAIL,BPC_BEHIND);
}
