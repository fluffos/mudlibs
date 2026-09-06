#include <drink.h>
#include <conditions.h>

void
create_drink()
{
  set_name("potion of detect magic");
  set_short("Potion of Detect Magic");
  set_long("This bottle is labeled \"Potion of Detect Magic\".");
  set_id(({"potion", "detect magic", "magic" }));
  set_empty_container("bottle");
  set_drinker_mess("Glug-glug-glug...");
  set_strength(4);
  set_soft(1);
  set_value(50);
  full = 1;
  set_weight(1);
  set_size(({ 10, 20, 10 }));
  set_liquid("dark green liquid");
}

void
extra_drink()
{
  this_player()->tell_me("You feel perceptive.");
  this_player()->set_condition(C_DETECT_MAGIC, 150 + random(251));
}
