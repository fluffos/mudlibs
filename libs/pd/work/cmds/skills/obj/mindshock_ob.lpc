
#include <std.h>

#define MYID "mindshock_ob"

inherit OBJECT;

object owner;
object target;
int rounds;

void setup(object tp, object tgt, int time) {
  if (!tp || !time) return;
  owner=tp;
  rounds=time;
  target=tgt;
  set_heart_beat(1);
}

int catch_all(string str) {
  if (this_player() != target) return 0;
  message("info", "Your mind has been shocked.", this_player());
  return 1;
}

void init() {
  ::init();
  add_action("catch_all", "");
}

void create() {
  ::create();
  set_name(MYID);
  set_id( ({MYID}) );
  set_weight(0);
}

void heart_beat() {
  if (!this_object()) return;
  if (!target || environment() != target ||
      !owner || rounds-- < 1)
        remove();
}
