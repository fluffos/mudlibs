#include <std.h>

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^GREEN%^"
#define COL2 RES+"%^MAGENTA%^"

inherit OBJECT;

object owner;
int damage,rounds;

void setup(object tp, int dam, int rds) {
  owner=tp;
  damage=dam;
  rounds=rds;
  set_heart_beat(1);
}

void heart_beat() {
  object env=environment();
  if (!env || !living(env)) {
    remove();
    return;
  }

  if (env->query_hp() < damage+20) {
    message("magic", COL+"Your body convulses in one last surge of pain."+RES,env);
    message("magic", COL+env->query_cap_name()+" convulses in a final spasm."+RES,
      environment(env),env);
    remove();
    return;
  }

  if (--rounds < 1) {
    message("magic",COL+"The unnatural disease begins to wear off."+RES,env);
    message("magic",COL+env->query_cap_name()+" begins to look a little better."+RES,
      environment(env),env);
    remove();
    return;
  }

  message("magic", COL+"You "+COL2+"bleed"+COL+" and "
                   "c"+COL2+"o"+COL+"nv"+COL2+"u"+COL+"ls"+COL2+"e"+COL+
                   " from the pain!"+RES,env);
  message("magic", COL+env->query_cap_name()+" "+COL2+"bleeds"+COL+" and c"+
                   COL2+"o"+COL+"nv"+COL2+"u"+COL+"ls"+COL2+"e"+COL+"s!"+RES,
    environment(env),env);

  env->add_hp(-(damage+random(15)));
  if (env->query_hp() < 1) env->set_hp(1);

}

