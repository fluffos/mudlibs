#include <drink.h>
#include <stats.h>

void
create_drink()
{
  set_name("potion of healing");
  set_short("Potion of Healing");
  set_long("This bottle is labeled \"Potion of Healing\".");
  set_info("It's a Potion of Extra Healing!\n");
  set_id(({"potion", "healing potion", "healing"}));
  set_empty_container("bottle");
  set_drinker_mess("Glug-glug-glug...");
  set_strength(8);
  set_soft(1);
  set_value(600);
  full = 1;
  set_weight(1);
  set_size(({ 10, 20, 10 }));
  set_liquid("glowing liquid");
}

void
extra_drink()
{
  this_player()->tell_me("You feel great!");
  this_player()->add_hp(80 + random(50));
}
