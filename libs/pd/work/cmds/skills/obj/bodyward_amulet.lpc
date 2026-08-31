
#include <std.h>

#define COL "%^CYAN%^"
#define RES "%^RESET%^"

inherit ARMOUR;

int mine;
int beats;
int max_beats;
int ac;
object owner;

int ward_on();
int ward_off();

void setup(object tp, int max, int prot) {
  if (!tp || !max) return;
  owner = tp;
  max_beats = max;
  ac = prot;
  if (!alignment_ok(owner))
    mine=1;
}

void create() {
  ::create();
  set_id( ({"bodyward_amulet", "amulet", "glowing amulet",
            "turquoise amulet", "glowing turquoise amulet"}) );
  set_name("amulet");
  set_short("a glowing turquoise amulet");
  set_long("This amulet is made of a solid bluish stone in a teardrop shape. "
           "A feeling of safety emanates from it.");
  set_weight(3);
  set_curr_value("gold", 0);
  set_ac(0);
  set_type("necklace");
  set_limbs( ({"head"}) );
  set_property("magic item", ({"wear"}) );
  set_property("no auction", 1);
  set_wear( (: ward_on :) );
  set_remove( (: ward_off :) );
  set("dragon wear", 1);
  ac = 1;
  beats = 0;
  max_beats = 10;
  mine = 0;
  set_heart_beat(1);
}

int ward_on() {
  environment()->add_magic_protection( ({0, ac, 0}) );
  return 1;
}

int ward_off() {
  environment()->add_magic_protection( ({0, -ac, 0}) );
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

int drop() {
  if (!mine) return 0;
  message("info", "Why would you give that away?", environment() );
  return 1;
}

int give() {
  if (!mine) return 0;
  message("info", "Why would you give that away?", environment() );
  return 1;
}

int put() {
  if (!mine) return 0;
  return 1;
}

int bury() {
  if (!mine) return 0;
  message("info", "Why would you give that away?", environment() );
  return 1;
}

int store() {
  if (!mine) return 0;
  message("info", "Why would you give that away?", environment() );
  return 1;
}

