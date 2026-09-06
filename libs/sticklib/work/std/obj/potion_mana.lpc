#include <drink.h>
#include <stats.h>

void
create_drink()
{
  set_name("potion of mana");
  set_short("Potion of Mana");
  set_long("This bottle is labeled \"Potion of mana\".");
  set_id(({"potion", "mana"}));
  set_empty_container("bottle");
  set_drinker_mess("Glug-glug-glug...");
  set_value(600);
  set_strength(8);
  set_soft(1);
  full = 1;
  set_weight(1);
  set_size(({ 10, 20, 10 }));
  set_liquid("green liquid");
}

void
extra_drink()
{
  this_player()->tell_me("You have a tingling feeling.");
  this_player()->add_sp(80 + random(50));
}
