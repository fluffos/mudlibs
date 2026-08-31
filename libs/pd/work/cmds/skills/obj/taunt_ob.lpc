#include <std.h>

inherit OBJECT;

object owner;
int rounds;

void set_owner(object tp);

void init() {
  ::init();
  set_heart_beat(1);
}

void set_owner(object tp) {
  owner=tp;
}
void set_rounds(int r) {
  rounds = r;
}

void heart_beat() {
  object tgt = environment();

  if (!this_object()) return;

  if (!tgt || !tgt->is_living()) {
    remove();
    return;
  }

  if (!rounds || !owner || !present(owner, environment(tgt)) ) { 
    message("info", "You calm down and feel less annoyed.", tgt);
    remove();
    return;
  }

  if (random(250) < owner->query_level())
    tgt->set_paralyzed(2, "The need to HURT "+
        owner->query_cap_name()+" consumes you.","");

  if (random(2))
    tgt->kill_ob(owner);

  rounds--;
}

