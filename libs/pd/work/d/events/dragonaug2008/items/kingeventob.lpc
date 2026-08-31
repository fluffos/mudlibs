#include <std.h>
#include <dragonevent.h>

inherit OBJECT;

void create() {
  set_name("kingeventob");
  set_short("");
  set_long("");
  set_id( ({ "kingeventob" }) );
}

void notify_die() {
  if(environment(environment())->is_instanced()) {
    load_object(DRAG_ROOMS"instance_d")->destruct_instances_with_group_id(environment()->query_name());
  }
  this_object()->remove();
}
