#include <std.h>
inherit OBJECT;

object owner;
int damage,rounds;

void heart_beat();
void setup(object tp, int dam, int rds);

void create() {
  set_id(({"drownob"}));
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
  if (!rounds || !present(owner,environment(env)) || owner->query_mp() < damage/2) {
    message("magic","%^CYAN%^The water around you dissipates.%^RESET%^",env);
    message("magic","%^CYAN%^The water around "+env->query_cap_name()+" dissipates.%^RESET%^",
      environment(env),env);
    remove();
    return;
  }
  message("magic","%^BOLD%^%^CYAN%^You gasp for breath as the water fills your lungs!%^RESET%^",env);
  message("magic","%^BOLD%^%^CYAN%^"+env->query_cap_name()+" gasps for breath as the water "
    "fills "+env->query_possessive()+" lungs!%^RESET%^",environment(env),env);
  owner->add_mp(-(damage/5+random(20)));
  env->add_hp(-damage);
  if (env->query_skill("attack") > env->query_base_skill("attack")/3)
    env->add_skill_bonus("attack",-damage/3,rounds*2);
  damage+=damage/6;
  rounds--;

  call_out("heart_beat",2);
}

