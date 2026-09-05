#include <bodypart.h>

inherit BODY;

void
configure()
{
  object torso, horse_torso, head, limb;

  BODY::configure();

  set_race("centaur");
  set_name("centaur body");
  set_id(({"body","centaur body"}));

  add_bodypart(head = clone_object(BP_HEAD("centaur")));

  add_bodypart(torso = clone_object(BP_TORSO("centaur")));
  connect_bodyparts(torso,head,BPC_NECK);

  add_bodypart(limb = clone_object(BP_UPPER_LIMB("centaur")));
  limb->add_position("right",1);
  connect_bodyparts(limb,torso,BPC_SHOULDER,BPC_RIGHT_SHOULDER);

  add_bodypart(limb = clone_object(BP_UPPER_LIMB("centaur")));
  limb->add_position("left",1);
  connect_bodyparts(limb,torso,BPC_SHOULDER,BPC_LEFT_SHOULDER);

  add_bodypart(horse_torso = clone_object(BP_HORSE_TORSO));
  connect_bodyparts(horse_torso,torso,BPC_FRONT,BPC_HIP);

  add_bodypart(limb = clone_object(BP_HORSE_FORELIMB));
  limb->add_position("left",1);
  connect_bodyparts(limb,horse_torso,BPC_SHOULDER);

  add_bodypart(limb = clone_object(BP_HORSE_FORELIMB));
  limb->add_position("right",1);
  connect_bodyparts(limb,horse_torso,BPC_SHOULDER);

  add_bodypart(limb = clone_object(BP_HORSE_HINDLIMB));
  limb->add_position("left",1);
  connect_bodyparts(limb,horse_torso,BPC_HIP);

  add_bodypart(limb = clone_object(BP_HORSE_HINDLIMB));
  limb->add_position("right",1);
  connect_bodyparts(limb,horse_torso,BPC_HIP);

  add_bodypart(limb = clone_object(BP_HORSE_TAIL));
  connect_bodyparts(limb,horse_torso,BPC_TAIL,BPC_BEHIND);
}
