#include <bodypart.h>

inherit BODY;

void configure() {
  object torso, head, limb, tail;

  BODY::configure();

  set_race("cattle");
  set_name("cattle body");
  set_id(({"body","cattle body"}));

  add_bodypart(head = clone_object(BODYPART_DIR"cattle/head"));

  add_bodypart(torso = clone_object(BODYPART_DIR"cattle/torso"));
  connect_bodyparts(torso,head,BPC_FRONT,BPC_NECK);

  add_bodypart(limb = clone_object(BODYPART_DIR"cattle/forelimb"));
  limb->add_position("left",1);
  connect_bodyparts(limb,torso,BPC_SHOULDER);

  add_bodypart(limb = clone_object(BODYPART_DIR"cattle/forelimb"));
  limb->add_position("right",1);
  connect_bodyparts(limb,torso,BPC_SHOULDER);

  add_bodypart(limb = clone_object(BODYPART_DIR"cattle/hindlimb"));
  limb->add_position("left",1);
  connect_bodyparts(limb,torso,BPC_HIP);

  add_bodypart(limb = clone_object(BODYPART_DIR"cattle/hindlimb"));
  limb->add_position("right",1);
  connect_bodyparts(limb,torso,BPC_HIP);

  add_bodypart(tail = clone_object(BODYPART_DIR"cattle/tail"));
  connect_bodyparts(tail,torso,BPC_TAIL,BPC_BEHIND);
}

