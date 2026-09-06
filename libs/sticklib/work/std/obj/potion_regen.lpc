#include <drink.h>
#include <stats.h>

void
create_drink()
{
  set_name("potion of regeneration");
  set_short("Potion of Regeneration");
  set_long("This bottle is labeled \"Potion of regeneration\".");
  set_id(({"potion", "regeneration"}));
  set_empty_container("bottle");
  set_drinker_mess("Glug-glug-glug...");
  set_value(400);
  set_strength(6);
  set_soft(1);
  full = 1;
  set_weight(1);
  set_size(({ 10, 20, 10 }));
  set_liquid("green liquid");
}

void
extra_drink()
{
    // Max 10 minutes (in heartbeats), minimum 7.5 mins
    int duration = (10 * 60 / 2);
    duration -= random(duration/4);
    this_player()->add_stat(ST_HP_HEAL_RATE, 30, duration);
    this_player()->add_stat(ST_SP_HEAL_RATE, 30, duration);
    this_player()->add_stat(ST_FP_HEAL_RATE, 30, duration);
    this_player()->tell_me("You feel like you will heal faster!");
}
