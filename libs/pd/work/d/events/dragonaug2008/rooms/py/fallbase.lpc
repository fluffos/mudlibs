#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"py/base";

object player;
int beats;

void create() {
  ::create();
  skip_obvious();
  set_property("no map", 1);
  remove_property("indoors");
  set_heart_beat(1);
}

void set_real_long(string str) { return ::set_long(str); }
void set_long(string str) {
  ::set_long("You are falling through the air.\n"+str);
}

int accept_player_into_instance(object play) {
  return 1;
}

void init() {
  ::init();
  if(!player && this_player() && this_player()->is_player()) {
    player = this_player();
    beats = 0;
    this_object()->new_player(this_player());
    set_heart_beat(1);
  }

  add_action("prevent_fly", ({"fly", "glide", "flap"}) );
}

int prevent_fly(string str) {
  write("A magical force removes the air from beneath you, making flying impossible.");
  return 1;
}

int beats() { return beats; }
object player() { return player; }

void heart_beat() {
  if(!player || !present(player)) {
    player = 0;
    set_heart_beat(0);
    return;
  }

  beats++;
}
