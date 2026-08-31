
#include <std.h>

#define COL "%^YELLOW%^"
#define RES "%^RESET%^"

inherit ARMOUR;

int beats;
int max_beats;
object owner;

int ward_on();
int ward_off();
string stop_death_hook(string killer);

void setup(object tp, int max) {
  if (!tp || !max) return;
  owner = tp;
  max_beats = max;
}

void create() {
  ::create();
  set_id( ({"soulward_amulet", "amulet", "glowing amulet",
            "citrine amulet", "glowing citrine amulet"}) );
  set_name("amulet");
  set_short("a glowing citrine amulet");
  set_long("A small oval amulet with a yellow citrine stone in the center. "
           "It radiates peace and calm.");
  set_weight(3);
  set_curr_value("gold", 0);
  set_ac(1);
  set_type("necklace");
  set_limbs( ({"head"}) );
  set_property("magic item", ({"wear"}) );
  set_property("no auction", 1);
  set_wear( (: ward_on :) );
  set_remove( (: ward_off :) );
  set("dragon wear", 1);
  beats = 0;
  max_beats = 10;
}

int ward_on() {
  //environment()->add_hook("die", (: this_object(), "stop_death_hook" :) );
  return 1;
}

int ward_off() {
  //environment()->remove_hook("die", (: this_object(), "stop_death_hook" :) );
  return 1;
}

void heart_beat() {
  object env;
  if (!this_object()) return;
  env=environment();
  if (!env || !living(env))
    return;

  if (++beats >= max_beats) {
    message("magic", COL+"Your amulet glows brightly and melts away."+RES, env);
    remove();
    return;
  }
  return;
}

string stop_death_hook(string killer) {
  object env=environment(this_object());
  message("magic", COL+"The amulet burns brightly and suddenly "
                   "you feel very safe."+RES, env);
  message("magic", COL+"Light and warmth envelop "+env->query_cap_name()+
                   "!"+RES, environment(env), env);
  env->set_hp(env->query_max_hp());
  this_object()->remove();
  return 0;
}
