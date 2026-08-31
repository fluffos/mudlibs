#include <std.h>

inherit ARMOUR;

void create() {
  ::create();
  set_name("kinky leather outfit");
  set_short("%^BOLD%^%^BLACK%^kinky leather outfit%^RESET%^");
  set_long("%^BOLD%^%^BLACK%^This slick leather outfit wraps tightly around your middle and under your arms.  The top plunges down the middle, leaving little to the imagination.  Accompanied by a miniskirt with a high slit on each side, this outfit is not for the feint of heart.%^RESET%^");
  set_type("leggings");
  set_limbs(({ "torso" }));
  set_ac(1);
  set_id( ({ "outfit", "leather outfit", "kinky leather outfit", "kinky outfit" }) );
  set_weight(1);
}

int query_auto_load() { if(this_player()->query_name() == "azire") return 1; }
