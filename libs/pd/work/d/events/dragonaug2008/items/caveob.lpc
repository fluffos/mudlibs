#include <std.h>
#include <dragonevent.h>

inherit OBJECT;

void check_stone();
int escape_cave_of_courage(string);

void create() {
  ::create();
  set_name("stone");
  set_id( ({ "shining stone", "stone" }) );
  set_short("a %^BOLD%^shining%^RESET%^ stone");
  set_long("A grey stone that eminates a soft white light. After releasing its power on the wall in the room with the icicles, you can use it to <escape> the cave of courage. Your progress will be tracked. Usefull should you feel your life is in immediate peril.");
  set("no store", 1);
  set_property("no steal", 1);
  set_property("no auction", 1);
}

void init() {
  ::init();
  //used because removing this_object() in init() causes errors
  call_out("check_stone", 1);
  add_action("escape_cave_of_courage", "escape");
}

void check_stone() {
  object env;
  if(!this_player() || !(env = environment(this_player())))
    return;
  if(env->is_instance()
      && env->query_instance_group_id()=="Event Test Of Courage Instance")
    return;
  message("info", "The bright stone blinks out of existance.", environment());
  this_object()->remove();
}

int escape_cave_of_courage(string str) {
  check_stone();
  if(!this_object()) return 1;
  message("info", "You melt into the shadows and appear elsewhere.", this_player());
  message("info", this_player()->query_cap_name()+" melts into the shadows.",
     environment(this_player()), this_player());
  this_player()->move(DRAG_ROOMS"py/entrance");
  message("info", this_player()->query_cap_name()+" appears from the shadows.",
    environment(this_player()), this_player());
  check_stone();
  return 1;
}

int drop() { return 1; }
int give() { return 1; }

void notify_die() {
  if(environment(environment())->query_instance_group_id() == "Event Test Of Courage Instance") {
    environment()->move(DRAG_ROOMS"py/entrance");
  }
  check_stone();
}
