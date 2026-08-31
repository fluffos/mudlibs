#include <std.h>
inherit OBJECT;

object owner;
int damage,rounds;

void heart_beat();
void setup(object tp, int dam, int rds);

void create() {
  set_id(({"diseaseob"}));
  set_mass(0);
}

void setup(object tp, int dam, int rds) {
  owner=tp;
  damage=dam;
  rounds=rds;
}

void heart_beat() {
  object env=environment();
  if (!living(env)) {
    remove();
    return;
  }
  if (env->query_hp() < damage+20) {
    env->set_paralyzed(3,"You are too weak to move.");
    message("magic","%^MAGENTA%^The pain overcomes you and you collapse.%^RESET%^",env);
    message("magic","%^MAGENTA%^"+env->query_cap_name()+" collapses.%^RESET%^",
      environment(env),env);
    remove();
    return;
  }
  if (!rounds) {
    message("magic","%^MAGENTA%^The unnatural disease begins to wear off.%^RESET%^",env);
    message("magic","%^MAGENTA%^"+env->query_cap_name()+" begins to look a little better.%^RESET%^",
      environment(env),env);
    remove();
    return;
  }
  message("magic","%^MAGENTA%^You bleed and convulse from the pain!%^RESET%^",env);
  message("magic","%^MAGENTA%^"+env->query_cap_name()+" bleeds and convulses!%^RESET%^",
    environment(env),env);
  env->add_hp(-(damage+random(15)));
  if (env->query_hp() < 1) env->set_hp(1);
  rounds--;

  call_out("heart_beat",2);
}

