
#include <std.h>

#define COL "%^BOLD%^%^WHITE%^"
#define RES "%^RESET%^"

inherit ARMOUR;
inherit OIL;

int beats;
int max_beats;
int mine;
object owner;

void setup(object tp, int max, int uses) {
  if (!tp || !max) return;
  owner = tp;
  max_beats = max;
  set_uses(uses);
  if (!alignment_ok(owner))
    mine=1;
}

void init() {
  armour::init();
  oil::init();
}
  
void create() {
  oil::create();
  armour::create();
  set_id( ({"healthward_amulet", "amulet", "glowing amulet",
            "white amulet", "glowing white amulet"}) );
  set_name("amulet");
  set_short("a glowing white amulet");
  set_long("This amulet is covered in a simple yet inspiring design "
           "of etched lines and whorls. A warmth emanates from it which "
           "makes you want to <grasp amulet>.");
  set_weight(3);
  set_curr_value("gold", 0);
  set_ac(1);
  set_type("necklace");
  set_limbs( ({"head"}) );
  set_action("grasp");
  set_your_mess(COL+"You grasp the amulet gently."+RES);
  set_their_mess(COL+"", " grasps ", " amulet."+RES);
  set_heal_mess(COL+"A warmth flows through you."+RES);
  set_uses(5);
  set_heart_beat(1);
  beats=0;
  max_beats=10;
  mine=0;
  set_property("magic item", ({"wear", "grasp"}) );
  set_property("no auction",1);
  set("dragon wear", 1);
}

string query_short() {
  return "a glowing white amulet"+(query_worn()?" (worn)":"");
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
  else if (this_object()->query_worn() == env) {
    if (random(1000) < 400)
      env->heal(7+random(4));
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

