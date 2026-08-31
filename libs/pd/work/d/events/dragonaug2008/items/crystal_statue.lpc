
#include <std.h>
#include <daemons.h>
#include <dragonevent.h>

inherit OBJECT;

void create() {
  ::create();
  set_name("crystal dragon");
  set_property("no store", 1);
  set_property("no auction", 1);
  set_property("magic item", ({ "soul" }) );
  set_id( ({
    "crystal", "statuette", "statue", "dragon", "crystal dragon",
    "crystal statuette", "crystal dragon statuette",
  }) );
  set_short("a crystal dragon statuette");
  set_long(
    "This is a small statuette made of clear crystal. It depicts a "
    "dragon standing with its head, wings, and tail spread up into "
    "the air, and one claw raised off the ground. Every scale is "
    "discernable in this incredible work of art; even the eyes seem "
    "to have a certain depth to them."
  );
  set_item( ({ "head", "eyes" }), "Deep pinpoints of rainbow light "
    "seem to stare back at you from the crystal dragon's eyes.");
  set_touch("default", "The intricately carved crystal scales feel bumpy "
    "but smooth under your fingers.");
  set_weight(4);
  set_curr_value("gold", 10000);
  set_heart_beat(10);
}

void heart_beat() {
  object env = environment();
  int ran;
  if (!this_object() || !env || !env->is_player()) return;

  if (env->query_heal_rate_bonus("all") == 0) {
    ran = 2+random(9);
    env->add_heal_rate_bonus("all", ran);      
    DELAY_D->add_delay(20, env, "add_heal_rate_bonus", -ran, 0);
  }
}

int get() {
  if (DRAG_D->query_data("prisonbeams") > 0 &&
      DRAG_D->query_data("canloadcrystaldragon") == 1) {
        message("magic", "%^YELLOW%^The statuette is held fast "
          "by a beam of light from the next room.%^RESET%^", this_player());
        return 0;
  }
  return 1;
}

int query_autoload() { return 1; }

//added by pyro
int query_auto_load() { return 1; }
