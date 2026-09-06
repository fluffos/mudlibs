#include <const.h>

int main(string who) {
  object victim;
  int x;

  WIZ_CHECK

  if (!who) {
    write ("Who do you want to revive?\n");
    return 1;
  }
  if( victim = present(who, environment(this_player())) ) {
    if( is_living(victim) ) {
       msg("You need to kill it first...");
       return 1;
    }
    victim->revive();
    victim->set_hp(victim->query_max_hp());
    victim->set_mana(victim->query_max_mana());
    victim->set_end(victim->query_max_endurance());
    victim->set_food(victim->query_food_capacity()*2);
    victim->set_drink(victim->query_drink_capacity()*2);
    set_target(victim);
    this_player()->msg_local("~CBRT~Name ~verbwave ~poss hands, and with a gesture and a flash, ~targ ~vertis restored to life!~CDEF");
  } else
    write ("Could not find "+capitalize(who)+".\n");
  return 1;
}
