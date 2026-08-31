#include <std.h>
inherit OBJECT;

object owner;
int rounds;

void set_owner(object tp);
void heart_beat();

void create() {
  ::create();
  set_id(({"tauntobj"}));
  set_mass(0);
}

void set_owner(object tp) {
  owner=tp;
  rounds=tp->query_level()*4/3;
}

void heart_beat() {
  if (!living(environment())) {
    remove();
    return;
  }
  if (!rounds || !present(owner,environment(environment()))) { 
    message("info","You feel less annoyed at "+owner->query_cap_name()+" now.",environment());
    remove();
    return;
  }
  if (!random(5))
    environment()->set_paralyzed(2, "The need to HURT "+owner->query_cap_name()+" consumes you...","");
  rounds--;
  call_out("heart_beat",2);
}

