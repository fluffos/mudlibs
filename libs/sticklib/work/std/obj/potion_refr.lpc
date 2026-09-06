#include <drink.h>
#include <stats.h>

void
create_drink()
{
  set_name("potion of refreshing");
  set_short("Potion of Refreshing");
  set_long("This bottle is labeled \"Potion of Refreshing\".");
  set_info("It's a Potion of Extra Refreshing!\n");
  set_id(({"potion", "refresh", "refreshing"}));
  set_empty_container("bottle");
  set_drinker_mess("Glug-glug-glug...");
  set_strength(8);
  set_soft(1);
  set_value(400);
  full = 1;
  set_weight(1);
  set_size(({ 10, 20, 10 }));
  set_liquid("brown liquid");
}

void
extra_drink()
{
  this_player()->tell_me("You feel much less tired.");
  this_player()->add_fp(80 + random(50));
}
